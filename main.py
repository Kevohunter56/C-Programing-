from pygl import *

Include()
framebuffer_size_callback()
key_callback()

main()




WriteToFile("Testmain.c")



#ShaderSetup("vertexShaderSource", "fragmentShaderSource", "vertexShader", "fragmentShader", "shaderProgram")
#TriangleSetup("Vertices1",[0.0, 0.0, 0.3, -0.4, 0.0, -0.4], "VAO1", "VBO1")
#TriangleSetup("Vertices2", [0.0, 0.0, -0.3, +0.4, 0.0, +0.4], "VAO2", "VBO2")
#hooseShaderProgram("shaderProgram")
#DrawTriangle("VAO1")
#DrawTriangle("VAO2")