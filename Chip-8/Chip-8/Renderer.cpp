#include "Renderer.h"

bool Renderer::init(string windowName, int width, int height)
{

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Window Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
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

void Renderer::update()
{
	for (int i = 0; i < 64; i++) {
		for (int j = 0; j < 32; j++) {
			cout << +m_pixels[j + i * 32];
		}
		cout << "\n";
	}

	unsigned char pixels_rgb[64 * 32 * 3];

	int idx = 0;
	for (int i = 0; i < (64 * 32); i++) {
		unsigned char aux = m_pixels[i];
		pixels_rgb[idx] = aux * 0xFF;
		pixels_rgb[idx + 1] = aux * 0xFF;
		pixels_rgb[idx + 2] = aux * 0xFF;

		idx += 3;
	}
	SDL_UpdateTexture(m_sdlTexture, NULL, pixels_rgb, 64 * 3 * sizeof(unsigned char));
}