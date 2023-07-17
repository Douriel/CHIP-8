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
		cout << "File not found" << endl;
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
			m_cpu->LD_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 1:
			m_cpu->OR_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 2:
			m_cpu->AND_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 3:
			m_cpu->XOR_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 4:
			m_cpu->ADD_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 5:
			m_cpu->SUB_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 6:
			m_cpu->SHR_Vx(secondDigit);
			break;
		case 7:
			m_cpu->SUBN_Vx_Vy(secondDigit, thirdDigit);
			break;
		case 0xE: // Test with 14 if not working with 'E';
			break;
		default:
			cout << "Error: 8xy? instruction not found" << endl;
			break;
		}
		break;
	case 0x9:
		m_cpu->SNE_Vx_Vy(secondDigit, thirdDigit);
		break;
	case 0xA:
		m_cpu->LD_I_addr(secondAndThirdAndFourthDigit);
		break;
	case 0xB:
		m_cpu->JP_V0_addr(secondAndThirdAndFourthDigit);
		break;
	case 0xC:
		m_cpu->RND_Vx_byte(secondDigit, thirdAndFourthDigit);
		break;
	case 0xD:
		cout << "0xD not implemented" << endl;
		break;
	case 0xE:
		switch (thirdAndFourthDigit)
		{
		case 0x9E:
			cout << "0xEx9E not implemented" << endl;
			break;
		case 0xA1:
			cout << "0xExA1 not implemented" << endl;
			break;
		default:
			cout << "0xE??? unkown." << endl;
			break;
		}
		break;
	case 0xF:
		switch (thirdAndFourthDigit)
		{
		case 0x07:
			m_cpu->LD_Vx_DT(secondDigit);
			break;
		case 0x0A:
			cout << "0xFx0ANot implemented" << endl;
			break;
		case 0x15:
			cout << "0xFx15 Not implemented" << endl;
			break;
		case 0x18:
			
			break;
		case 0x1E:
			break;
		case 0x29:
			break;
		case 0x33:
			break;
		case 0x55:
			break;
		case 0x65:
			break;
		default:
			cout << "0xF??? unkown." << endl;
			break;
		}
		break;



	default:
		cout << "Instruction not implemented" << endl;
		break;
	}
}