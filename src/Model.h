#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector> 
#include <iostream>
#include "Mesh.h"
#include "Texture.h"



class Model
{
    private:
        Mesh* activeMesh;
        Texture* activeTex;
    public:
        Model(Mesh* mesh, Texture* texture);
        ~Model();
        
        Mesh* GetActiveMesh();
        void SetActiveMesh(Mesh* mesh);

        Texture* GetActiveTex();
        void SetActiveTex(Texture* tex);

};