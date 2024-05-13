#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h> 
#include <iostream>
#include <vector>
#include <ShaderLoader.h>
#include "Mesh.h"
#include "DisplayManager.h"
#include "Renderer.h"
#include "Texture.h"
#include "Entity.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

int main()
{

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT);
    Renderer renderer;
    
    Shader shader("res/shaders/default.vs", "res/shaders/default.fs");
    Texture texture("res/images/larrald.jpg");
    std::vector<Vertex> squareVerts;
    squareVerts.push_back({{ 0.5f,  0.5f, 0.0f}, {1.0f, 1.0f}});   // top right
    squareVerts.push_back({{ 0.5f, -0.5f, 0.0f}, {1.0f, 0.0f}});  // bottom right
    squareVerts.push_back({{-0.5f, -0.5f, 0.0f}, {0.0f, 0.0f}});  // bottom left
    squareVerts.push_back({{-0.5f,  0.5f, 0.0f}, {0.0f, 1.0f}});  // top left

    std::vector<unsigned int> squareIndices = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle

    };

    Mesh squareMesh(squareVerts, squareIndices);
    Model squareModel(&squareMesh, &texture);


    Entity square(&squareModel);

    Transform squareTransform;
    squareTransform.modelMat = glm::rotate(glm::mat4(1.0f), glm::radians(45.0f), glm::vec3(0.0f, 1.0f, -1.0f));
    squareTransform.projMat  = glm::perspective(glm::radians(45.0f),(float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    squareTransform.viewMat  = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
    // to do setters for all these from the entity class
    square.SetActiveTransform(&squareTransform);

    shader.setInt("tex", square.GetActiveTexID());
    


    // render loop
    while (!glfwWindowShouldClose(displayManager.window))
    {
        // input
        processInput(displayManager.window);

        shader.setMat4("model", square.GetActiveTransform()->modelMat);
        shader.setMat4("projection", square.GetActiveTransform()->projMat);
        shader.setMat4("view", square.GetActiveTransform()->viewMat);
        // render
        renderer.Prepare();
        renderer.Render(square.GetActiveModel(), &shader);

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