#pragma once
#include <glad/glad.h>
class Vao {

    unsigned int id;

public:
    Vao();
    ~Vao();
    void bind()const;
    void unbind()const;
    void point(GLuint location ,GLuint size,GLuint Type,GLuint stride , GLuint offset)const;
    void enable(GLuint location)const;
    void disable(GLuint location)const;


};
