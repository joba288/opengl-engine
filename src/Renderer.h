#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h> 
#include "ShaderLoader.h"
#include "Model.h"

class Renderer
{
    private:

    public:
        Renderer();
        ~Renderer();

        void Prepare();
        void Render(unsigned int vaoID, int indexCount);


};