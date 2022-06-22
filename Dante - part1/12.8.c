#include <stdio.h>

int main ()
{
	printf("Podaj N:  ");
	int N;
	int y = scanf("%d",&N);
	if(y!=1)
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(N<10 || N>1000000)
	{
		printf("Incorrect input\n");
		return 0;
	}
	if(N<=10)
	{
		printf("Nothing to show\n");
		return 0;
	}
	if(N>10 && N<100)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>=10;i--)
		{
			for(j=1;j<10;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N>108 && N<1000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>=100;i--)
		{
			for(j=10;j<100;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N>=1100 && N<10000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>=1000;i--)
		{
			for(j=100;j<1000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N>=11000 && N<100000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>=10000;i--)
		{
			for(j=1000;j<10000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N>=110000 && N<1000000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>=100000;i--)
		{
			for(j=10000;j<100000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N==100)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>90;i--)
		{
			for(j=1;j<10;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
	}
	if(N==1000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>900;i--)
		{
			for(j=10;j<100;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
	}
	if(N==10000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>9000;i--)
		{
			for(j=100;j<1000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
	}
	if(N==100000)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=N-1;i>90000;i--)
		{
			for(j=1000;j<10000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
	}
	if(N>100 && N<=108)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=99;i>90;i--)
		{
			for(j=1;j<10;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		
	}
	if(N==1099)
		{
			printf("Nothing to show\n");
			return 0;
		}
	if(N>1000 && N<1099)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=999;i>=900;i--)
		{
			for(j=10;j<100;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N==10999)
		{
			printf("Nothing to show\n");
			return 0;
		}
	if(N>10000 && N<10999)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=9999;i>=9000;i--)
		{
			for(j=100;j<1000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	if(N>100000 && N<109990)
	{
		int ilosc=0;
		int i;
		int j;
		for(i=99099;i>=90000;i--)
		{
			for(j=1000;j<10000;j++)
			{
				if(i+j==N)
				{
					printf("%d + %d = %d\n",i,j,N);
					ilosc+=1;
				}
			}
		}
		if(ilosc==0)
		{
			printf("Nothing to show\n");
			return 0;
		}
	}
	return 0;

}
