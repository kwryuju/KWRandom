#pragma once
#include "KWPRNGBase.h"

//üŒ`‡“¯–@‚É‚æ‚é—”¶¬Ší(LCG : Linear Congruential Genarator)
class KWLCG : public KWPRNGBase
{
public:
	KWLCG() : 
		KWPRNGBase(),
		//prameters from glibc
		A(65539),
		C(0),
		M(2147483648u) { }
	KWLCG(unsigned int a) :
		KWPRNGBase(a),
		//prameters from glibc
		A(65539),
		C(0),
		M(2147483648u) { }

	~KWLCG() {};
	virtual unsigned int next() {
		return x = (x * A + C) % M;
	}
	virtual unsigned int maxvalue() {
		return M - 1;
	}
protected:
private:
	const unsigned int A;
	const unsigned int C;
	const unsigned int M;
};