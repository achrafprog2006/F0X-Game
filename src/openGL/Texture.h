#pragma once

class Texture {
public:
	unsigned int id;

	Texture(const char* filename);
	~Texture();

	void bind();
	void activateOn(int unit);

};