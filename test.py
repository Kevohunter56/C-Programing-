oB="{"
cB="}"


verticesName = "vertices"
VAOName = "VAO"
VBOName = "VBO"


describe = f"""
Hello, we are trying to automate the process of creating a triangle in OpenGL using Python. 
The code below demonstrates how to set up a simple OpenGL context and render a triangle on the screen.

// Define the vertices for a triangle
float {verticesName}[] =
{oB}
    0.0f, 0.0f,
    0.3f, -0.4f,
    0.0f,  -0.4f
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

"""
print(describe)