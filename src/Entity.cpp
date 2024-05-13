#include "./Entity.h"

Entity::Entity(Model* model)
{
    Entity::activeModel = model;

}

void Entity::SetActiveModel(Model* model)
{
    Entity::activeModel = model;
}

Model* Entity::GetActiveModel()
{
    return Entity::activeModel;
}

void Entity::SetActiveTransform(Transform* t)
{
    Entity::transform = t;
}

Transform* Entity::GetActiveTransform()
{
    return Entity::transform;
}

// transform getters and setters

void Entity::SetModelMat(glm::mat4 model)
{
    Entity::transform->modelMat = model;
}
void Entity::SetViewMat(glm::mat4 view)
{
    Entity::transform->viewMat = view;
}
void Entity::SetProjMat(glm::mat4 proj)
{
    Entity::transform->projMat = proj;
}

// model getters and setters

Mesh* Entity::GetActiveMesh()
{
    return Entity::activeModel->GetActiveMesh();
}

Texture* Entity::GetActiveTex()
{
    return Entity::activeModel->GetActiveTex();
}

void Entity::SetActiveMesh(Mesh* mesh)
{
    Entity::activeModel->SetActiveMesh(mesh);
}

void Entity::SetActiveTex(Texture* tex)
{
    Entity::activeModel->SetActiveTex(tex);
}

// texture getters and setters

unsigned int Entity::GetActiveTexID()
{
    return Entity::GetActiveTex()->GetID();
}

Entity::~Entity()
{

}