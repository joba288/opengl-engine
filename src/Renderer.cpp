#include "./Renderer.h"


Renderer::Renderer(Shader* shader)
{
    Renderer::projMat = glm::perspective(glm::radians(Renderer::fov), 1080.0f / 720.0f, 0.1f, 100.0f);
}

void Renderer::Prepare()
{
    glEnable(GL_DEPTH_TEST);  
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);   
}

void Renderer::Render(Entity* entity, Shader* shader)
{
    //Model* model = entity->GetActiveModel();
    Mesh* mesh = entity->GetActiveMesh();
    Texture* tex = entity->GetActiveTex();
    Transform* transform = entity->GetActiveTransform();
    
    // calculate model matrix
    glm::mat4 modelMat = glm::translate(glm::mat4(1.0f), transform->pos);
    modelMat = glm::rotate(modelMat, glm::radians(transform->rot.x), glm::vec3(1.f, 0.f, 0.f));
    modelMat = glm::rotate(modelMat, glm::radians(transform->rot.y), glm::vec3(0.f, 1.f, 0.f));
    modelMat = glm::rotate(modelMat, glm::radians(transform->rot.z), glm::vec3(0.f, 0.f, 1.f));
    modelMat = glm::scale(modelMat, transform->scale);

    
    shader->use();
    
    shader->setMat4("model", modelMat);
    shader->setMat4("projection", Renderer::projMat);
    
    
    tex->BindTexture();
    glBindVertexArray(mesh->GetVAO());
    glDrawElements(GL_TRIANGLES, mesh->CountIndices(), GL_UNSIGNED_INT, 0);   

}

Renderer::~Renderer()
{

}