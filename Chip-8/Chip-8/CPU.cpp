#include "CPU.h"

void CPU::RET() {
	PC = stack[SP];
	SP--;
}

void CPU::JP_addr(uint16_t location) {
	PC = location;
}

void CPU::CALL_addr() {
	SP++;
	PC = stack[SP];
}

//Unsigned char because there is only 16 registers
void CPU::SE_Vx_byte(unsigned char regIndex, uint8_t kk) {
	if (Vx[regIndex] == kk) { PC += 2; }
}

void CPU::SNE_Vx_byte(unsigned char regIndex, uint8_t kk) {
	if (Vx[regIndex] != kk) { PC += 2; }
}

void CPU::SE_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	if (Vx[regIndex] == Vx[regIndexJ]) { PC += 2; }
}

void CPU::LD_Vx_byte(unsigned char regIndex, uint8_t kk){
	Vx[regIndex] = kk;
}

void CPU::ADD_Vx_byte(unsigned char regIndex, uint8_t kk) {
	Vx[regIndex] += kk;
}

void CPU::LD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndexJ];
}

void CPU::OR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] || Vx[regIndexJ];
}

void CPU::AND_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] && Vx[regIndexJ];
}

void CPU::XOR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] ^ Vx[regIndexJ];
}

void CPU::ADD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	uint16_t aux = Vx[regIndex] + Vx[regIndexJ]; //Double check behabior of this line, I am not sure if 'aux' will save 16bit or 8bit.
	Vx[VF] = (aux > 255) ? 1 : 0;
	Vx[regIndex] += Vx[regIndexJ];
}

void CPU::SUB_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ)
{
	Vx[VF] = (Vx[regIndex] > Vx[regIndex]) ? 1 : 0;
	Vx[regIndex] -= Vx[regIndexJ];
}

void CPU::SHR_Vx(unsigned char regIndex)
{
	uint8_t lsb = Vx[regIndex] & 1;
	Vx[VF] = (lsb == 1) ? 1 : 0;
	Vx[regIndex] >>= 1;
}

void CPU::SUBN_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ)
{
	Vx[VF] = (Vx[regIndexJ] > Vx[regIndex]) ? 1 : 0;
	Vx[regIndex] = Vx[regIndexJ] - Vx[regIndex];
}




