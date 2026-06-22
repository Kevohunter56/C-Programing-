oB="{"
cB="}"
nL="\\"

def ShaderSetup(vertexShaderSource="vertexShaderSource", fragmentShaderSource="fragmentShaderSource",vertexShader="vertexShader", fragmentShader="fragmentShader", shaderProgramName="shaderProgram"):
    print(f"""//vertex shader source code
const char* {vertexShaderSource} =
"#version 330 core{nL}n"
"layout (location = 0) in vec2 aPos;{nL}n"
"void main(){nL}n"
"{oB}{nL}n"
"    gl_Position = vec4(aPos, 0.0, 1.0);{nL}n"
"{cB}{nL}n";
//fragment shader source code
const char* {fragmentShaderSource} =
"#version 330 core{nL}n"
"out vec4 FragColor;{nL}n"
"void main(){nL}n"
"{oB}{nL}n"
"    FragColor = vec4(1.0, 1.0, 1.0, 1.0);{nL}n"
"{cB}{nL}n";
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
GLuint {shaderProgramName} =
glCreateProgram();
glAttachShader(
    {shaderProgramName},
    {vertexShader}
);
glAttachShader(
    {shaderProgramName},
    {fragmentShader}
);
glLinkProgram({shaderProgramName});
//DELETE the shaders as they are no longer needed after linking
glDeleteShader({vertexShader});
glDeleteShader({fragmentShader});
""")

def TriangleSetup(verticesName="vertices", points=[0.0, 0.0, 0.3, -0.4, 0.0, -0.4], VAOName="VAO", VBOName="VBO"):
    print(f"""// Define the vertices for a triangle
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

def ChooseShaderProgram(shaderProgramName="shaderProgram"):
    print(f"glUseProgram({shaderProgramName});")

def DrawTriangle(VAOName="VAO"):
    print(f"""glBindVertexArray({VAOName});
glDrawArrays(GL_TRIANGLES, 0, 3);
""")
          
#ShaderSetup("vertexShaderSource", "fragmentShaderSource", "vertexShader", "fragmentShader", "shaderProgram")
#TriangleSetup("Vertices1",[0.0, 0.0, 0.3, -0.4, 0.0, -0.4], "VAO1", "VBO1")
#TriangleSetup("Vertices2", [0.0, 0.0, -0.3, +0.4, 0.0, +0.4], "VAO2", "VBO2")
ChooseShaderProgram("shaderProgram")
DrawTriangle("VAO1")
DrawTriangle("VAO2")