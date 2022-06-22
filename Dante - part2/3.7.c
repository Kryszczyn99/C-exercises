#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	
	/*for (int i = 0; i < 100; i++)
	{
		char snumber[10];
		_itoa(i, snumber, 10);

		char filename[20];
		strcpy(filename, "test");
		strcat(filename, snumber);     // zapisywanie dłużej trochę niż ta niżej.
		strcat(filename, ".txt");

		FILE* file = fopen(filename, "wt");
		fprintf(file, "%d ", i);
		fclose(file);
	}*/

	 /*for (int i = 0; i < 100; i++)
	{
		char filename[20];
		sprintf(filename, "test%d.txt", i);

		FILE* file = fopen(filename, "wt");    // wersja szbysza 
		fprintf(file, "%d ", i);
		fclose(file);
	} */
	// Napisz program który do pliku zapisuje teksty podane przez użytkownika będą różne od samego znaku enter.

	// fclose(file); // zamyka program  = podajemy w () uchwyt do pliku.
