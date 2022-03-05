#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <WinUser.h>
#include <locale.h>
#define n 4

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int key[n][n] = {{0,0,1,0},
					 {0,0,0,1},
					 {0,1,0,0},
			         {1,0,0,0}};
	int k = 0;
	char matrixShifr[n][n];
	char shifr[17];
	char ras_shifr[17];
	char* str;
	printf("Введите текст которое хотите зашифровать(16): ");
	str = (char*)malloc(17);
	fgets(str, 17, stdin);
	OemToCharA(str, str);
	printf("\n");
	
	for (int i = 0; i < 17; i++)
		if (str[i] == ' ')
			str[i] = '$';

	for (int i = 0; i < n; i++)
	{
		if (k < 4)
		{
			for (int j = 0; j < n; j++)
				if (key[i][j] == 1)
					matrixShifr[i][j] = str[k];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 8)
		{
			for (int j = 0; j < n; j++)
				if (key[n-j-1][i] == 1)
					matrixShifr[i][j] = str[k];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 12)
		{
			for (int j = 0; j < n; j++)
				if (key[n - i - 1][n - j - 1] == 1)
					matrixShifr[i][j] = str[k];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 16)
		{
			for (int j = 0; j < n; j++)
				if (key[j][n - i - 1] == 1)
					matrixShifr[i][j] = str[k];
		}
		k++;
	}

	k = 0;
	printf("Матричный вид зашифрованого текста:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c ", matrixShifr[i][j]);
			shifr[k++] = matrixShifr[i][j];
		}
		printf("\n");
	}
	printf("\nЗашифрованный текст: ");
	for (int i = 0; i < k; i++)
		printf("%c", shifr[i]);
	printf("\n");
	free(str);
	//----------------------------РАСШИФРОВКА------------------------------------
	k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			if (matrixShifr[i][j] == '$')
				matrixShifr[i][j] = ' ';
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 4)
		{
			for (int j = 0; j < n; j++)
				if (key[i][j] == 1)
					ras_shifr[k] = matrixShifr[i][j];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 8)
		{
			for (int j = 0; j < n; j++)
				if (key[n - j - 1][i] == 1)
					ras_shifr[k] = matrixShifr[i][j];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 12)
		{
			for (int j = 0; j < n; j++)
				if (key[n - i - 1][n - j - 1] == 1)
					ras_shifr[k] = matrixShifr[i][j];
		}
		k++;
	}
	for (int i = 0; i < n; i++)
	{
		if (k < 16)
		{
			for (int j = 0; j < n; j++)
				if (key[j][n - i - 1] == 1)
					ras_shifr[k] = matrixShifr[i][j];
		}
		k++;
	}

	printf("\nРасшифрованный текст: ");
	for (int i = 0; i < k; i++)
		printf("%c", ras_shifr[i]);
	

	printf("\n");
	return 0;
}