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
        int vertexCount;
        int indexCount;

        void InitVertexData(std::vector<Vertex> v);

        unsigned int VAO, VBO, EBO;
    public:
        Model(std::vector<Vertex> v,
              std::vector<unsigned int> i);
        ~Model();

        void Cleanup();

        int CountVertices();
        int CountIndices();

        unsigned int GetVAO();

};