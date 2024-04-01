//
// Created by symc on 4/1/24.
//

#ifndef OPENGL_LEARN_SHADER_H
#define OPENGL_LEARN_SHADER_H

#include "glad/glad.h"

#include "string"
#include "fstream"
#include "sstream"
#include "iostream"

class Shader{
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setBool(const std::string &name, bool value) const;
    void setInit(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setFloat3(const std::string &name, float value0,float value1,float value2) const;
private:
    void checkCompileError(unsigned int shader, std::string type);
};

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    //read shaders
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        vShaderFile.close();
        fShaderFile.close();

        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }catch (std::ifstream::failure e){
        std::cout<<"ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ"<<std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    //compile shaders
    unsigned int vertex, fragment;


    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex,1,&vShaderCode,NULL);
    glCompileShader(vertex);
    checkCompileError(vertex, "VERTEX_SHADER");

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment,1,&fShaderCode,NULL);
    glCompileShader(fragment);
    checkCompileError(fragment,"FRAGMENT_SHADER");

    //shader program
    ID = glCreateProgram();
    glAttachShader(ID,vertex);
    glAttachShader(ID,fragment);
    glLinkProgram(ID);
    checkCompileError(ID,"PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::use() {
    glUseProgram(ID);
}
void Shader::setBool(const std::string &name, bool value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()),(int)value);
}
void Shader::setInit(const std::string &name, int value) const{
    glUniform1i(glGetUniformLocation(ID, name.c_str()),(int)value);
}
void Shader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()),(float)value);
}
void Shader::setFloat3(const std::string &name, float value0,float value1,float value2) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()),(float)value0,(float)value1,(float)value2);
}


void Shader::checkCompileError(unsigned int shader, std::string type) {
    int success;
    char infoLog[512];
    if (type != "PROGRAM"){
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}
#endif //OPENGL_LEARN_SHADER_H
