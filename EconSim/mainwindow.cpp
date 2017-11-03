//
//  mainwindow.cpp
//  EconSim
//
//  Created by Grant Miller on 11/1/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "mainwindow.hpp"

void MainWindow::setupMainWindow() {
    
    GLfloat vertices[] = {
        -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
        -0.5, -0.5f, 1.0f, 1.0f, 1.0f
//        
//        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
//        0.25f, 0.0f, 0.0f, 1.0f, 0.0f,
//        0.0f, -0.5f, 0.0f, 1.0f, 0.0f,
//        
//        -0.5f,-0.5f, 0.0f, 0.0f, 1.0f,
//        -0.25f, 0.0f, 0.0f, 0.0f, 1.0f,
//        0.0f, -0.5f, 0.0f, 0.0f, 1.0f
    };
    
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0
    };
    
    //shaders
    const GLchar* vertexSource  =  R"glsl(
    #version 150 core
    
    in vec2 position;
    in vec3 color;
    out vec3 Color;
    
    void main()
    {
        Color = color;
        gl_Position = vec4(position, 0.0, 1.0);
    }
    )glsl";
    
    const GLchar* fragmentSource = R"glsl(
    #version 150 core
    
    in vec3 Color;
    out vec4 outColor;
    
    void main(){
        outColor = vec4 (Color, 1.0);
    }
    )glsl";
    
    //setup main window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    
    mainWindow = glfwCreateWindow(800, 600, "EconSim", nullptr, nullptr);
    
    glfwMakeContextCurrent(mainWindow);
    
    //init glew
    glewExperimental = GL_TRUE;
    glewInit();
    
    //Create vao object and bind to the vbo just made
    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    GLuint ebo;
    glGenBuffers(1, &ebo);
    
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    //bind buffer to vertex array
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    //Static draw - draw many times, draw the same
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //Compile vertex Shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);
    //Compile fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    //Check for success
    GLint status, statusFragShader;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &statusFragShader);
    
    if (status != GL_TRUE) {
        //failed to compile, get log
        char buffer[512];
        glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(-1);
    }
    
    if (statusFragShader != GL_TRUE) {
        char buffer[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, buffer);
        printf("%s\n", buffer);
        exit(-1);
    }
    
    
    
    //Combine into program
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glBindFragDataLocation(shaderProgram, 0, "outColor");
    //Link Program
    glLinkProgram(shaderProgram);
    glUseProgram(shaderProgram);

    //Set pos attribute and define how to read VBO
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
    glEnableVertexAttribArray(posAttrib);
    glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), 0);
    
    //Set shader color
    GLint colAttrib = glGetAttribLocation(shaderProgram, "color");
    glEnableVertexAttribArray(colAttrib);
    glVertexAttribPointer(colAttrib, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (void *) (2 * sizeof(GLfloat)));
    
    //Load elements
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
    
    
    
    
    //event loop
    while (!glfwWindowShouldClose(mainWindow)) {
        
        glfwSwapBuffers(mainWindow);
        glfwPollEvents();
        
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }

    
    glfwTerminate();
}

GLFWwindow * MainWindow::getMainWindow() {
    return mainWindow;
}

