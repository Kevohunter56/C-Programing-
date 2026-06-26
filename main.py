from pygl import *
#predefined methods 
Include()
framebuffer_size_callback()
key_callback()


Body.AddOutSideMainFunction(0,"""
""")

ShaderSetup(1,2)

Body.AddOutSideMainLoop(1,"""
                        
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
                        

""")

Body.AddInsideMainLoop(2,"""
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


""" )

TriangleSetup(1,2,True,["color1[0]","color1[1]","color1[2]","color1[3]"],"vtcs1",[0.0,0.0,0.3,0.0,0.3,0.4],"VAO1","VBO1","New1")
TriangleSetup(1,2,True,["color2[0]","color2[1]","color2[2]","color2[3]"],"vtcs2",[0.0,0.0,0.3,0.4,0.0,0.4],"VAO2","VBO2","New2")
TriangleSetup(1,2,True,["color3[0]","color3[1]","color3[2]","color3[3]"],"vtcs3",[0.0,0.0,0.0,0.4,-0.3,0.4],"VAO3","VBO3","New3")
TriangleSetup(1,2,True,["color4[0]","color4[1]","color4[2]","color4[3]"],"vtcs4",[0.0,0.0,-0.3,0.4,-0.3,0.0],"VAO4","VBO4","New4")
TriangleSetup(1,2,True,["color5[0]","color5[1]","color5[2]","color5[3]"],"vtcs5",[0.0,0.0,-0.3,0.0,-0.3,-0.4],"VAO5","VBO5","New5")
TriangleSetup(1,2,True,["color6[0]","color6[1]","color6[2]","color6[3]"],"vtcs6",[0.0,0.0,-0.3,-0.4,0.0,-0.4],"VAO6","VBO6","New6")
TriangleSetup(1,2,True,["color7[0]","color7[1]","color7[2]","color7[3]"],"vtcs7",[0.0,0.0,0.0,-0.4,0.3,-0.4],"VAO7","VBO7","New7")
TriangleSetup(1,2,True,["color8[0]","color8[1]","color8[2]","color8[3]"],"vtcs8",[0.0,0.0,0.3,-0.4,0.3,0.0],"VAO8","VBO8","New8")


main(0,"KEVIN THE PHILOSOPHER",[0.03,0.04,0.1,0.1])
WriteToFile("Testmain.c")
