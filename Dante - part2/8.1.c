#include <stdio.h>

int add_int(int a,int b)
{
	return a + b;	
} 
int sub_int(int a,int b) 
{
	return a - b;
}

int div_int(int a,int b) 
{
	return a / b;
}

int mul_int(int a,int b) 
{
	return a * b;
}


int calculate(int a,int b, const char* pointer)
{
	return (pointer)(a,b);
}


int main()
{
	
}
