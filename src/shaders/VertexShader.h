#pragma once

#include<string>


class VertexShader {

public :
	size_t id;
	VertexShader(const std::string& fileName);
	~VertexShader();

};