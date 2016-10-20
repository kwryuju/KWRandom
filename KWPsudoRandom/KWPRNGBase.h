#pragma once

//疑似乱数生成器(PRNG: Pseudorandom number generator)の抽象クラス
class KWPRNGBase
{
public:
	//コンストラクタ：シード値0で生成器を初期化
	KWPRNGBase() { Seed(0);; }
	//コンストラクタ：引数のシード値で生成器を初期化
	KWPRNGBase(unsigned int x0) { Seed(x0); }
	
	virtual ~KWPRNGBase() {}
	virtual unsigned int next() = 0;
	virtual unsigned int maxvalue() = 0;

	void Seed(unsigned int x0) { x = x0; }
	unsigned int operator()() { return next(); }
protected:
	unsigned int x;
};