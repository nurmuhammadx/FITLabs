#include <iostream>
#include <stdio.h>
#include <math.h>
#include <locale.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int v;
	printf("Выбирите 1, если хотите перевести из 10 СС в 8 СС.");
	printf("\nВыбирите 2, если хотите перевести число с плавающей запятой в еговнутреннее представление.");
	printf("\nВаш выбор: ");
	scanf_s("%d", &v);
	if (v == 1)
	{
		int x;
		int result = 0;
		int stp = 0;
		printf("Введите число: ");
		scanf_s("%d", &x);
		while (x > 0)
		{
			result += x % 8 * pow(10, stp++);
			x /= 8;
		}
		printf("\nРезультат в восьмеричной системе: %d", result);
	}
	else if (v == 2)
	{
		double n;
		cout << "Введите число: ";
		scanf_s("%lF", &n);
		bool neg = n < 0;
		if (neg) n = -n;
		string str = "";
		//перевод целой
		int d = (int)n;
		while (d > 0)
		{
			str = char('0'+ d % 2) + str;
			d /= 2;
		}
		cout << str << endl;
		//перевод дробной части
		double f = n - (int)n;
		str += ".";
		for (int i = 40; i > 0; i--)
		{
			f *= 2;
			str += char((int)f + '0');
			f -= (int)f;
		}

		int dot = str.find_first_of('.');
		int firstOne = str.find_first_of('1');

		int order = (dot - firstOne - 1) + 1023;
		string binstr = " ";
		while (order > 0)
		{
			binstr = char('0' + order % 2) + binstr;
			order /= 2;
		}

		string result = "";
		//знак
		if (neg) result = "1 " + result;
		else result = "0 " + result;
		//порядок
		result += binstr;

		//мантиса
		for (int i = firstOne + 1; i < str.length(); i++)
		{ 
			if (str[i] != '.')
				result += str[i];
		}

		cout << "Число с плавающей запятой в его внутреннем представлении:\n" << endl;
		for (int i = 0; i < result.length(); i++)
		{
			cout << result[i];
		}
	}
	
	printf("\n");
	return 0;
}