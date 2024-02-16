#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <stb_image.h>
#include <vector> 
#include <iostream>




class Texture
{
    private:
        unsigned int texID;
        int width, height, nrChannels;
        unsigned char* data;
        void InitTexture(const char* filepath);

    public:
        Texture(const char* filepath);
        ~Texture();
        unsigned int GetID();
        void BindTexture();

};