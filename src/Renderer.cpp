#include "./Renderer.h"


Renderer::Renderer()
{

}

void Renderer::Prepare()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);   
}

void Renderer::Render(Model* model, Shader* shader)
{
    
    Mesh* mesh = model->GetActiveMesh();
    Texture* tex = model->GetActiveTex();
    
    shader->use();
    
    tex->BindTexture();
    glBindVertexArray(mesh->GetVAO());
    glDrawElements(GL_TRIANGLES, mesh->CountIndices(), GL_UNSIGNED_INT, 0);   

}

Renderer::~Renderer()
{

}