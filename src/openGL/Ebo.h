#pragma once
#include<glad/glad.h>
#include<vector>

class Ebo
{
    unsigned int id;
public:
    Ebo();
    ~Ebo();

    void bind()const;      
    void unbind()const;
    void fill(unsigned int* data, int size)const;
    void fill(const std::vector<unsigned int>& data)const;
    
};