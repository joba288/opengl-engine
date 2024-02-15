#include <GLFW/glfw3.h>
#include <glad/glad.h> 
#include <iostream>
#include <vector>
#include <ShaderLoader.h>
#include "Model.h"
#include "DisplayManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

int main()
{

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT);
    Shader shader("res/shaders/default.vs", "res/shaders/default.fs");

    std::vector<Vertex> squareVerts;
    squareVerts.push_back({{ 0.5f,  0.5f, 0.0f}, {0.0f, 0.0f}});   // top right
    squareVerts.push_back({{ 0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}});  // bottom right
    squareVerts.push_back({{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}});  // bottom left
    squareVerts.push_back({{-0.5f,  0.5f, 0.0f}, {0.0f, 0.0f}});  // top left

    std::vector<unsigned int> squareIndices = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle

    };

    Model square(squareVerts, squareIndices);

    // render loop
    while (!glfwWindowShouldClose(displayManager.window))
    {
        // input
        processInput(displayManager.window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(square.GetVAO());
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


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