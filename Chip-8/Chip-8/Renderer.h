#pragma once
#include "Common.h"


class Renderer
{

public:
	Renderer();
	~Renderer();
	bool init(string windowName, int width, int height);
	void update();
	void render();
	void clear();
	void stop();

	unsigned char* getPixels() { return m_pixels; }

private:

	//The window we'll be rendering to
	SDL_Window* m_window = NULL;

	//Creo el atributo renderer
	SDL_Renderer* m_renderer = NULL;

	//Creo el atributo textura
	SDL_Texture* m_sdlTexture = NULL;

	//Array de pixeles 
	unsigned char m_pixels[64 * 32];
};

