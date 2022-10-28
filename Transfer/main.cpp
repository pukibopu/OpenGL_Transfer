//
//  main.cpp
//  Transfer
//
//  Created by ShuYang Yan on 2022/10/28.
//

#include <iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window,int width,int height){
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE)== GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    GLFWwindow *window=glfwCreateWindow(800, 600, "Transfer", NULL, NULL);
    if (!window) {
        std::cerr<<"Error to create window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr<<"Error to Initial glad"<<std::endl;
        return  -1;
    }
    
    while (!glfwWindowShouldClose(window)) {
        //input
        processInput(window);
        
        
        glClearColor(0.1f,0.2f,0.1f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    

    
    return 0;
}
