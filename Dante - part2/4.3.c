#include <stdio.h>
#include <ctype.h>

struct student_t
{
	char name[20];
	char surname[40];
	int index;
	char field[50];
	char faculty[80];
	int year;
};


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
int main()
{
	struct student_t ja;
	int err_code;
	int *result = &err_code;
	printf("Podaj dane: ");
	if (read(&ja, result) == NULL)
	{
		printf("Incorrect input\n");
		struct student_t on;
		int err_code2;
		int *result2=&err_code2;
		set(&on,"Krzysztof", "Pijanowski", 222540, "informatyka", "weeia", 2019,result2);
		display(&on);
		return err_code;
	} 
	struct student_t on;
	int err_code2;
	int *result2=&err_code2;
	set(&on,"Krzysztof", "Pijanowski", 222540, "informatyka", "weeia", 2019,result2);
	display(&ja);
	display(&on);
	display_name(&ja);
	display_surname(&ja);
	display_index(&ja);
	display_field(&ja);
	display_faculty(&ja);
	display_year(&ja);
	return 0;
}






