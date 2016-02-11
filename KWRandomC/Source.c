#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE_MAX 100

int main() {
	double real_val;
	int integer_val;

	/*シード値を現在時から設定*/
	srand((unsigned int)time(NULL));

	/*0.0から1.0の範囲の実数で乱数を生成*/
	real_val = rand() / (double)RAND_MAX;

	/*0からRANGE_MAX(=100)の範囲の整数で乱数を生成*/
	integer_val = rand() % (RANGE_MAX + 1);

	printf("%lf, %d\n", real_val, integer_val);

	return 0;
}