#include "Vbo.h"
#include<iostream>

 Vbo::Vbo()
 {
     glGenBuffers(1, &id);
}
void Vbo::bind()const
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}
void Vbo::unbind()const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void Vbo::fill(float* data, int size)const
{
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
void Vbo::fill(const std::vector<float>& data)const
{
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
}


Vbo::~Vbo()
{
    glDeleteBuffers(1, &id);
    std::cout << "delete vbo\n";
}
