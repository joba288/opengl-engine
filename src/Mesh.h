#pragma once


#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector> 
#include <iostream>


struct Vertex{
    glm::vec3 positions;
    glm::vec2 texCoords;
    glm::vec3 normals;
};


class Mesh
{
    private:
        std::vector<float> vertices;
        std::vector<unsigned int> indices;
        int vertexCount;
        int indexCount;

        void InitVertexData(std::vector<Vertex> v);

        unsigned int VAO, VBO, EBO;
    public:
        Mesh(std::vector<Vertex> v,
              std::vector<unsigned int> i);
        ~Mesh();

        void Cleanup();

        int CountVertices();
        int CountIndices();

        unsigned int GetVAO();

};