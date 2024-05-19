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
#include "Camera.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;

int main()
{

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT);
    Shader shader("res/shaders/default.vs", "res/shaders/default.fs");
    Renderer renderer(&shader);
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

    Transform transform;
    

    
    shader.setInt("tex", square.GetActiveTexID());

    Camera camera(glm::vec3(0.0f, 0.0f, 1.0f));
    //camera.position = glm::vec3(0.f,0.f,-3.f);

    // render loop
    while (!glfwWindowShouldClose(displayManager.window))
    {
        // input
        processInput(displayManager.window);
 
        square.SetActiveTransform(&transform);
        // render
        renderer.Prepare();

        shader.setMat4("view", camera.GetViewMatrix());

        renderer.Render(&square, &shader);

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