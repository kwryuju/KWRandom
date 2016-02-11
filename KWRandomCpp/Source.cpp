#include <iostream>
#include <random>

const int RANGE_MAX = 100;

int main() {
	//�񌈒�I�ȗ���������
	std::random_device rnd_dev;
	std::cout << rnd_dev() << std::endl;

	//�����Z���k�E�c�C�X�^����������
	std::mt19937 mt(rnd_dev());
	std::cout << mt() << std::endl;

	//������l���z(0�`RANGE_MAX)
	std::uniform_int_distribution<> ui_rand(0, RANGE_MAX);
	std::cout << ui_rand(mt) << std::endl;

	//�������K���z(0.0�`1.0)
	std::normal_distribution<> nr_rand(0.0, 1.0);
	std::cout << nr_rand(mt) << std::endl;

	return 0;
}