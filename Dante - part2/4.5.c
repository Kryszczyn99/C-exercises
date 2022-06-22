#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct student_t
{
	char name[20];
	char surname[40];
	int index;
	char field[50];
	char faculty[80];
	int year;
};
/**************************************************/
void display_name(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Student name: %s\n", student->name);
}
void display_surname(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Student surname: %s\n", student->surname);
}
void display_index(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Index: %d\n", student->index);
}
void display_field(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Field: %s\n", student->field);
}
void display_faculty(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Faculty: %s\n", student->faculty);
}
void display_year(const struct student_t* student)
{
	if (student == NULL) return;
	printf("Year: %d\n", student->year);
}
/**************************************************/


int save_student_t(const char *filename, const struct student_t* s);
int load_student_t(const char *filename, struct student_t* s);
int save_student_b(const char *filename, const struct student_t* s);
int load_student_b(const char *filename, struct student_t* s);

struct student_t* set(struct student_t* student, const char * name,
	const char * surname, int index,
	const char * field, const char * faculty,
	int year, int *err_code)
{
	if (student == NULL || name == NULL || surname == NULL || field == NULL || faculty == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	const char *check;
	check=name;
	int len=0;
	for(;*check!='\0';check++) len++;
	if(len>=20) 
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	check=surname;
	len=0;
	for(;*check!='\0';check++) len++;
	if(len>=40) 
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	check=field;
	len=0;
	for(;*check!='\0';check++) len++;
	if(len>=50) 
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	check=faculty;
	len=0;
	for(;*check!='\0';check++) len++;
	if(len>=80) 
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	
	
	const char *wsk = name;
	char *wsk2 = (student->name);
	for (; *wsk != '\0'; wsk++, wsk2++) *wsk2 = *wsk;
	*wsk2 = '\0';
	wsk = surname;
	wsk2 = (student->surname);
	for (; *wsk != '\0'; wsk++, wsk2++) *wsk2 = *wsk;
	*wsk2 = '\0';
	(student->index) = index;

	wsk = field;
	wsk2 = (student->field);
	for (; *wsk != '\0'; wsk++, wsk2++) *wsk2 = *wsk;
	*wsk2 = '\0';
	wsk = faculty;
	wsk2 = (student->faculty);
	for (; *wsk != '\0'; wsk++, wsk2++) *wsk2 = *wsk;
	*wsk2 = '\0';
	(student->year) = year;

	if (err_code != NULL) *err_code = 0;
	return student;
}
/**************************************************/

struct student_t* read(struct student_t* p, int *err_code)
{
	if (p == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	int i;
	char *ptr;
	char znak;
	int k=0;
	int pobrane = 0;
	int czy_litera = 0;
/*************************************************/
	char tablica1[20];
	ptr = tablica1;
	for (i = 0; i < 20; i++)
	{
		scanf("%c", &znak);
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 1;
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	scanf("%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 2;
		return NULL;
	}
	/***************************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica2[40];
	ptr = tablica2;
	for (i = 0; i < 40; i++)
	{
		scanf("%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 2;
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 2;
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 2;
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 2;
		return NULL;
	}
	scanf("%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 2;
		return NULL;
	}
	/************************************************/
	scanf("%c",&znak);
	int liczba;
	if(isdigit(znak))
	{
		liczba=znak-'0';
		liczba*=100000;
	}
	else
	{
		if (err_code != NULL) *err_code = 3;
		return NULL;		
	}
	int indexik;
	int y = scanf("%d", &indexik);
	if (y != 1)
	{
		if (err_code != NULL) *err_code = 3;
		return NULL;
	}
	indexik+=liczba;
	/************************************************/
	scanf("%c", &znak);
	if (znak != ',')
	{
		if (err_code != NULL) *err_code = 4;
		return NULL;
	}
	scanf("%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 4;
		return NULL;
	}
	/*************************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica3[50];
	ptr = tablica3;
	for (i = 0; i < 50; i++)
	{
		scanf("%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 4;
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 4;
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 4;
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 4;
		return NULL;
	}
	scanf("%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 5;
		return NULL;
	}
	/**********************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica4[80];
	ptr = tablica4;
	for (i = 0; i < 80; i++)
	{
		scanf("%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 5;
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 5;
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 5;
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 5;
		return NULL;
	}
	scanf("%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 6;
		return NULL;
	}
	/********************************************/
	int rok;
	y = scanf("%d", &rok);
	if (y != 1)
	{
		if (err_code != NULL) *err_code = 6;
		return NULL;
	}
	set(p, tablica1, tablica2, indexik, tablica3, tablica4, rok, err_code);
	return p;
}
/*************************************************************/
void display_load_t(struct student_t* s)
{
	if(s==NULL) return;
	printf("%s, %s, %d, %s, %s, %d",s->name,s->surname,s->index,s->field,s->faculty,s->year);
}

struct student_t* freadd(const char *filenam, struct student_t* p, int *err_code, int tryb)
{
	if (p == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return NULL;
	}
	FILE *filename;
	if(tryb==1) filename=fopen(filenam,"r");
	if(tryb==2) filename=fopen(filenam,"rb");
	int i;
	char *ptr;
	char znak;
	int k=0;
	int pobrane = 0;
	int czy_litera = 0;
/*************************************************/
	char tablica1[20];
	ptr = tablica1;
	for (i = 0; i < 20; i++)
	{
		fscanf(filename,"%c", &znak);
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 1;
			fclose(filename);
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 1;
		fclose(filename);
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 1;
		fclose(filename);
		return NULL;
	}
	fscanf(filename,"%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 2;
		fclose(filename);
		return NULL;
	}
	/***************************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica2[40];
	ptr = tablica2;
	for (i = 0; i < 40; i++)
	{
		fscanf(filename,"%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 2;
			fclose(filename);
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 2;
			fclose(filename);
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 2;
		fclose(filename);
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 2;
		fclose(filename);
		return NULL;
	}
	fscanf(filename,"%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 2;
		fclose(filename);
		return NULL;
	}
	/************************************************/
	fscanf(filename,"%c",&znak);
	int liczba;
	if(isdigit(znak))
	{
		liczba=znak-'0';
		liczba*=100000;
	}
	else
	{
		if (err_code != NULL) *err_code = 3;
		fclose(filename);
		return NULL;		
	}
	int indexik;
	int y = fscanf(filename,"%d", &indexik);
	if (y != 1)
	{
		if (err_code != NULL) *err_code = 3;
		fclose(filename);
		return NULL;
	}
	indexik+=liczba;
	/************************************************/
	fscanf(filename,"%c", &znak);
	if (znak != ',')
	{
		if (err_code != NULL) *err_code = 4;
		fclose(filename);
		return NULL;
	}
	fscanf(filename,"%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 4;
		fclose(filename);
		return NULL;
	}
	/*************************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica3[50];
	ptr = tablica3;
	for (i = 0; i < 50; i++)
	{
		fscanf(filename,"%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 4;
			fclose(filename);
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 4;
			fclose(filename);
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 4;
		fclose(filename);
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 4;
		fclose(filename);
		return NULL;
	}
	fscanf(filename,"%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 5;
		fclose(filename);
		return NULL;
	}
	/**********************************************/
	k=0;
	pobrane = 0;
	czy_litera = 0;
	char tablica4[80];
	ptr = tablica4;
	for (i = 0; i < 80; i++)
	{
		fscanf(filename,"%c", &znak);
		if (i == 0 && znak == ' ')
		{
			if (err_code != NULL) *err_code = 5;
			fclose(filename);
			return NULL;
		}
		if (znak == '\n' || isdigit(znak) || znak == '/')
		{
			if (err_code != NULL) *err_code = 5;
			fclose(filename);
			return NULL;
		}
		if (znak == ',')
		{
			*ptr = '\0';
			k=1;
			break;
		}
		if (isalpha(znak)) czy_litera = 1;
		pobrane += 1;
		*ptr = znak;
		ptr++;
	}
	if (k==0)
	{
		if (err_code != NULL) *err_code = 5;
		fclose(filename);
		return NULL;
	}
	if (pobrane == 0 || czy_litera == 0)
	{
		if (err_code != NULL) *err_code = 5;
		fclose(filename);
		return NULL;
	}
	fscanf(filename,"%c", &znak);
	if (znak != ' ')
	{
		if (err_code != NULL) *err_code = 6;
		fclose(filename);
		return NULL;
	}
	/********************************************/
	int rok;
	y = fscanf(filename,"%d", &rok);
	if (y != 1)
	{
		if (err_code != NULL) *err_code = 6;
		fclose(filename);
		return NULL;
	}
	set(p, tablica1, tablica2, indexik, tablica3, tablica4, rok, err_code);
	fclose(filename);
	return p;
}
/************************************************************/



void display(const struct student_t* p)
{
	if (p == NULL) return;
	printf("%s %s, index number: %d, was ", p->name, p->surname, p->index);
	const char *wsk;
	wsk = p->field;
	if (*wsk == 'a' || *wsk == 'A' || *wsk == 'O' || *wsk == 'o' || *wsk == 'E' || *wsk == 'e' || *wsk == 'Y' || *wsk == 'y' || *wsk == 'i' || *wsk == 'I' || *wsk == 'u' || *wsk == 'U') printf("an ");
	else printf("a ");
	printf("%s student at the %s in %d.\n", p->field, p->faculty, p->year);
}
/**************************************************/
int main()
{
	struct student_t ja;
	int err_code;
	int *result = &err_code;
	printf("Podaj dane: ");
	if (read(&ja, result) == NULL) return printf("Incorrect input\n"),err_code;
	else
	{
		display(&ja);
	}
	int c = getchar();
    if (c != '\n') 
    {
        while (c != '\n')   c = getchar();
    }
	char tab[31]={0};
	printf("Podaj sciezke: ");
	scanf("%30[^\n]s",tab);
	char *ptr=tab;
	int blad=0;
	for(;*ptr!='.';ptr++)
	{
		if(*ptr=='\0')
		{
			blad=1;
			break;
		}
	}
	if(blad==1)
	{
		printf("Unsupported file format\n");
		return 7;
	}
	ptr++; // by³ na kropke teraz jest na pierwszy znak po niej
	char rozszerzenie[10]={0};
	char *ptr2=rozszerzenie;
	for(;*ptr!='\0';ptr++,ptr2++)
	{
		*ptr2=*ptr;
	}
	blad=0;
	ptr2=rozszerzenie;
	int roz=0;
	if((*ptr2=='t' && *(ptr2+1)=='x' && *(ptr2+2)=='t') || (*ptr2=='b' && *(ptr2+1)=='i' && *(ptr2+2)=='n'));
	else
	{
		printf("Unsupported file format\n");
		return 7;		
	}
	if(*ptr2=='t' && *(ptr2+1)=='x' && *(ptr2+2)=='t') roz=1;
	else if(*ptr2=='b' && *(ptr2+1)=='i' && *(ptr2+2)=='n') roz=2;
	if(roz==1)
	{
		int w = save_student_t(tab,&ja);
		if(w==1) return printf("Incorrect input\n"),1;
		if(w==2) return printf("Couldn't create file\n"),5;
		if(w==0) printf("File saved\n");
	} 
	if(roz==2)
	{
		int w = save_student_b(tab,&ja);
		if(w==1) return printf("Incorrect input\n"),1;
		if(w==2) return printf("Couldn't create file\n"),5;
		if(w==0) printf("File saved\n");
	} 
	printf("Czy chcesz odczytac dane (Y/N)?  ");
	char ans;
	c = getchar();
    if (c != '\n') 
    {
        while (c != '\n')   c = getchar();
    }
	scanf("%c",&ans);
	if(ans!='Y' && ans!='y' && ans!='n' && ans!='N')
	{
		printf("Incorrect input\n");
		return 1;
	}
	if(ans=='n' || ans=='N');
	else if(roz==1)
	{
		struct student_t odczyt;
		int p=load_student_t(tab,&odczyt);
		if(p==1)
		{
			printf("Incorrect input\n");
			return 1;
		}
		if(p==2) return printf("Couldn't open file"),4;
		if(p==3) return printf("File corrupted"),6;
		display(&odczyt);
	}
	else if(roz==2)
	{
		struct student_t odczyt;
		int p=load_student_b(tab,&odczyt);
		if(p==1)
		{
			printf("Incorrect input\n");
			return 1;
		}
		if(p==2) return printf("Couldn't open file"),4;
		if(p==3) return printf("File corrupted"),6;
		display(&odczyt);
	}
	
	return 0;
}





int save_student_t(const char *filename, const struct student_t* s)
{
	if(filename==NULL || s==NULL) return 1;
	FILE *f;
	f=fopen(filename,"w");
	if(f==NULL) return 2;
	fprintf(f,"%s, %s, %d, %s, %s, %d",s->name,s->surname,s->index,s->field,s->faculty,s->year);
	fclose(f);
	return 0;
}

int load_student_t(const char *filename, struct student_t* s)
{
	if(filename==NULL || s==NULL) return 1;
	FILE *f;
	f=fopen(filename,"r");
	if(f==NULL) return 2;
	int err_code;
	int *err_code1=&err_code;
	int tryb=1;
	if(freadd(filename,s,err_code1,tryb)==NULL)
	{
		fclose(f);
		return 3;
	} 
	fclose(f);
	return 0;
}
int save_student_b(const char *filename, const struct student_t* s)
{
	if(filename==NULL || s==NULL) return 1;
	FILE *f;
	f=fopen(filename,"wb");
	if(f==NULL) return 2;
	char tablica[200]={0};
	char tablica2[200]={0};
	const char *wsk=(s->name);
	char *ptr=tablica;
	for(;*wsk!='\0';wsk++,ptr++) *ptr=*wsk;
	*ptr=',';
	ptr+=1;
	*ptr=' ';
	ptr+=1;
	wsk=(s->surname);
	for(;*wsk!='\0';wsk++,ptr++) *ptr=*wsk;
	*ptr=',';
	ptr+=1;
	*ptr=' ';
	ptr+=1;
	int liczba1=(s->index);
	ptr=tablica2;
	*ptr=',';
	ptr+=1;
	*ptr=' ';
	ptr+=1;
	wsk=(s->field);
	for(;*wsk!='\0';wsk++,ptr++) *ptr=*wsk;
	*ptr=',';
	ptr+=1;
	*ptr=' ';
	ptr+=1;
	wsk=(s->faculty);
	for(;*wsk!='\0';wsk++,ptr++) *ptr=*wsk;
	*ptr=',';
	ptr+=1;
	*ptr=' ';
	ptr+=1;
	int liczba2=(s->year);
	int len=strlen(tablica);
	fwrite(tablica,1,len,f);
	fprintf(f,"%d",liczba1);
	int len2=strlen(tablica2);
	fwrite(tablica2,1,len2,f);
	fprintf(f,"%d",liczba2);
	fclose(f);
	return 0;
}
int load_student_b(const char *filename, struct student_t* s)
{
	if(filename==NULL || s==NULL) return 1;
	FILE *f;
	f=fopen(filename,"rb");
	if(f==NULL) return 2;
	int err_code;
	int *err_code1=&err_code;
	int tryb=2;
	if(freadd(filename,s,err_code1,tryb)==NULL)
	{
		fclose(f);
		return 3;
	}
	fclose(f);
	return 0;
}



//Krzysztof, Pijanowski, 222540, IFNORMATYKA, WEEIA, 2019
