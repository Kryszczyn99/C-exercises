#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct student_t
{
	char *imie;
	char *nazwisko;
	int index;
};

struct student_t* read(int *err_code)
{
	char *wsk = (char *)calloc(100,sizeof(char));
	if (wsk == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		return NULL;
	}
	struct student_t *ptr = (struct student_t *)malloc(sizeof(struct student_t));
	if (ptr == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		free(wsk);
		return NULL;
	}
	int i=0;
	int przecinki=0;
	printf("Podaje dane: ");
	for(i=0;i<100;i++)
	{

		char znak;
		scanf("%c",&znak);
		if(znak=='\n' || isdigit(znak))
		{
			free(wsk);
			free(ptr);
			if(przecinki==0)
			{
				if (err_code != NULL) *err_code = 1;
				return NULL;
			}
			if (err_code != NULL) *err_code = 2;
			return NULL;
		}
		if(znak==',')
		{
			przecinki+=1;
			if(przecinki==2)
			{
				break;
			}
		}
		*(wsk+i)=znak;
	}
	*(wsk+i)='\0';
	int liczba;
	int y=scanf("%d",&liczba);
	if(y!=1)
	{
		if (err_code != NULL) *err_code = 3;
		free(wsk);
		free(ptr);
		return NULL;		
	}
	int pobrane1=0;
	int flaga=0;
	for(i=0;i<100;i++)
	{
		if(isalpha(*(wsk+i)))
		{
			flaga=1;
			pobrane1+=1;
		}
		else if(flaga==1 && !isalpha(*(wsk+i)))
		{
			pobrane1+=1;
			break;		 
		} 
	}
	if(flaga==0 || pobrane1==0)
	{
		if (err_code != NULL) *err_code = 1;
		free(wsk);
		free(ptr);
		return NULL;		
	}
	int pobrane2=0;
	flaga=0;
	for(;*(wsk+i)!=',';i++);
	for(;i<100;i++)
	{
		if(isalpha(*(wsk+i)))
		{
			flaga=1;
			pobrane2+=1;
		}
		else if(flaga==1 && !isalpha(*(wsk+i)))
		{
			int backup=i;
			int flag=0;
			for(;i<100;i++)
			{
				if(*(wsk+i)=='\0')
				{
					flag=1;
					break;
				}
				if(isalpha(*(wsk+i))) break;
			}
			if(flag==1)
			{
				pobrane2+=1;
				break;	
			}
			pobrane2+=1;
			i=backup;
		} 		
	}
	if(flaga==0 || pobrane1==0)
	{
		if (err_code != NULL) *err_code = 1;
		free(wsk);
		free(ptr);
		return NULL;		
	}
	char *tekst1=(char *)calloc(pobrane1,sizeof(char));
	if (tekst1 == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		free(wsk);
		free(ptr);
		return NULL;
	}	
	char *tekst2=(char *)calloc(pobrane2,sizeof(char));
	if (tekst2 == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		free(wsk);
		free(tekst1);
		free(ptr);
		return NULL;
	}
	flaga=0;
	int p=0;
	for(i=0;i<100;i++)
	{
		if(isalpha(*(wsk+i)))
		{
			flaga=1;
			*(tekst1+p)=*(wsk+i);
			p+=1;
		}
		else if(flaga==1 && !isalpha(*(wsk+i)))
		{
			break;		 
		} 		
	}
	*(tekst1+p)='\0';
	flaga=0;
	p=0;
	for(;*(wsk+i)!=',';i++);
	for(;i<100;i++)
	{
		if(isalpha(*(wsk+i)))
		{
			flaga=1;
			*(tekst2+p)=*(wsk+i);
			p+=1;
		}
		else if(flaga==1 && !isalpha(*(wsk+i)))
		{
			int backup=i;
			int flag=0;
			for(;i<100;i++)
			{
				if(*(wsk+i)=='\0') flag=1;
				if(isalpha(*(wsk+i))) break;
			}
			if(flag==1)
			{
				break;	
			}
			i=backup;
			*(tekst2+p)=*(wsk+i);
			p+=1;
		} 		
	}
	*(tekst2+p)='\0';
	ptr->imie=tekst1;
	ptr->nazwisko=tekst2;
	ptr->index=liczba;
	free(wsk);
	if (err_code != NULL) *err_code = 0;
	return ptr;
}

void destroy(struct student_t **s)
{
	if(s==NULL) return;
	free((*s)->imie);
	free((*s)->nazwisko);
	free(*s);
}
void show(const struct student_t* p)
{
	if(p==NULL) return;
	printf("%s %s, %d",p->imie,p->nazwisko,p->index);
}

