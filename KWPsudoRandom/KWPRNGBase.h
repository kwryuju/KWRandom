#pragma once

//�^������������(PRNG: Pseudorandom number generator)�̒��ۃN���X
class KWPRNGBase
{
public:
	//�R���X�g���N�^�F�V�[�h�l0�Ő������������
	KWPRNGBase() { Seed(0);; }
	//�R���X�g���N�^�F�����̃V�[�h�l�Ő������������
	KWPRNGBase(unsigned int x0) { Seed(x0); }
	
	virtual ~KWPRNGBase() {}
	virtual unsigned int next() = 0;
	virtual unsigned int maxvalue() = 0;

	void Seed(unsigned int x0) { x = x0; }
	unsigned int operator()() { return next(); }
protected:
	unsigned int x;
};