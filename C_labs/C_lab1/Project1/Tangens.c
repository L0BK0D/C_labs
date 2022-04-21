#include <stdio.h>
/*Функция возведения числа в степень*/
double RaiseToPow(double x, int power)
{
	double res;
	int i;
	res = 1.0;
	if (power == 0) {
		return 1;
	}
	else if (power == 1) {
		return x;
	}
	
	else 
		for (i = 1; i <= power; i++)
		{
		res = res * x;
		}
		return(res);
}
/* Функция нахождения факториала числа */
double fact(int k) {
	if (k < 2)
		return 1;
	return k * fact(k - 1);
}
/* Функция нахождения модуля числа */
double fabs(double x) {
	if (x > 0)
		return x;
	else return x * -1;
}
/* Функция нахождения синуса разложением в ряд Тейлора */
double sinus(double x) {
	int n;
	double sin;
	sin = 0.0;
	for (n = 1; n <= 18; n++) 
	{
		sin = sin + (RaiseToPow(-1, n-1) * RaiseToPow(x, (2*n-1)) / fact(2*n-1)); 
	}
		
	return(sin);
}
/*Функция для проверки точности вычисления синуса*/
int test_sin() {
	int r;
	r = 0;
	
	r = r || (fabs(sinus(0) - 0.0) >= 0.0001);
	r = r || (fabs(sinus(1) - 0.8415) >= 0.0001);
	r = r || (fabs(sinus(2) - 0.9093) >= 0.0001);
	r = r || (fabs(sinus(4) + 0.7568) >= 0.0001);
	r = r || (fabs(sinus(10) + 0.5440) >= 0.0001);
	return r;
}
/* Функция нахождения косинуса разложением в ряд Тейлора */
double cosinus(double x) {
	int n;
	double cos;
	cos = 1.0;
	for (n = 1; n <= 18; n++) {
		cos = cos + (RaiseToPow(-1, n) * RaiseToPow(x, (2 * n)) / fact(2 * n));
	}
	return cos;
}

/*Функция для проверки точности вычисления косинуса*/
int test_cos() {
	int r;
	r = 0;

	r = r || (fabs(cosinus(0) - 1.0) >= 0.0001);
	r = r || (fabs(cosinus(1) - 0.5403) >= 0.0001);
	r = r || (fabs(cosinus(2.5) + 0.8011) >= 0.0001);
	r = r || (fabs(cosinus(5) - 0.2837) >= 0.0001);
	r = r || (fabs(cosinus(10) + 0.8391) >= 0.0001);
	return r;
}
/*Функция для вычисления тангенса путем деления синус на косинус*/
double tangens(double x) {
	return sinus(x) / cosinus(x);
}

/*Функция для проверки точности вычисления косинуса*/
int test_tan() {
	int r;
	r = 0;

	r = r || (fabs(tangens(0) - 0.0) >= 0.0001);
	r = r || (fabs(tangens(1) - 1.5574) >= 0.0001);
	r = r || (fabs(tangens(2.5) + 0.7470) >= 0.0001);
	r = r || (fabs(tangens(-4) + 1.1578) >= 0.0001);
	r = r || (fabs(tangens(10) - 0.6484) >= 0.0001);
	return r;
}



int main(int argc, char** argv) {
	//return test_sin();
	//return test_cos();
	return test_tan();
}