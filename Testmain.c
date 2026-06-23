//header files
#include <stdio.h>
#include "glad.h" 
#include "glfw3.h" 

//framebuffer size callback function
void framebuffer_size_callback(GLFWwindow* window,int width,  int height)
{
    glViewport(0, 0, width, height);
}

//key callback function
void key_callback(GLFWwindow* window,
                  int key,
                  int scancode,
                  int action,
                  int mods)
{
    if (action == GLFW_PRESS)
    {
            printf("Key %d pressed\n", key);
    }
}


int main()
{
    // Initialize GLFW
    glfwInit();
    
    //get the primary monitor and its video mode to create a fullscreen window
    GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);

    //window creation
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "C PROGRAMMING WITH GLFW OPENGL", primaryMonitor, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    //Initialize GLAD before calling any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return -1;
    } 


    //framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //body initalizations
    


    // Initialize window width and height variables
    int WindowWidth, WindowHeight;
    glViewport(0, 0, WindowWidth, WindowHeight);

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
        glClearColor(0.0f, 0.8f, 0.2f, 1.0f);

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
