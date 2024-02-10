#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h> 
#include <iostream>


class DisplayManager
{
    private:

    public:
        DisplayManager(int scr_width, int scr_height);
        GLFWwindow* window = NULL;
        GLFWwindow* CreateDisplay(int scr_width, int scr_height);
        void UpdateDisplay();
        void CleanupDisplay();


};