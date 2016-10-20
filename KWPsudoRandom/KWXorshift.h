#pragma once
#include "KWPRNGBase.h"

//32bitXorshiftによる乱数生成器
class KWXorshift32 : public KWPRNGBase
{
public:
	KWXorshift32() :
		KWPRNGBase() {
			Seed(123456789);
		}
	KWXorshift32(unsigned int a) :
		KWPRNGBase(a) { }

	~KWXorshift32() {};
	virtual unsigned int next() {
		x = x ^ (x << 13);
		x = x ^ (x >> 17);
		return x = x ^ (x << 5);
	}
	virtual unsigned int maxvalue() {
		return 0xffffffff; //周期と最大値の関係不明
	}
protected:
private:
};

//128bitXorshiftによる乱数生成器(rand()でシード生成)
class KWXorshift128 : public KWPRNGBase
{
public:
	KWXorshift128() :
		KWPRNGBase(),
		x(123456789),
		y(362436069),
		z(521288629),
		w(88675123) { }
	KWXorshift128(unsigned int a, unsigned int b, unsigned int c, unsigned int d) :
		KWPRNGBase(a),
		x(a),
		y(b),
		z(c),
		w(d) { }

	~KWXorshift128() {};
	virtual unsigned int next() {
		unsigned int t = x ^ (x << 11);
		x = y; y = z; z = w;
		return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
	}
	virtual unsigned int maxvalue() {
		return 0xffffffff; //周期と最大値の関係不明
	}
protected:
private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
	unsigned int w;
};