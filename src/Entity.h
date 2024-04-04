#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector> 
#include <iostream>

#include "Model.h"

struct Transform
{
    glm::mat4 modelMat         = glm::mat4(1.0f);
    glm::mat4 viewMat          = glm::mat4(1.0f);
    glm::mat4 projMat          = glm::mat4(1.0f);
};


class Entity
{
    private:
        Model* activeModel;
        Transform transform;

    public:
        Entity(Model* model);
        ~Entity();
        //void SetActiveModel(Model* model);
        Model* GetActiveModel();
        void SetActiveTransform(Transform t);
        Transform GetActiveTransform();
        
        // set and get for all subclasses

};