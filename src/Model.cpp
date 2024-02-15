#include "./Model.h"



Model::Model(std::vector<Vertex> v,
              std::vector<unsigned int> i)
{


    InitVertexData(v);
        
    Model::indices = i;


    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);


    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*i.size(), &i[0], GL_STATIC_DRAW);

    //pos attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //tex attrib
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //cleanup
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Model::InitVertexData(std::vector<Vertex> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        vertices.push_back(v[i].positions[0]);
        vertices.push_back(v[i].positions[1]);
        vertices.push_back(v[i].positions[2]);
        vertices.push_back(v[i].texCoords[0]);
        vertices.push_back(v[i].texCoords[1]);
    }
}


unsigned int Model::GetVAO()
{
    return VAO;
}

void Model::Cleanup()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);  
}


Model::~Model()
{
    Cleanup();
}
