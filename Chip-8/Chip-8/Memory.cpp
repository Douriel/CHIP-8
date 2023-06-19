#include "Memory.h"

Memory::Memory() {
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;

	// 1
	RAM[idx++] = 0x20;
	RAM[idx++] = 0x60;
	RAM[idx++] = 0x20;
	RAM[idx++] = 0x20;
	RAM[idx++] = 0x70;

	// 2
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;

	// 3
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0xF0;

	// 4
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0x10;

	// 5
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0xF0;

	// 6
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;

	// 7 
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0x20;
	RAM[idx++] = 0x40;
	RAM[idx++] = 0x40;

	// 8
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;

	// 9
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x10;
	RAM[idx++] = 0xF0;

	// A
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;

	// B
	RAM[idx++] = 0xE0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xE0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xE0;

	// C
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;

	// D
	RAM[idx++] = 0xE0;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0x90;
	RAM[idx++] = 0xE0;

	// E
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;

	// F
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0xF0;
	RAM[idx++] = 0x80;
	RAM[idx++] = 0x80;
}

void Memory::write(std::uint16_t I, std::uint8_t value) {
	RAM[I] = value;
}

std::uint8_t Memory::read(std::uint16_t I)
{
	return RAM[I];
}

std::uint8_t* Memory::getRAM() {
	return RAM;
}