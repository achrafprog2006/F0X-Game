 
#include "Vao.h"
#include<iostream>

Vao::Vao()
{
	glGenVertexArrays(1, &id);
}
void Vao::bind()const
{
	glBindVertexArray(id);
}
void Vao::unbind()const
{
	glBindVertexArray(0);
}
void Vao::point(GLuint location, GLuint size, GLenum type, GLuint stride, GLuint offset)const
{
	glVertexAttribPointer(location, size, type, GL_FALSE, stride,(void*) offset);
}

void Vao::enable(GLuint location)const
{
	glEnableVertexAttribArray(location);
}
void Vao::disable(GLuint location)const
{
	glDisableVertexAttribArray(location);
}
Vao::~Vao()
{
	glDeleteVertexArrays(1, &id);
	std::cout << "delete vao\n";
}