#pragma once
#include "Common.h"

class CPU
{
public:
	//Constructor and desctructor
	CPU();
	~CPU();

	//Methods I am not sure if I should implement here:
	void SYS_addr();
	void CLS();

	//Methods
	void RET();
	void JP_addr(uint16_t location);
	void CALL_addr();
	void SE_Vx_byte(unsigned char regIndex, uint8_t kk);
	void SNE_Vx_byte(unsigned char regIndex, uint8_t kk);
	void SE_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void LD_Vx_byte(unsigned char regIndex, uint8_t kk);
	void ADD_Vx_byte(unsigned char regIndex, uint8_t kk);
	void LD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void OR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void AND_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void XOR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void ADD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void SUB_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void SHR_Vx(unsigned char regIndex);
	void SUBN_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);



private:
	std::uint16_t PC = 512;
	std::uint16_t I = 0;
	std::uint8_t Vx[16];
	std::uint8_t VF = 15;
	std::uint8_t SP = 0;
	std::uint16_t stack[16];



	// Sound and delay timer
	std::uint16_t DT;
	std::uint16_t ST;
};





