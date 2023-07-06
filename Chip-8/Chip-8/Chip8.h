#pragma once
#include "CPU.h"
#include "Renderer.h"


class Chip8
{
public:
	Chip8();
	~Chip8();

	void init(string gameName, int width, int height);
	void decodeNext();
	void update();


private:

	unsigned char getVx(uint16_t inst);
	unsigned char getVy(uint16_t inst);

	CPU		   *m_cpu;
	Memory		m_memory;
	Renderer	m_renderer;
};