int save_student_b(const struct student_t *s, const char *filename)
{
	if(s==NULL || s->imie==NULL || s->nazwisko==NULL || filename==NULL) return 1;
	FILE *f;
	f=fopen(filename,"wb");
	if(f==NULL) return 2;
	int len1=strlen(s->imie);
	int len2=strlen(s->nazwisko);
	fwrite(&len1,sizeof(int),1,f);
	fwrite(s->imie,sizeof(char),len1,f);
	fwrite(&len2,sizeof(int),1,f);
	fwrite(s->nazwisko,sizeof(char),len2,f);
	fwrite(&s->index,sizeof(int),1,f);
	fclose(f);
	return 0;
}

struct student_t* load_student_b(const char *filename, int *err_code)
{
	if(filename==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;
	}

	FILE *f;
	f=fopen(filename,"rb");
	if(f==NULL)
	{
		if(err_code!=NULL) *err_code=2;
		return NULL;
	}
	struct student_t *ptr = (struct student_t *)malloc(sizeof(struct student_t));
	if (ptr == NULL)
	{
		if (err_code != NULL) *err_code = 4;
		fclose(f);
		return NULL;
	}
	int g;
	int len1;
	g=fread(&len1,sizeof(int),1,f);
	if(g!=1 || len1<=0)
	{
		if(err_code!=NULL) *err_code=3;
		free(ptr);
		fclose(f);
		return NULL;		
	}
	char *ptr1=(char *)calloc(len1+1,sizeof(char));
	if(ptr1==NULL)
	{
		if(err_code!=NULL) *err_code=4;
		free(ptr);
		fclose(f);
		return NULL;			
	}
	fread(ptr1,len1,sizeof(char),f);
	int len2;
	g=fread(&len2,sizeof(int),1,f);
	if(g!=1 || len2<=0)
	{
		if(err_code!=NULL) *err_code=3;
		free(ptr);
		free(ptr1);
		fclose(f);
		return NULL;		
	}
	char *ptr2=(char *)calloc(len2+1,sizeof(char));
	if(ptr2==NULL)
	{
		if(err_code!=NULL) *err_code=4;
		free(ptr);
		free(ptr1);
		fclose(f);
		return NULL;			
	}
	fread(ptr2,len2,sizeof(char),f);
	int liczba;
	g=fread(&liczba,sizeof(int),1,f);	
	if(g!=1)
	{
		if(err_code!=NULL) *err_code=3;
		free(ptr);
		free(ptr1);
		free(ptr2);
		fclose(f);
		return NULL;			
	}
	ptr->imie=ptr1;
	ptr->nazwisko=ptr2;
	ptr->index=liczba;
	if(err_code!=NULL) *err_code=0;
	fclose(f);
	return ptr;
}

int main()
{
	printf("Co chcesz zrobic: ");
	char znak;
	scanf("%c",&znak);
	if(znak=='s' || znak=='S')
	{
		int c=getchar();
		while(c!='\n') c=getchar();
		struct student_t *value;
		int err_code;
		value = read(&err_code);
		if (err_code == 4) return printf("Failed to allocate memory"), 8;
		else if (err_code != 0) return printf("Incorrect input data"), 2;
		char *tablica=(char *)calloc(40,sizeof(char));
		if(tablica==NULL)
		{
			destroy(&value);
			return printf("Failed to allocate memory"),8;
		} 
		printf("Podaj plik: ");
		c=getchar();
		while(c!='\n') c=getchar();
		int i=0;
		while(1)
		{
			scanf("%c",&znak);
			if(znak=='\n') break;
			if(i==39) break;
			*(tablica+i)=znak;
			i++;
		}
		*(tablica+i)='\0';
		int g=save_student_b(value,tablica);
		if(g==1 || g==2)
		{
			destroy(&value);
			free(tablica);
			return printf("Couldn't create file"),5;
		} 
		printf("File saved");
		destroy(&value);
		free(tablica);
	}
	else if(znak=='l' || znak=='L')
	{
		int c=getchar();
		while(c!='\n') c=getchar();
		char *tablica=(char *)calloc(40,sizeof(char));
		if(tablica==NULL)
		{
			free(tablica);
			return printf("Failed to allocate memory"),8;
		} 
		printf("Podaj plik: ");
		int i=0;
		while(1)
		{
			scanf("%c",&znak);
			if(znak=='\n') break;
			if(i==39) break;
			*(tablica+i)=znak;
			i++;
		}
		*(tablica+i)='\0';
		int err_code;
		struct student_t *value=load_student_b(tablica,&err_code);
		if(err_code!=0) free(tablica);
		if(err_code==1) return printf("Incorrect input\n"),1;
		if(err_code==2) return printf("Couldn't open file"),4;
		if(err_code==3) return printf("File corrupted"),6;
		if(err_code==4) return printf("Failed to allocate memory"),8;
		free(tablica);
		show(value);
		destroy(&value);
	}
	else
	{
		return printf("Incorrect input"),1;
	}
	
	return 0;
}
