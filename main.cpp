#include <iostream>
#include "glfw3.h"

#define WIDTH 1000
#define HEIGHT 800

GLFWwindow* window;
bool running;

void Start();
void Update();
void Input();
void Render();

void error_callback (int error, const char* description)
{
    fprintf(stderr, "GLFW Error: %s\n", description);
}

int Init () {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {std::cout << "GLFW init failed"; return 0;}
    window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if (!window) {std::cout << "Window failed to create"; return 0;}
    glfwMakeContextCurrent(window);
    running = true;
    return 1;
}

int main () {
    if (!Init()) return 1;
    Start();

    while (running) {
        Update();
        Input();
        Render();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

//   Frame Functions

void Start () {

}

void Update () {
    
}

void Input () {
    glfwPollEvents();

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        running = false;
        glfwSetWindowShouldClose(window, 1);
    }
}

void Render () {
    glClearColor(1, 0, 0, 0.5f);
    glClear(GL_COLOR_BUFFER_BIT);

    //render

    glfwSwapBuffers(window);
}