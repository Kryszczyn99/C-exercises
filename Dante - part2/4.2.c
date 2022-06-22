#include <stdio.h>
#include <ctype.h>

struct student_t
{
    char name[20];
    char surname[40];
    int index;
};

struct student_t* read(struct student_t* p, int *err_code)
{
	if(p==NULL)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;
	}
	char *ptr;
	ptr=p->name;
	int i,pobrane=0;
	int k=0;
	char znak;
	for(i=0;i<20;i++)
	{
		scanf("%c",&znak);
		if(znak==',')
		{
			scanf("%c",&znak);
			if(znak==' ')
			{
				*ptr='\0';
				k=1;
				break;
			} 
			else
			{
				if(err_code!=NULL) *err_code=1;
				return NULL;	
			}
		}
		if(znak=='\n')
			{
				if(err_code!=NULL) *err_code=1;
				return NULL;	
			}
		if(!isalpha(znak))
		{
			if(err_code!=NULL) *err_code=1;
			return NULL;			
		}
		pobrane+=1;
		*ptr=znak;
		ptr++;
	}
	if(pobrane==0)
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;			
	}
	if(k==0) 
	{
		if(err_code!=NULL) *err_code=1;
		return NULL;			
	}
	
	pobrane=0;
	k=0;
	char *ptr2=(p->surname);
	for(i=0;i<40;i++)
	{
		scanf("%c",&znak);
		if(znak==',')
		{
			scanf("%c",&znak);
			if(znak==' ')
			{
				*ptr='\0';
				k=1;
				break;
			} 
			else
			{
				if(err_code!=NULL) *err_code=2;
				return NULL;	
			}	
		}
		if(znak=='\n')
			{
				if(err_code!=NULL) *err_code=2;
				return NULL;	
			}
		if(isdigit(znak) || znak=='/')
		{
			if(err_code!=NULL) *err_code=2;
			return NULL;			
		}
		pobrane+=1;
		*ptr2=znak;
		ptr2++;
	}		
	if(pobrane==0)
	{
		if(err_code!=NULL) *err_code=2;
		return NULL;			
	}
	if(k==0) 
	{
		if(err_code!=NULL) *err_code=2;
		return NULL;			
	}
/*	ptr=p->surname;
	for(;*ptr!='\0';ptr++)
	{
		if(*ptr==' ')
		{
			*ptr='\0';
			break;
		}
	}*/
	int y=scanf("%d",&(p->index));
	if(y!=1)
	{
		if(err_code!=NULL) *err_code=3;
		return NULL;			
	}
	if(err_code!=NULL) *err_code=0;
	ptr=p->name;
	i=0;
	while(i<20)
	{
		if(*ptr=='\0') break;
		if(!isalpha(*ptr) && *ptr!=' ' && *ptr!='.')
		{
			*ptr='\0';
			break;
		}
		ptr++;
		i++;
	}
	i=0;
	ptr=p->surname;
	while(i<40)
	{
		if(*ptr=='\0') break;
		if(!isalpha(*ptr) && *ptr!=' ' && *ptr!='.')
		{
			*ptr='\0';
			break;
		}
		ptr++;
		i++;
	}
	return p;
}
void show(const struct student_t* p)
{
	if(p==NULL) return;
	printf("%s %s, %d",p->name,p->surname,p->index);
}

int main ()
{
	printf("Podaj dane: \n");
	struct student_t value;
	int err_code;
	int *result=&err_code;
	if(read(&value,result)==NULL) return printf("Incorrect input\n"),err_code;
	show(&value);
	return 0;
}
