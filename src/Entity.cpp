#include "./Entity.h"

Entity::Entity(Model* model)
{
    Entity::activeModel = model;

}

Model* Entity::GetActiveModel()
{
    return Entity::activeModel;
}



void Entity::SetActiveTransform(Transform t)
{
    Entity::transform = t;
}

Transform Entity::GetActiveTransform()
{
    return Entity::transform;
}

Entity::~Entity()
{

}