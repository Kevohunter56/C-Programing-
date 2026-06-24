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
        

    // Set the framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    /* Set the key callback function
    glfwSetKeyCallback(window, key_callback); */
    // Initialize window width and height variables



    

    // Define the vertices for a triangle
    float Vertices1[] =
    {
        0.0f, 0.0f,
        0.3f, -0.4f,
        0.0f,  -0.4f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO1, VBO1;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO1);
    glGenBuffers(1, &VBO1);
    // Bind VAO first
    glBindVertexArray(VAO1);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(Vertices1),
        Vertices1,
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
    "uniform vec4 ourColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = ourColor;\n"
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



    // Define the vertices for a triangle
    float Vertices2[] =
    {
        0.0f, 0.0f,
        -0.3f, 0.4f,
        0.0f,  0.4f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO2, VBO2;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO2);
    glGenBuffers(1, &VBO2);
    // Bind VAO first
    glBindVertexArray(VAO2);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);

    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(Vertices2),
        Vertices2,
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




    while (!glfwWindowShouldClose(window))
    {   
        //Close the window when the escape key is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        } 

        // Set background color (Red, Green, Blue, Alpha)
        glClearColor(0.0f, 0.1f, 0.05f, 1.0f);
        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        
        glUseProgram(shaderProgram);
        glUniform4f(glGetUniformLocation(shaderProgram, "ourColor"), 1.0f, 0.0f, 0.0f, 1.0f);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glUniform4f(glGetUniformLocation(shaderProgram, "ourColor"), 0.0f, 1.0f, 0.0f, 1.0f);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);



        // Display what was drawn
        glfwSwapBuffers(window);

        // Process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}