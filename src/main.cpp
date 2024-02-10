#include <GLFW/glfw3.h>
#include <glad/glad.h> 
#include <iostream>
#include "DisplayManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

int main()
{

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT);  

    // render loop
    while (!glfwWindowShouldClose(displayManager.window))
    {
        // input
        processInput(displayManager.window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        displayManager.UpdateDisplay();      
    }
    displayManager.CleanupDisplay();
    return 0;
}


void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}