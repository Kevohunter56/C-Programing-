#include <GLFW/glfw3.h>

/*gcc main.c -IC:\glfw-3.4.bin.WIN64\include -LC:\glfw-3.4.bin.WIN64\lib-mingw-w64 -lglfw3 
-lgdi32 -lopengl32 -o app.exea */

int main()
{
    glfwInit();

    GLFWwindow* window =
        glfwCreateWindow(800, 600, "Hello My Great GLFW", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}