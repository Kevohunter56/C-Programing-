from math import sqrt
oB="{"
cB="}"
nL="\\n"
tB="\\t"

def Indent(text, prefix):
    return "\n".join(prefix + line for line in text.splitlines())

class SourceCode:
    def __init__(self):
        self.code = """"""
    def add(self,tabs=0, code = """"""):
        self.code += Indent(code,tab.put(tabs))
Code  = SourceCode()

class Tab:
    def __init__(self, tab=0):
        self.tabN = 0
        self.tab ="    "*self.tabN

    def add(self, space = 1):
        self.tabN += space
        self.tab = "    "* self.tabN
    def put(self, space = 0):
        self.tab = "    "* space
        return self.tab
    def rem(self, space = 1):
        self.tabN -= space
        if self.tabN < 0:
            self.tabN = 0
        self.tab = "    "* self.tabN
tab = Tab()

class body:
    def __init__(self):
        self.OutsideMainFunction = """"""
        self.OutsideMainLoop = """"""
        self.InsideMainLoop = """"""
    def AddOutSideMainFunction(self,tabs=0,code = """"""):

        self.OutsideMainFunction += Indent(code,tab.put(tabs))

    def AddOutSideMainLoop(self,tabs=0,code = """"""):
        self.OutsideMainLoop += Indent(code,tab.put(tabs))

    def AddInsideMainLoop(self,tabs=0, code = """""" ):
        self.InsideMainLoop += Indent(code,tab.put(tabs))
Body = body()

def ln():
    Code.add(f"{nL}")

def Include(tabs0=0,HeaderFiles=""""""):
    Code.add(tabs0,f"""//header files
#include <stdio.h>
#include "glad.h" 
#include "glfw3.h" {HeaderFiles}
""")

def framebuffer_size_callback(tabs0=0):
    Code.add(tabs0,f"""
//framebuffer size callback function
void framebuffer_size_callback(GLFWwindow* window,int width,  int height)
{oB}
    glViewport(0, 0, width, height);
{cB}
""")

def key_callback(tabs0=0):
    Code.add(tabs0,f"""
//key callback function
void key_callback(GLFWwindow* window,
                  int key,
                  int scancode,
                  int action,
                  int mods)
{oB}
    if (action == GLFW_PRESS)
    {oB}
            printf("Key %d pressed{nL}", key);
    {cB}
{cB}
""")

def main(tabs0=0,title = "C PROGRAMMING WITH GLFW OPENGL",color=[0.0, 0.8, 0.2, 1.0],windowed = "primaryMonitor", width = "mode->width", height = "mode->height"):
    Code.add(tabs0,f"""
             
{Body.OutsideMainFunction}

int main()
{oB}
    // Initialize GLFW
    glfwInit();
    
    //get the primary monitor and its video mode to create a fullscreen window
    GLFWmonitor* {windowed} = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode({windowed});

    //window creation
    GLFWwindow* window = glfwCreateWindow({width}, {height}, "{title}", {windowed}, NULL);
    if (!window) {oB}
        glfwTerminate();
        return -1;
    {cB}
    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    //Initialize GLAD before calling any OpenGL function
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {oB}
        printf("Failed to initialize GLAD{nL}");
        return -1;
    {cB} 


    //framebuffer size callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //body initalizations
    {Body.OutsideMainLoop}


    // Initialize window width and height variables
    int WindowWidth, WindowHeight;
    glViewport(0, 0, WindowWidth, WindowHeight);

    while (!glfwWindowShouldClose(window))
    {oB}
        //Close the window when the escape key is pressed
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {oB}
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        {cB}

        // Get the current window size
        glfwGetFramebufferSize(window, &WindowWidth, &WindowHeight);
        glViewport(0, 0, WindowWidth, WindowHeight);
        
        // Set background color (Red, Green, Blue, Alpha)
        glClearColor({color[0]}f, {color[1]}f, {color[2]}f, {color[3]}f);

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);
        
        {Body.InsideMainLoop}

        // Display what was drawn
        glfwSwapBuffers(window);
        // Process events
        glfwPollEvents();
    {cB}
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
{cB}
""")

def WriteToFile(FileName = "Testmain.c"):
    with open(FileName, "w") as file:
        file.write(Code.code)

