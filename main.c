#include "glfw3.h"

int main()
{
    glfwInit();

    GLFWwindow* window =
        glfwCreateWindow(800, 600, "Hello Great GLFW", NULL, NULL);

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