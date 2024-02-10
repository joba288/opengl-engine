#include "./DisplayManager.h"


DisplayManager::DisplayManager(int scr_width, int scr_height)
{
    CreateDisplay(scr_width, scr_height);
}

GLFWwindow* DisplayManager::CreateDisplay(int scr_width, int scr_height)
{
    //glfw init
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 


    //window
    window = glfwCreateWindow(scr_width, scr_height, "JobaGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);

    //glad init
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return NULL;
    }  

    return window;

}

void DisplayManager::UpdateDisplay()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

void DisplayManager::CleanupDisplay()
{
    glfwTerminate();
}