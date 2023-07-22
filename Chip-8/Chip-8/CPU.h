#pragma once
#include "Common.h"
#include "Memory.h"
#include "Renderer.h"


class CPU
{
public:
	//Constructor and desctructor
	CPU(Memory *memory);
	~CPU();
	void incPC() { PC += 2; }

	uint16_t getPC();

	//Methods I am not sure if I should implement here:
	//void SYS_addr();

	void DRW_Vx_Vy_nibble(unsigned char regIndex, unsigned char regIndexJ, uint8_t k, uint32_t video[]);
	//void SKP_Vx();
	//void SKNP_Vx();
	//void LD_Vx_K();


	//Methods

	void CLS(uint32_t *video);
	void RET();
	void JP_addr(uint16_t location);
	void CALL_addr(uint16_t instruction);
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
	void SHL_Vx(unsigned char regIndex);
	void SNE_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ);
	void LD_I_addr(uint16_t instruction);
	void JP_V0_addr(uint16_t instruction);
	void RND_Vx_byte(unsigned char regIndex, uint8_t kk);
	void LD_Vx_DT(unsigned char regIndex);
	void LD_DT_Vx(unsigned char regIndex);
	void LD_ST_Vx(unsigned char regIndex);
	void ADD_I_Vx(unsigned char regIndex);
	void LD_F_Vx(unsigned char regIndex);
	void LD_B_Vx(unsigned char regIndex);  
	void LD_I_Vx(unsigned char regIndex);
	void LD_Vx_I(unsigned char regIndex);

private:
	std::uint16_t PC = 512;
	std::uint16_t I = 0;
	std::uint8_t Vx[16];
	std::uint8_t VF = 15;
	std::uint8_t SP = 0;
	std::uint16_t stack[16];

	Memory* m_memory;

	// Sound and delay timer
	std::uint16_t DT;
	std::uint16_t ST;
};





