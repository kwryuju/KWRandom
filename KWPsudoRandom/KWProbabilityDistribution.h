#pragma once
#include "KWPRNGBase.h"
#include <cmath>

static class KWProbabilityDistribution {
public:
	static double ExponentialInvertFuncMethod(double lambda, KWPRNGBase& random) {

		return -1.0 / lambda * log(1.0 - (random.next() / (double)(random.maxvalue())));

	}

	static double InvertFuncMethod(KWPRNGBase& random, double (*f)(double)) {
		return (*f)(random.next() / (double)(random.maxvalue()));
	}

	static double BoxMuller(KWPRNGBase& random, double mu = 0.0, double sigma = 1.0) {

		double x = random.next() / (double)(random.maxvalue());
		double y = random.next() / (double)(random.maxvalue());
		double z1 = sqrt(-2 * log(x)) * sin(2.0 * 3.1415926535897932384626433832795 * y);
		double z2 = sqrt(-2 * log(y)) * sin(2.0 * 3.1415926535897932384626433832795 * x);
		return z1 * sigma + mu;
	}

	static double CentralLimitTheorem(KWPRNGBase& random, double mu = 0.0, double sigma = 1.0) {

		double x = 0.0;
		for (size_t i = 0; i < 12; i++)
		{
			x += random.next() / (double)(random.maxvalue());
		}
		x -= 6;
		return x * sigma + mu;
	}
};