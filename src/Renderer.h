#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h> 
#include "ShaderLoader.h"
#include "Entity.h"


class Renderer
{
    private:
        float fov = 70;
        glm::mat4 projMat;
    public:
        Renderer(Shader* shader);
        ~Renderer();

        void Prepare();
        void Render(Entity* entity, Shader* shader);


};