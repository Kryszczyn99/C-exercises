#include <stdio.h>

int int_len(int liczba)
{
	int d=liczba,b=0;
	int len=0;
	while(1)
	{
		b=d%10;
		d-=b;
		d/=10;
		len+=1;
		if(d==0) break;
	}
	return len;
}

struct date_t
{
    int day;
    int month;
    int year;
};

struct date_t* set_date(struct date_t* d, int day, int month, int year, int *err_code)
{
	if(d==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;
	}
	
	(d->day)=day;
	(d->month)=month;
	(d->year)=year;
	if(err_code!=NULL) *err_code=0;
	return d;
}

void show(const struct date_t* d)
{
	if(d==NULL) return;
	int dzien,miesiac,rok;
	dzien=d->day;
	miesiac=d->month;
	rok=d->year;
	if(dzien<=9) printf("0%d-",dzien);
    else printf("%d-",dzien);
    if(miesiac<=9) printf("0%d-",miesiac);
    else printf("%d-",miesiac);
    if(rok<=9) printf("000%d\n",rok);
    else if(rok<=99) printf("00%d\n",rok);
    else if(rok<=999) printf("0%d\n",rok);
    else printf("%d\n",rok);
}

struct date_t* read(struct date_t* d, int *err_code)
{
	if(d==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;
	}
	int L1,L2,L3;
	int y=scanf("%d-%d-%d",&L1,&L2,&L3);
	if(y!=3)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;	
	}
	int result1=int_len(L1);
	int result2=int_len(L2);
	int result3=int_len(L3);
	if(L1<=9 || L2<=9);
	else if(result1!=2 || result2!=2 || result3!=4)
	{
		if(err_code!=NULL) *err_code=2;
		return NULL;	
	}
	int error;
	int *wynik=&error;
	set_date(d,L1,L2,L3,wynik);
	if(err_code!=NULL) *err_code=0;
	return d;
}

int validate(const struct date_t* d)
{
	if(d==NULL) return -1;
	int dzien,miesiac,rok;
	dzien=(d->day);
	miesiac=(d->month);
	rok=(d->year);
	switch (miesiac)
	{
		case 12:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 11:
			{
				if(dzien>=1 && dzien<=30)
				{
					return 1;
				}
				return 0;
			}
		case 10:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 9:
			{
				if(dzien>=1 && dzien<=30)
				{
					return 1;
				}
				return 0;
			}
		case 8:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 7:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 6:
			{
				if(dzien>=1 && dzien<=30)
				{
					return 1;
				}
				return 0;
			}
		case 5:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 4:
			{
				if(dzien>=1 && dzien<=30)
				{
					return 1;
				}
				return 0;
			}
		case 3:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		case 2:
			{
				if(dzien>=1 && dzien<=27) return 1;
				if(rok%4)
				{
					if(dzien==28)  return 1;
					if(dzien==29)  return 0;
					else return 0;
				}
				else
				{
					if(dzien==28 && rok==2000) return 1;
					if(dzien==28) return 0;
					if(dzien==29 && rok==2000) return 1;
					if(dzien==29 && (rok%100==0) && rok>1600) return 0;
					if(dzien==29) return 1;
					return 0;
				}
			}
		case 1:
			{
				if(dzien>=1 && dzien<=31)
				{
					return 1;
				}
				return 0;
			}
		default: return 0;
	}
		
}

int main ()
{
	printf("Enter a date (formatted as dd-mm-yyyy):");
	struct date_t data;
	int err_code;
	int *result=&err_code;
	read(&data,result);
	if(err_code==1) return printf("Incorrect input\n"),1;
	int wynik=validate(&data);
	if(wynik==0)
	{
		printf("Incorrect");
	} 
	else if(wynik==1)
	{
		show(&data);
		printf("Correct\n");
	} 
	return 0;
}
