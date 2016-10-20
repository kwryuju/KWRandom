#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "KWWrapedRandom.h"
#include "KWLCG.h"
#include "KWLFSR.h"
#include "KWXorshift.h"
#include "KWProbabilityDistribution.h"

const int LOOPS(10000);


int main() {

	double* buffer = new double[LOOPS];
		
	std::random_device rnd_dev; //�������p

	//�e�퐶����̏�����
	const int NUM = 7;
	KWPRNGBase* PRNGs[NUM] = {
		new KWCRand(rnd_dev()),
		new KWCpp11DeviceRand(),
		new KWCpp11MT19937(rnd_dev()),
		new KWLCG(rnd_dev()),
		new KWLFSR(rnd_dev()),
		new KWXorshift32(rnd_dev()),
		new KWXorshift128(rnd_dev(), rnd_dev(), rnd_dev(), rnd_dev()),
	};
	//�t�@�C�����p
	std::string method_name[] = {
		"crand",
		"devrand",
		"mt19937",
		"LCG",
		"LFSR",
		"XOR32",
		"XOR128",
	};
	std::string ext = ".txt";

	for (int methodnum = 0; methodnum < NUM; methodnum++)
	{
		KWPRNGBase* rnd = PRNGs[methodnum];

		//���Ԍv�����Ȃ��痐���񐶐�
		auto start = std::chrono::system_clock::now();
		for (int i = 0; i < LOOPS; i++)
		{
			buffer[i] = (*rnd)() / (double)(rnd->maxvalue());

			//buffer[i] = KWProbabilityDistribution::ExponentialInvertFuncMethod(5.0, (*rnd));
			//buffer[i] = KWProbabilityDistribution::InvertFuncMethod((*rnd), [](double s){
			//	return 0.2 + (0.8 - 0.2) * s;
			//});

			//buffer[i] = KWProbabilityDistribution::BoxMuller(*rnd);
			//buffer[i] = KWProbabilityDistribution::CentralLimitTheorem(*rnd);
		}
		auto end = std::chrono::system_clock::now();
		auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();


		//1�����ŏ����o��
		std::string name = "result1D_";
		std::ofstream ofs(name + method_name[methodnum] + ext);
		ofs << "#" << LOOPS << " loops: " << dur << "msec" << std::endl;
		for (int i = 0; i < LOOPS; i++)
		{
			ofs << buffer[i] << std::endl;
		}
		ofs.close();

		//2�����ŏ����o��
		name = "result2D_";
		ofs.open(name + method_name[methodnum] + ext);
		for (int i = 0; i < LOOPS; i += 2)
		{
			ofs << buffer[i + 0] << " " << buffer[i + 1] << std::endl;
		}
		ofs.close();

		//3�����ŏ����o��
		name = "result3D_";
		ofs.open(name + method_name[methodnum] + ext);
		for (int i = 0; i < LOOPS; i += 3)
		{
			ofs << buffer[i + 0] << " " << buffer[i + 1] << " " << buffer[i + 2] << std::endl;
		}
		ofs.close();
	}

	//�������
	delete buffer;
	for (size_t i = 0; i < NUM; i++)
	{
		delete PRNGs[i];
	}
	return 0;
}