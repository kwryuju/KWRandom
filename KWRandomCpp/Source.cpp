#include <iostream>
#include <random>

const int RANGE_MAX = 100;

int main() {
	//非決定的な乱数生成器
	std::random_device rnd_dev;
	std::cout << rnd_dev() << std::endl;

	//メルセンヌ・ツイスタ乱数生成器
	std::mt19937 mt(rnd_dev());
	std::cout << mt() << std::endl;

	//一様整数乱数(0～RANGE_MAX)
	std::uniform_int_distribution<> ui_rand(0, RANGE_MAX);
	std::cout << ui_rand(mt) << std::endl;

	//正規実数乱数(0.0～1.0)
	std::normal_distribution<> nr_rand(0.0, 1.0);
	std::cout << nr_rand(mt) << std::endl;

	return 0;
}