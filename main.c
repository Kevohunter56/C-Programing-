#include <stdio.h>
#include "glfw3.h"


void framebuffer_size_callback(GLFWwindow* window,int width,  int height)
{
    glViewport(0, 0, width, height);
}


int main()
{
    glfwInit();
    
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    GLFWwindow* window =
        glfwCreateWindow(mode->width, mode->height, "C PROGRAMMING WITH GLFW OPENGL", primaryMonitor, NULL);
    
    


    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    int WindowWidth, WindowHeight;

    while (!glfwWindowShouldClose(window))
    {   
        //Close the window when the escape key is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        // Get the current window size
        glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);
        glViewport(0, 0, WindowWidth, WindowHeight);
        
        // Set background color (Red, Green, Blue, Alpha)
        glClearColor(0.0f, 0.1f, 0.05f, 1.0f);

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Display what was drawn
        glfwSwapBuffers(window);

        // Process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}