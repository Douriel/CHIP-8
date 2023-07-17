#include "CPU.h"


CPU::CPU(Memory* memory) {
	m_memory = memory;
}

uint16_t CPU::getPC() {
	return PC;
}

void CPU::DRW_Vx_Vy_nibble(unsigned char regIndex, unsigned char regIndexJ, uint8_t n, Renderer &m_renderer)
{

	for (int i = 0; i < n; i++) {
		m_memory->read(I);
		//SDL_RenderDrawPoint(m_renderer, regIndex, regIndexJ)
		I++, i++;
	}
}

// Should I send a pointer?
void CPU::CLS(Renderer &m_renderer)
{
	m_renderer.clear();
}

void CPU::RET() {
	PC = stack[SP];
	SP--;
}

void CPU::JP_addr(uint16_t location) {
	PC = location;
}

void CPU::CALL_addr(uint16_t instruction)
{
	SP++;
	stack[SP]= PC;
	PC = instruction;
}

//Unsigned char because there is only 16 registers
void CPU::SE_Vx_byte(unsigned char regIndex, uint8_t kk) {
	if (Vx[regIndex] == kk) { PC += 2; }
	incPC();
}

void CPU::SNE_Vx_byte(unsigned char regIndex, uint8_t kk) {
	if (Vx[regIndex] != kk) { PC += 2; }
	incPC();
}

void CPU::SE_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	if (Vx[regIndex] == Vx[regIndexJ]) { PC += 2; }
	incPC();
}

void CPU::LD_Vx_byte(unsigned char regIndex, uint8_t kk){
	Vx[regIndex] = kk;
	incPC();
}

void CPU::ADD_Vx_byte(unsigned char regIndex, uint8_t kk) {
	Vx[regIndex] += kk;
	incPC();
}

void CPU::LD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndexJ];
	incPC();
}

void CPU::OR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] || Vx[regIndexJ];
	incPC();
}

void CPU::AND_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] && Vx[regIndexJ];
	incPC();
}

void CPU::XOR_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	Vx[regIndex] = Vx[regIndex] ^ Vx[regIndexJ];
	incPC();
}

void CPU::ADD_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ) {
	uint16_t aux = Vx[regIndex] + Vx[regIndexJ]; //Double check behabior of this line, I am not sure if 'aux' will save 16bit or 8bit.
	Vx[VF] = (aux > 255) ? 1 : 0;
	Vx[regIndex] += Vx[regIndexJ];
	incPC();
}

void CPU::SUB_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ)
{
	Vx[VF] = (Vx[regIndex] > Vx[regIndex]) ? 1 : 0;
	Vx[regIndex] -= Vx[regIndexJ];
	incPC();
}

void CPU::SHR_Vx(unsigned char regIndex)
{
	bool lsb = Vx[regIndex] & 1;
	Vx[VF] = (lsb == 1) ? 1 : 0;
	Vx[regIndex] >>= 1;
	incPC();
}

void CPU::SUBN_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ)
{
	Vx[VF] = (Vx[regIndexJ] > Vx[regIndex]) ? 1 : 0;
	Vx[regIndex] = Vx[regIndexJ] - Vx[regIndex];
	incPC();
}

void CPU::SHL_Vx(unsigned char regIndex)
{
	bool msb = Vx[regIndex] & 0x08;
	Vx[VF] = (msb == 1) ? 1 : 0;
	Vx[regIndex] >>= 1;
	incPC();
}

void CPU::SNE_Vx_Vy(unsigned char regIndex, unsigned char regIndexJ)
{
	if (Vx[regIndex] == Vx[regIndexJ])PC += 2;
	incPC();
}

void CPU::LD_I_addr(uint16_t instruction)
{
	I = instruction;
	incPC();
}

void CPU::JP_V0_addr(uint16_t instruction)
{
	PC = instruction + Vx[0];
	incPC();
}

void CPU::RND_Vx_byte(unsigned char regIndex, uint8_t kk)
{
	Vx[regIndex] = (rand()% 255) & kk;
	incPC();
}

void CPU::LD_Vx_DT(unsigned char regIndex)
{
	Vx[regIndex] = DT;
	incPC();
}

void CPU::LD_DT_Vx(unsigned char regIndex)
{
	DT = Vx[regIndex];
	incPC();
}

void CPU::LD_ST_Vx(unsigned char regIndex)
{
	ST = Vx[regIndex];
	incPC();
}

void CPU::ADD_I_Vx(unsigned char regIndex)
{
	I += Vx[regIndex];
	incPC();
}

void CPU::LD_F_Vx(unsigned char regIndex)
{
	I = 5 * Vx[regIndex];
	incPC();
}

void CPU::LD_B_Vx(unsigned char regIndex)
{
	uint8_t value = Vx[regIndex];

	uint8_t hundreds = value / 100;
	uint8_t decimals = (value % 100) / 10;
	uint8_t ones = (value % 10);


	m_memory->write(I, hundreds);
	m_memory->write(I+1, decimals);
	m_memory->write(I+2, ones);

	incPC();
}

void CPU::LD_I_Vx(unsigned char regIndex)
{
	for (int i = 0; i < regIndex; i++) {
		m_memory->write(I, Vx[i]);
	}
	incPC();
}

void CPU::LD_Vx_I(unsigned char regIndex)
{
	for (int i = 0; i <= regIndex; i++) {
		Vx[i] = m_memory->read(I + 1);
	}
	incPC();
}