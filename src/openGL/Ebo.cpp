#include"Ebo.h"
#include<iostream>


Ebo::Ebo()
{
    glGenBuffers(1, &id);
}
Ebo::~Ebo() {
    glDeleteBuffers(1, &id);
    std::cout << "delete ebo\n";
}

void Ebo::bind()const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void Ebo::unbind()const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Ebo::fill(unsigned int* data, int size)const
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}
void Ebo::fill(const std::vector<unsigned int>& data)const
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
}

