#include "./Model.h"



Model::Model(Mesh* mesh, Texture* tex)
{
    SetActiveMesh(mesh);
    SetActiveTex(tex);
}

Mesh* Model::GetActiveMesh()
{
    return activeMesh;
}

Texture* Model::GetActiveTex()
{
    return activeTex;
}

void Model::SetActiveMesh(Mesh* mesh)
{
    activeMesh = mesh;
}


void Model::SetActiveTex(Texture* tex)
{
    activeTex = tex;
}

Model::~Model()
{}
