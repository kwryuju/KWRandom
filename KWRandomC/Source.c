#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_MAX 100

int main() {
	double real_val;
	int integer_val;

	/*�V�[�h�l�����ݎ�����ݒ�*/
	srand((unsigned int)time(NULL));

	/*0.0����1.0�͈̔͂̎����ŗ����𐶐�*/
	real_val = rand() / (double)RAND_MAX;

	/*0����RANGE_MAX(=100)�͈̔͂̐����ŗ����𐶐�*/
	integer_val = rand() % (RANGE_MAX + 1);

	printf("%lf, %d\n", real_val, integer_val);

	return 0;
}