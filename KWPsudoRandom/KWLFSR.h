#pragma once
#include "KWPRNGBase.h"
#include <stdlib.h>

//ガロア線形帰還シフトレジスタによる乱数生成器(LFSR : Linear-Feedack Shift Register)
class KWLFSR : public KWPRNGBase
{
public:
	KWLFSR() :
		KWPRNGBase(),
		REGITSIZE(521) {
		init();
	}
	KWLFSR(unsigned int a) :
		KWPRNGBase(a),
		REGITSIZE(521) {
		srand(a);
		init();
	}

	~KWLFSR() {
		delete regs;
	};

	virtual unsigned int next() {
		if (++x >= REGITSIZE) {
			GFSR();
			x = 0;
		}
		return regs[x];
	}
	virtual unsigned int maxvalue() {
		return 0xffffffff;
	}
protected:
private:
	const int REGITSIZE;
	unsigned int* regs;

	void GFSR() {
		int i;
		for (i = 0; i < 32; i++)
			regs[i] ^= regs[i + 489];
		for (i = 32; i < REGITSIZE; i++)
			regs[i] ^= regs[i - 32];
	}

	void init() {
		regs = new unsigned int[REGITSIZE];

		for (size_t i = 0; i <= 16; i++)
		{
			for (size_t j = 0; j < 31; j++) {
				rand();
			}
			regs[i] = rand();
		}
		regs[16] = (regs[16] << 23) ^ (regs[0] >> 9) ^ regs[15];
		for (size_t i = 17; i < REGITSIZE; i++)
			regs[i] = (regs[i - 17] << 23) ^ (regs[i - 16] >> 9) ^ regs[i - 1];
		GFSR(); GFSR(); GFSR();
		x = 520;
	}
};