def ShaderSetup(tabs1=0,tabs2=0,Use=True,vertexShaderSource="vertexShaderSource", 
                fragmentShaderSource="fragmentShaderSource",vertexShader="vertexShader", 
                fragmentShader="fragmentShader", shaderProgram="shaderProgram",OurColor="Color"):
    Body.AddOutSideMainLoop(tabs1,f"""
                            
//vertex shader source code
const char* {vertexShaderSource} =
"#version 330 core{nL}"
"layout (location = 0) in vec2 aPos;{nL}"
"void main(){nL}"
"{oB}{nL}"
"    gl_Position = vec4(aPos, 0.0, 1.0);{nL}"
"{cB}{nL}";
//fragment shader source code
const char* {fragmentShaderSource} =
"#version 330 core{nL}"
"out vec4 FragColor;{nL}"
"uniform vec4 {OurColor};{nL}"
"void main(){nL}"
"{oB}{nL}"
"    FragColor = {OurColor};{nL}"
"{cB}{nL}";
//compile the vertex shader
GLuint {vertexShader} =
glCreateShader(GL_VERTEX_SHADER);
glShaderSource(
    {vertexShader},
    1,
    &{vertexShaderSource},
    NULL
);
glCompileShader({vertexShader});
//compile the fragment shader
GLuint {fragmentShader} =
glCreateShader(GL_FRAGMENT_SHADER);
glShaderSource(
    {fragmentShader},
    1,
    &{fragmentShaderSource},
    NULL
);
glCompileShader({fragmentShader});
//create a shader program and link the shaders
GLuint {shaderProgram} =
glCreateProgram();
glAttachShader(
    {shaderProgram},
    {vertexShader}
);
glAttachShader(
    {shaderProgram},
    {fragmentShader}
);
glLinkProgram({shaderProgram});
//DELETE the shaders as they are no longer needed after linking
glDeleteShader({vertexShader});
glDeleteShader({fragmentShader});
""")
    if Use:
        Body.AddInsideMainLoop(tabs2,f"""
glUseProgram({shaderProgram});                                
    """)

def TriangleSetup(tabs1=0,tabs2=0,Use=True,color=[1.0,0.0,1.0,1.0],verticesName="vertices", 
                  points=[0.0, 0.0, 0.3, -0.4, 0.0, -0.4], VAOName="VAO", VBOName="VBO",NewPoints="",
                  shaderProgram="shaderProgram",OurColor="Color"):
    if NewPoints =="":
        UpadatePoints = ""
        DeclaireNewPoints= ""
    else:
        DeclaireNewPoints =f"""
// Declaire points Array for update  in the main loop 
float {NewPoints}[] =
{oB}
    {str(points[0])}f, {str(points[1])}f,
    {str(points[2])}f, {str(points[3])}f,
    {str(points[4])}f,  {str(points[5])}f
{cB}; 
"""
        UpadatePoints = f"""

//Update the vertices 
glBindBuffer(GL_ARRAY_BUFFER, {VBOName});
glBufferSubData(GL_ARRAY_BUFFER,
                0,
                sizeof({NewPoints}),
                {NewPoints});
"""
    
    Body.AddOutSideMainLoop(tabs1,f""" 

{DeclaireNewPoints}           
// Define the vertices for a triangle
float {verticesName}[] =
{oB}
    {str(points[0])}f, {str(points[1])}f,
    {str(points[2])}f, {str(points[3])}f,
    {str(points[4])}f,  {str(points[5])}f
{cB};
// Generate and bind a Vertex Array Object (VAO) and Vertex Buffer Object (VBO)
GLuint {VAOName}, {VBOName};
// Generate VAO and VBO
glGenVertexArrays(1, &{VAOName});
glGenBuffers(1, &{VBOName});
// Bind VAO first
glBindVertexArray({VAOName});
// Then bind VBO
glBindBuffer(GL_ARRAY_BUFFER, {VBOName});

//send the vertex data to the GPU
glBufferData(
    GL_ARRAY_BUFFER,
    sizeof({verticesName}),
    {verticesName},
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

""")
    if Use:
        Body.AddInsideMainLoop(tabs2,f"""

{UpadatePoints}

//Update the color
glUniform4f(glGetUniformLocation({shaderProgram}, "{OurColor}"), {color[0]}, {color[1]}, {color[2]}, {color[3]});
glBindVertexArray({VAOName});
glDrawArrays(GL_TRIANGLES, 0, 3);                         
""")


def Circle(tabs1=0,tabs2=0,Use=True,color=[1.0,0.0,0.1,1.0],verticesName="vertices",
           info=[0.4, 0.0, 0.0, 20], VAOName="VAO", VBOName="VBO",NewPoints="",
                  shaderProgram="shaderProgram",OurColor="Color"):
    R = info[0]
    DXP=DXN=CX=info[1]
    CY=DYP=DYN=info[2]

    DXPdy=CY+R

    NT=info[3]
    dx=dy=R/NT
    for i in range(NT):
        XF=DXP
        YF=DXPdy

        DXP += dx
        DXPdy = CY + sqrt(R**2 - DXP**2)

        
        