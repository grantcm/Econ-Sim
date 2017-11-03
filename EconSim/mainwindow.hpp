//
//  mainwindow.hpp
//  EconSim
//
//  Created by Grant Miller on 11/3/17.
//  Copyright © 2017 Grant Miller. All rights reserved.
//

#ifndef mainwindow_h
#define mainwindow_h
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class MainWindow {
    GLFWwindow * mainWindow;
    
public:
    MainWindow(){
        setupMainWindow();
    }
    void setupMainWindow ();
    GLFWwindow * getMainWindow();
    
};

#endif /* mainwindow_h */
