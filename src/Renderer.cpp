#include "./Renderer.h"


Renderer::Renderer()
{

}

void Renderer::Prepare()
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);   
}

void Renderer::Render(unsigned int vaoID, int indexCount)
{

    glBindVertexArray(vaoID);
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);   

}

Renderer::~Renderer()
{

}