#include <stdio.h>
#include <stdlib.h>
#include "stack3.h"

int main()
{
	struct stack_t *wsk;
	int g = stack_init(&wsk);
	if (g == 2) return printf("Failed to allocate memory"), 8;
	int flaga_dig = 0;
	int flaga_next = 0;
	int flaga_div = 0;
	printf("Podaj wyrazenie: ");
	while (1)
	{
		char znak;
		scanf("%c", &znak);
		if (znak == '\n') break;
		if (znak >= '0' && znak <= '9') flaga_dig = 1;
		else if (znak != '-' && znak != '/' && znak != '*' && znak != '+' && znak != ' ')
		{
			stack_destroy(&wsk);
			return printf("Incorrect input"), 1;
		}
		if (flaga_dig == 1)
		{
			ungetc(znak, stdin);
			double number;
			int y = scanf("%lf", &number);
			if (y != 1)
			{
				stack_destroy(&wsk);
				return printf("Incorrect input"), 1;
			}
			int p = stack_push(wsk, number);
			if (p != 0)
			{
				stack_destroy(&wsk);
				return printf("Failed to allocate memory"), 8;
			}
		}
		else if (znak == '-')
		{
			char znak2;
			scanf("%c", &znak2);
			if (znak2 >= '0' && znak2 <= '9')
			{
				ungetc(znak2, stdin);
				ungetc(znak, stdin);
				double number;
				int y = scanf("%lf", &number);
				if (y != 1)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				int p = stack_push(wsk, number);
				if (p != 0)
				{
					stack_destroy(&wsk);
					return printf("Failed to allocate memory"), 8;
				}
				flaga_div = 1;
			}
			else
			{
				ungetc(znak2, stdin);
				flaga_next = 1;
			}
		}
		if (flaga_next == 1 || ((znak == '-' || znak == '+' || znak == '*' || znak == '/') && flaga_div==0))
		{
			int size = stack_size(wsk);
			if (size <= 1)
			{
				stack_destroy(&wsk);
				return printf("Incorrect expression"), 2;
			}
			if (znak == '-')
			{
				int err_code;
				double l2 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				double l1 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				int wynik = stack_push(wsk, l1 - l2);
				if (wynik != 0)
				{
					stack_destroy(&wsk);
					return printf("Failed to allocate memory"), 8;
				}
			}
			else if (znak == '+')
			{
				int err_code;
				double l2 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				double l1 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				int wynik = stack_push(wsk, l1 + l2);
				if (wynik != 0)
				{
					stack_destroy(&wsk);
					return printf("Failed to allocate memory"), 8;
				}
			}
			else if (znak == '/')
			{
				int err_code;
				double l2 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				double l1 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				int wynik = stack_push(wsk, l1 / l2);
				if (wynik != 0)
				{
					stack_destroy(&wsk);
					return printf("Failed to allocate memory"), 8;
				}
			}
			else if (znak == '*')
			{
				int err_code;
				double l2 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				double l1 = stack_pop(wsk, &err_code);
				if (err_code != 0)
				{
					stack_destroy(&wsk);
					return printf("Incorrect input"), 1;
				}
				int wynik = stack_push(wsk, l1*l2);
				if (wynik != 0)
				{
					stack_destroy(&wsk);
					return printf("Failed to allocate memory"), 8;
				}
			}
		}
		flaga_div = 0;
		flaga_next = 0;
		flaga_dig = 0;
	}
	int rozmiarek=stack_size(wsk);
	if(rozmiarek!=1)
	{
		printf("Incorrect expression");
		stack_destroy(&wsk);
		return 2;
	}
	printf("%lf\n", wsk->head->data);
	stack_destroy(&wsk);
	return 0;
}

