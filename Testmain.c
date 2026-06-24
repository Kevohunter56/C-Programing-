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
    GLFWwindow* window = glfwCreateWindow(mode->width, mode->height, "KEVIN THE PHILOSOPHER", primaryMonitor, NULL);
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
"uniform vec4 Color;\n"
"void main()\n"
"{\n"
"    FragColor = Color;\n"
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
float vertices[] =
{
    0.0f, 0.0f,
    0.3f, -0.4f,
    0.0f,  -0.4f
};
// Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
GLuint VAO, VBO;
// Generate VAO and VBO
glGenVertexArrays(1, &VAO);
glGenBuffers(1, &VBO);
// Bind VAO first
glBindVertexArray(VAO);
// Then bind VBO
glBindBuffer(GL_ARRAY_BUFFER, VBO);

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


// Define the vertices for a triangle
float vtcs2[] =
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
    sizeof(vtcs2),
    vtcs2,
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


// Define the vertices for a triangle
float vtcs3[] =
{
    0.0f, 0.0f,
    -0.3f, 0.0f,
    -0.3f,  -0.4f
};
// Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
GLuint VAO3, VBO3;
// Generate VAO and VBO
glGenVertexArrays(1, &VAO3);
glGenBuffers(1, &VBO3);
// Bind VAO first
glBindVertexArray(VAO3);
// Then bind VBO
glBindBuffer(GL_ARRAY_BUFFER, VBO3);

//send the vertex data to the GPU
glBufferData(
    GL_ARRAY_BUFFER,
    sizeof(vtcs3),
    vtcs3,
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


// Define the vertices for a triangle
float vtcs4[] =
{
    0.0f, 0.0f,
    0.3f, 0.0f,
    0.3f,  0.4f
};
// Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
GLuint VAO4, VBO4;
// Generate VAO and VBO
glGenVertexArrays(1, &VAO4);
glGenBuffers(1, &VBO4);
// Bind VAO first
glBindVertexArray(VAO4);
// Then bind VBO
glBindBuffer(GL_ARRAY_BUFFER, VBO4);

//send the vertex data to the GPU
glBufferData(
    GL_ARRAY_BUFFER,
    sizeof(vtcs4),
    vtcs4,
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




    // Initialize window width and height variables
    int WindowWidth, WindowHeight;
    glViewport(0, 0, WindowWidth, WindowHeight);
    float colors[4][4] = {{0.2f, 0.7f, 0.7f, 1.0f},{1.0f, 0.4f, 0.3f, 1.0f},{1.0f, 0.8f, 0.2f, 1.0f},{0.6f, 0.2f, 0.8f, 1.0f}};
    int w=0,x = 0,y=0,z=0;
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
        glClearColor(0.03f, 0.04f, 0.1f, 0.1f);

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        
        glUseProgram(shaderProgram);                                

            
            float *color1 = colors[w];
            float *color2 = colors[x];
            float *color3 = colors[x];
            float *color4 = colors[x];

            glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color1[0],color1[1],color1[2],color1[3]);
            glBindVertexArray(VAO);
            glDrawArrays(GL_TRIANGLES, 0, 3);                         


            glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color2[0],color2[1],color2[2],color2[3]);
            glBindVertexArray(VAO2);
            glDrawArrays(GL_TRIANGLES, 0, 3);                         


            glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color3[0],color3[1],color3[2],color3[3]);
            glBindVertexArray(VAO3);
            glDrawArrays(GL_TRIANGLES, 0, 3);                         


            glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color4[0],color4[1],color4[2],color4[3]);
            glBindVertexArray(VAO4);
            glDrawArrays(GL_TRIANGLES, 0, 3);                         

            
            if (w==3){
                w=0;
            }else{
                w+=1;
            }
            if (x==3){
                x=0;
            }else{
                x+=1;
            }
            if (y==3){
                y=0;
            }else{
                y+=1;
            }
            if (z==3){
                z=0;
            }else{
                z+=1;
            }



        // Display what was drawn
        glfwSwapBuffers(window);
        // Process events
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
