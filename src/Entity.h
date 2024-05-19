#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector> 
#include <iostream>

#include "Model.h"

struct Transform
{
    glm::vec3 pos = glm::vec3(0.0f, 0.f, 0.f);
    glm::vec3 rot = glm::vec3(0.0f, 0.f, 0.f);
    glm::vec3 scale = glm::vec3(1.0f, 1.f, 1.f);
};


class Entity
{
    private:
        Model* activeModel;
        Transform* transform;

    public:
        Entity(Model* model);
        ~Entity();
        void SetActiveModel(Model* model);
        Model* GetActiveModel();
        void SetActiveTransform(Transform* t);
        Transform* GetActiveTransform();
        
        // set and get for all subclasses
        Mesh* GetActiveMesh();
        Texture* GetActiveTex();
        void SetActiveMesh(Mesh* mesh);
        void SetActiveTex(Texture* tex);
        unsigned int GetActiveTexID();

};