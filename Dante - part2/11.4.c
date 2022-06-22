#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



int main (int argc, char** argv)
{
	int i=0;
	struct stack_t *stos;
	while(i<argc)
	{
		if(i==0)
		{
			i++;
			continue;
		}
		else
		{
			char *tekst=*(argv+i);
			int y=stack_load(&stos,tekst);
			switch(y)
			{
				case 3:
					{
						stack_destroy(&stos);
						return printf("Failed to allocate memory"),8;		
					}
				case 2:
					{
						printf("Couldn't open file ");
						int j=0;
						for(;*(tekst+j)!='\0';j++)
						{
							printf("%c",*(tekst+j));
						}
						printf("\n");
						i++;
						continue;
					}
				case 0:
					{
						int f=stack_save(stos,tekst);
						switch(f)
						{
							case 2:
								{
									stack_destroy(&stos);
									return printf("Couldn't create file"),5;
								}
							case 0:
								{
									printf("File ");
									int j=0;
									for(;*(tekst+j)!='\0';j++)
									{
										printf("%c",*(tekst+j));
									}
									printf(" saved\n");
								}
						}
					}
			}
			i++;
		}
		stack_destroy(&stos);
		
	}
	if(i==0 || i==1) return printf("Not enough arguments"),9;
	return 0;
}
