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
                            
    float colors[4][4] = { {0.6f, 0.5f, 0.0f, 1.0f},{0.03f,0.04f,0.1f,0.1f},{0.03f,0.04f,0.1f,0.1f},
                         {1.0f, 0.8f, 0.2f, 1.0f} };
    int a=1;
    int Timer1 = 0;
    
    float *color1 = colors[1];
    float *color2 = colors[1];
    float *color3 = colors[1];
    float *color4 = colors[1];
    float *color5 = colors[1];
    float *color6 = colors[1];
    float *color7 = colors[1];
    float *color8 = colors[1];
    
    float Xchange = 0.01f;
                            
         
    
    
    // Declaire points Array for update  in the main loop 
    float New1[] =
    {
        0.0f, 0.0f,
        0.3f, 0.0f,
        0.3f,  0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs1[] =
    {
        0.0f, 0.0f,
        0.3f, 0.0f,
        0.3f,  0.4f
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
        sizeof(vtcs1),
        vtcs1,
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New2[] =
    {
        0.0f, 0.0f,
        0.3f, 0.4f,
        0.0f,  0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs2[] =
    {
        0.0f, 0.0f,
        0.3f, 0.4f,
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New3[] =
    {
        0.0f, 0.0f,
        0.0f, 0.4f,
        -0.3f,  0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs3[] =
    {
        0.0f, 0.0f,
        0.0f, 0.4f,
        -0.3f,  0.4f
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New4[] =
    {
        0.0f, 0.0f,
        -0.3f, 0.4f,
        -0.3f,  0.0f
    }; 
               
    // Define the vertices for a triangle
    float vtcs4[] =
    {
        0.0f, 0.0f,
        -0.3f, 0.4f,
        -0.3f,  0.0f
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New5[] =
    {
        0.0f, 0.0f,
        -0.3f, 0.0f,
        -0.3f,  -0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs5[] =
    {
        0.0f, 0.0f,
        -0.3f, 0.0f,
        -0.3f,  -0.4f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO5, VBO5;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO5);
    glGenBuffers(1, &VBO5);
    // Bind VAO first
    glBindVertexArray(VAO5);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO5);
    
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vtcs5),
        vtcs5,
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New6[] =
    {
        0.0f, 0.0f,
        -0.3f, -0.4f,
        0.0f,  -0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs6[] =
    {
        0.0f, 0.0f,
        -0.3f, -0.4f,
        0.0f,  -0.4f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO6, VBO6;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO6);
    glGenBuffers(1, &VBO6);
    // Bind VAO first
    glBindVertexArray(VAO6);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO6);
    
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vtcs6),
        vtcs6,
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New7[] =
    {
        0.0f, 0.0f,
        0.0f, -0.4f,
        0.3f,  -0.4f
    }; 
               
    // Define the vertices for a triangle
    float vtcs7[] =
    {
        0.0f, 0.0f,
        0.0f, -0.4f,
        0.3f,  -0.4f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO7, VBO7;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO7);
    glGenBuffers(1, &VBO7);
    // Bind VAO first
    glBindVertexArray(VAO7);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO7);
    
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vtcs7),
        vtcs7,
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
         
    
    
    // Declaire points Array for update  in the main loop 
    float New8[] =
    {
        0.0f, 0.0f,
        0.3f, -0.4f,
        0.3f,  0.0f
    }; 
               
    // Define the vertices for a triangle
    float vtcs8[] =
    {
        0.0f, 0.0f,
        0.3f, -0.4f,
        0.3f,  0.0f
    };
    // Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
    GLuint VAO8, VBO8;
    // Generate VAO and VBO
    glGenVertexArrays(1, &VAO8);
    glGenBuffers(1, &VBO8);
    // Bind VAO first
    glBindVertexArray(VAO8);
    // Then bind VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO8);
    
    //send the vertex data to the GPU
    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vtcs8),
        vtcs8,
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
                    
        Timer1+=1;
        if (Timer1==100) {    
            Timer1=0;            
            color1 = colors[1];
            color3 = colors[1];
            color2 = colors[1];
            color4 = colors[1]; 
            color5 = colors[1];
            color6 = colors[1];
            color7 = colors[1];
            color8 = colors[1];  
        
            if (Xchange == -0.05f) {                   
                           
                if (a==1){
                    color1= colors[0];
                    color5= colors[0];
                    color3=colors[2];
                    color7=colors[2];
                    a=2;
                } else if (a==2){
                    color2= colors[0];
                    color6= colors[0];
                    color4=colors[2];
                    color8=colors[2];
                    a=3;
                } else if (a==3){
                    color3=colors[0];
                    color7=colors[0];
                    color1= colors[2];
                    color5= colors[2];
                    a=4;
                } else if (a==4){
                    color4=colors[0];
                    color8=colors[0];
                    color2= colors[2];
                    color6= colors[2];
                    a=1;
                }                                
            } else {
                
                if (a==1){
                    color1= colors[0];
                    color5= colors[0];
                    color3=colors[2];
                    color7=colors[2];
                    a=2;
                } else if (a==2){
                    color4= colors[0];
                    color8= colors[0];
                    color2=colors[2];
                    color6=colors[2];
                    a=3;
                } else if (a==3){
                    color3=colors[0];
                    color7=colors[0];
                    color1= colors[2];
                    color5= colors[2];
                    a=4;
                } else if (a==4){
                    color2=colors[0];
                    color6=colors[0];
                    color4= colors[2];
                    color8= colors[2];
                    a=1;
                }
            }
                               
            
            New1[0] += Xchange;
            New1[2] += Xchange;
            New1[4] += Xchange;
        
            New2[0] += Xchange;
            New2[2] += Xchange;
            New2[4] += Xchange;
        
            
            New3[0] += Xchange;
            New3[2] += Xchange;
            New3[4] += Xchange;
        
            New4[0] += Xchange;
            New4[2] += Xchange;
            New4[4] += Xchange;
        
            New5[0] += Xchange;
            New5[2] += Xchange;
            New5[4] += Xchange;
        
            New6[0] += Xchange;
            New6[2] += Xchange;
            New6[4] += Xchange;
        
            New7[0] += Xchange;
            New7[2] += Xchange;
            New7[4] += Xchange;
        
            New8[0] += Xchange;
            New8[2] += Xchange;
            New8[4] += Xchange;
                               
            if (New1[4] > 1.0f) {
                                                            
                Xchange = -0.05f;
                  
            } else if (New6[2] < -1.0f) {
        
                Xchange = 0.05f;
                
            }
                                              
                
            
        }
        
                
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO1);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New1),
                        New1);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color1[0], color1[1], color1[2], color1[3]);
        glBindVertexArray(VAO1);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO2);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New2),
                        New2);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color2[0], color2[1], color2[2], color2[3]);
        glBindVertexArray(VAO2);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO3);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New3),
                        New3);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color3[0], color3[1], color3[2], color3[3]);
        glBindVertexArray(VAO3);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO4);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New4),
                        New4);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color4[0], color4[1], color4[2], color4[3]);
        glBindVertexArray(VAO4);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO5);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New5),
                        New5);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color5[0], color5[1], color5[2], color5[3]);
        glBindVertexArray(VAO5);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO6);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New6),
                        New6);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color6[0], color6[1], color6[2], color6[3]);
        glBindVertexArray(VAO6);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO7);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New7),
                        New7);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color7[0], color7[1], color7[2], color7[3]);
        glBindVertexArray(VAO7);
        glDrawArrays(GL_TRIANGLES, 0, 3);                                 
        
        
        
        //Update the vertices 
        glBindBuffer(GL_ARRAY_BUFFER, VBO8);
        glBufferSubData(GL_ARRAY_BUFFER,
                        0,
                        sizeof(New8),
                        New8);
        
        
        //Update the color
        glUniform4f(glGetUniformLocation(shaderProgram, "Color"), color8[0], color8[1], color8[2], color8[3]);
        glBindVertexArray(VAO8);
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