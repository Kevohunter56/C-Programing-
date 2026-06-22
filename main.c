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


    //Initialize GLAD before calling any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        printf("Failed to initialize GLAD\n");
        return -1;
    } 
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO, VBO;

    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind VAO first
    glBindVertexArray(VAO);

    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

        

    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    /* Set the key callback function
    glfwSetKeyCallback(window, key_callback); */
    // Initialize window width and height variables
    int WindowWidth, WindowHeight;
    glViewport(0, 0, WindowWidth, WindowHeight);

    // Define the vertices for a triangle
    float vertices[] =
    {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f,  0.5f
    };
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );
    // Define the layout of the vertex data
    glVertexAttribPointer(
        0,                  // attribute location
        2,                  // x,y
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(0);
    //vertex shader source code
    const char* vertexShaderSource =
    "#version 330 core\n"
    "layout (location = 0) in vec2 aPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos, 0.0, 1.0);\n"
    "}\n";
    //fragment shader source code
    const char* fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
    "}\n";
    //compile the vertex shader
    GLuint vertexShader =
    glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(
        vertexShader,
        1,
        &vertexShaderSource,
        NULL
    );
    glCompileShader(vertexShader);
    //compile the fragment shader
    GLuint fragmentShader =
    glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(
        fragmentShader,
        1,
        &fragmentShaderSource,
        NULL
    );
    glCompileShader(fragmentShader);
    //create a shader program and link the shaders
    GLuint shaderProgram =
    glCreateProgram();
    glAttachShader(
        shaderProgram,
        vertexShader
    );
    glAttachShader(
        shaderProgram,
        fragmentShader
    );
    glLinkProgram(shaderProgram);
    //DELETE the shaders as they are no longer needed after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    while (!glfwWindowShouldClose(window))
    {   
        //Close the window when the escape key is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
        // Get the current window size
        glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);

        // Set background color (Red, Green, Blue, Alpha)
        glClearColor(0.0f, 0.1f, 0.05f, 1.0f);
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        //glClearColor(0.0f, 0.2f, 0.2f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(VAO);

        glDrawArrays(
            GL_TRIANGLES,
            0,
            3
        );




        // Display what was drawn
        glfwSwapBuffers(window);

        // Process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}