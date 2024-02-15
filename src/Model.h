#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector> 
#include <iostream>


struct Vertex{
    float positions[3];
    float texCoords[2];
};


class Model
{
    private:
        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        unsigned int VAO, VBO, EBO;

        void InitVertexData(std::vector<Vertex> v);

    public:
        Model(std::vector<Vertex> v,
              std::vector<unsigned int> i);
        ~Model();

        

        void Cleanup();


        unsigned int GetVAO();
        


};