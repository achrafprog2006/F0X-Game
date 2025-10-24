#pragma once

#include <glad/glad.h>
#include<vector>

class Vbo {
public:
    unsigned int id;
    Vbo();
    void bind()const;
    void unbind()const;
    void fill(float* data, int size)const;
    void fill(const std::vector<float>& data)const;
    ~Vbo();
};

