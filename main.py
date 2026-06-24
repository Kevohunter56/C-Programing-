from pygl import *

Include()
framebuffer_size_callback()
key_callback()

ShaderSetup()
TriangleSetup()
TriangleSetup(True,[0.7,0.2,0.0,1.0],"vtcs2",[0.0,0.0,-0.3,0.4,0.0,0.4],"VAO2","VBO2")
TriangleSetup(True,[0.2,0.5,0.1,1.0],"vtcs3",[0.0,0.0,-0.3,0.0,-0.3,-0.4],"VAO3","VBO3")
TriangleSetup(True,[0.2,0.5,0.1,1.0],"vtcs4",[0.0,0.0,0.3,0.0,0.3,0.4],"VAO4","VBO4")
main()

WriteToFile("Testmain.c")



#ShaderSetup("vertexShaderSource", "fragmentShaderSource", "vertexShader", "fragmentShader", "shaderProgram")
#TriangleSetup("Vertices1",[0.0, 0.0, 0.3, -0.4, 0.0, -0.4], "VAO1", "VBO1")
#TriangleSetup("Vertices2", [0.0, 0.0, -0.3, +0.4, 0.0, +0.4], "VAO2", "VBO2")
#hooseShaderProgram("shaderProgram")
#DrawTriangle("VAO1")
#DrawTriangle("VAO2")