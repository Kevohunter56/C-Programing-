from pygl import *

Include()
framebuffer_size_callback()
key_callback()

ShaderSetup()
TriangleSetup(True,[0.2,0.7,0.7,1.0])
TriangleSetup(True,[1.0,0.4,0.3,1.0],"vtcs2",[0.0,0.0,-0.3,0.4,0.0,0.4],"VAO2","VBO2")
TriangleSetup(True,[1.0,0.8,0.2,1.0],"vtcs3",[0.0,0.0,-0.3,0.0,-0.3,-0.4],"VAO3","VBO3")
TriangleSetup(True,[0.6,0.2,0.8,1.0],"vtcs4",[0.0,0.0,0.3,0.0,0.3,0.4],"VAO4","VBO4")
main("KEVIN THE PHILOSOPHER",[0.03,0.04,0.1,0.1])

WriteToFile("Testmain.c")
