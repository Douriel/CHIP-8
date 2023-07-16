#include "Chip8.h"

Chip8::Chip8()
{
}

Chip8::~Chip8()
{
}

void Chip8::init(string gameName, int width, int height) {

	m_renderer.init(gameName, width, height);

	m_cpu = new CPU(&m_memory);

	std::ifstream stream("games/" + gameName, ios::in | ios::binary);
	std::vector<unsigned char> contents((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	int idx = 512;
	for (unsigned char content : contents) {
		m_memory.write(idx, content);
		idx++;
	}
}

void Chip8::decodeNext() {
	unsigned char instruction = m_memory.read(m_cpu->getPC());
}