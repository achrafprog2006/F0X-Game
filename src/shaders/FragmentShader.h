#pragma once

#include<string>

class FragmentShader {

public:
	size_t id;
	FragmentShader(const std::string& fileName);
	~FragmentShader();

};