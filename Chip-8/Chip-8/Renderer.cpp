#include "Renderer.h"

bool Renderer::init(const char* windowName, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	SDL_RenderSetLogicalSize(m_renderer, width, height);

	m_sdlTexture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, 64, 32);

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);

	return true;
}

void Renderer::render(){
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_sdlTexture, NULL, NULL);
	SDL_RenderPresent(m_renderer);
	SDL_Delay(1000 / 24);
}

void Renderer::clear() {
    SDL_RenderClear(m_renderer);
}

void Renderer::stop()
{
	// destroy renderer
	SDL_DestroyRenderer(m_renderer);

	// destroy window
	SDL_DestroyWindow(m_window);

	// close SDL
	SDL_Quit();
}
