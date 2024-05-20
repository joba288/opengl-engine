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
#include "OBJLoader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window, Camera camera, float deltaTime);

// settings
const unsigned int SCR_WIDTH = 1080;
const unsigned int SCR_HEIGHT = 720;


bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{

    DisplayManager displayManager(SCR_WIDTH, SCR_HEIGHT);
    Shader shader("res/shaders/default.vs", "res/shaders/default.fs");
    Renderer renderer(&shader);
    Texture texture("res/images/Button.jpg");
    Texture texture1("res/images/aperature turrent.jpg");
 
    Transform transform;
    

    
   
    Camera camera(glm::vec3(0.0f, 0.0f, 1.0f));
    //camera.position = glm::vec3(0.f,0.f,-3.f);

    std::vector<Vertex> turret_v;
    std::vector<unsigned int> turret_i;
    loadOBJ("res/models/portalbutton.obj", turret_v, turret_i);

    Mesh turretMesh(turret_v, turret_i);
    Model turretModel(&turretMesh, &texture);

    Entity turret(&turretModel);

    std::vector<Vertex> button_v;
    std::vector<unsigned int> button_i;
    loadOBJ("res/models/aperature turrent.obj", button_v, button_i);

    Mesh buttonMesh(button_v, button_i);
    Model buttonModel(&buttonMesh, &texture);

    
    



    


    // render loop
    while (!glfwWindowShouldClose(displayManager.window))
    {
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        // input
        processInput(displayManager.window, camera, deltaTime);
        
        if (glfwGetKey(displayManager.window, GLFW_KEY_SPACE) == GLFW_PRESS)
        {
            turret.SetActiveModel(&turretModel);
            shader.setInt("tex", turret.GetActiveTexID());
        }
        else
        {
            turret.SetActiveModel(&buttonModel);
            shader.setInt("tex", texture1.GetID());
        }


        transform.scale.x = 0.2f;
        transform.scale.y = 0.2f;
        transform.scale.z = 0.2f;

        transform.rot.x += 1.f;
        transform.rot.z += 1.f;
        transform.rot.z += 1.f;

        turret.SetActiveTransform(&transform);
        // render
        renderer.Prepare();

        shader.setMat4("view", camera.GetViewMatrix());

        renderer.Render(&turret, &shader);

        displayManager.UpdateDisplay();      
    }
    displayManager.CleanupDisplay();
    return 0;
}


void processInput(GLFWwindow *window, Camera camera, float deltaTime)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);



    
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}