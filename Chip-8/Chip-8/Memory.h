#pragma once
#include "Common.h"
class Memory
{
public:
	Memory();
	~Memory();

	void write(std::uint16_t address, std::uint8_t value);
	std::uint8_t read(std::uint16_t address);
	std::uint8_t* getRAM();

private:
	std::uint8_t RAM[4096];
	int idx = 0;
};

