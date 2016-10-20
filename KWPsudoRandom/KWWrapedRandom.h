#pragma once
#include "KWPRNGBase.h"
#include <cstdlib>
#include <random>

//C言語におけるrand関数をラップ
class KWCRand : public KWPRNGBase
{
public:
	KWCRand() :
		KWPRNGBase() {
		srand(0);
	}
	KWCRand(unsigned int a) :
		KWPRNGBase(a) {
		srand(a);
	}

	~KWCRand() {};
	virtual unsigned int next() {
		return rand();
	}
	virtual unsigned int maxvalue() {
		return RAND_MAX;
	}
protected:
private:
};

//C++11におけるrandom_deviceをラップ
class KWCpp11DeviceRand : public KWPRNGBase
{
public:
	KWCpp11DeviceRand() :
		KWPRNGBase() {
	}

	~KWCpp11DeviceRand() {};
	virtual unsigned int next() {
		return rand();
	}
	virtual unsigned int maxvalue() {
		return rand.max();
	}
protected:
private:
	std::random_device rand;
};

//C++11におけるmt19937_32bitをラップ
class KWCpp11MT19937 : public KWPRNGBase
{
public:
	KWCpp11MT19937() :
		KWPRNGBase(),
		rand() {}
	KWCpp11MT19937(unsigned int a) :
		KWPRNGBase(a),
		rand(a) {}

	~KWCpp11MT19937() {};
	virtual unsigned int next() {
		return rand();
	}
	virtual unsigned int maxvalue() {
		return rand.max();
	}
protected:
private:
	std::mt19937 rand;
};