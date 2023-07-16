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
	if(!stream.is_open()){ 
		cout << "File not found";
	}
	std::vector<unsigned char> contents((std::istreambuf_iterator<char>(stream)), std::istreambuf_iterator<char>());

	int idx = 512;
	for (unsigned char content : contents) {
		m_memory.write(idx, content);
		idx++;
	}
}

void Chip8::decodeNext() {
	unsigned char instruction = m_memory.read(m_cpu->getPC());
	instruction = (instruction << 8) | m_memory.read(m_cpu->getPC()+1);


	std::cout << std::hex << (int)instruction;
	
	unsigned char firstDigit = (instruction & 0xF000) >> 12;
	unsigned char secondDigit = (instruction & 0x0F00) >> 8;
	unsigned char thirdDigit = (instruction & 0x00F0) >> 4;
	unsigned char fouthDigit = (instruction & 0x000F);
	unsigned char secondAndThirdDigit = (instruction & 0x0FF0) >> 4;
	unsigned char thirdAndFourthDigit = (instruction & 0x00FF);
	uint_least16_t secondAndThirdAndFourthDigit = (instruction & 0x0FFF);



	std::cout << std::hex << (int)firstDigit;


	switch (firstDigit)
	{
	case 0x0:
		switch (thirdAndFourthDigit)
		{
		case 0xE0:
			break;
		case 0xEE:
			break;
		default:
			break;
		}
		break;
	case 0x1:
		m_cpu->JP_addr(secondAndThirdAndFourthDigit);
		break;
	case 0x2:
		m_cpu->CALL_addr(secondAndThirdAndFourthDigit);
		break;
	case 0x3:
		m_cpu->SE_Vx_byte(secondDigit, thirdAndFourthDigit);
		break;
	case 0x4:
		m_cpu->SNE_Vx_byte(secondDigit, thirdAndFourthDigit);
		break;
	case 0x5:
		m_cpu->SE_Vx_Vy(secondDigit, thirdDigit);
		break;
	case 0x6:
		m_cpu->LD_Vx_byte(secondDigit, thirdAndFourthDigit);
		break;
	case 0x7:
		m_cpu->ADD_Vx_byte(secondDigit, thirdAndFourthDigit);
		break;
	case 0x8:
		switch (fouthDigit)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 14:
			break;
		default:
			cout << "Error: 8xy? instruction not found";
			break;
		}
		break;
	case 0x9:
		break;
	case 0xA:
		break;
	case 0xB:
		break;
	case 0xC:
		break;
	default:
		break;
	}
}