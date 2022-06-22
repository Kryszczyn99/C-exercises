#include <stdio.h>
#include <stdlib.h>
#define INT 0
#define DOUBLE 1

#define DEFINE_ARRAY(TYPE)\
	struct array_##TYPE##_t\
	{\
		int size;\
    	int capacity;\
    	TYPE* data;\
	}

#define FREE_ARRAY(TYPE)\
	void free_array_##TYPE(struct array_##TYPE##_t *array)\
	{\
		if(array==NULL) return;\
		int flaga=0;\
		if(array->data!=NULL) flaga=1;\
		if(flaga==1) free(array->data);\
		free(array);\
	}

#define CREATE_ARRAY(TYPE)\
;struct array_##TYPE##_t *create_array_##TYPE(int size)\
{\
		if(size<=0) return NULL;\
	    struct array_##TYPE##_t *wsk = (struct array_##TYPE##_t*)malloc(sizeof(struct array_##TYPE##_t));\
		if(wsk==NULL) return NULL;\
	    TYPE* ptr = (TYPE*)calloc(size, sizeof(TYPE));\
		if(ptr==NULL)\
		{\
	        free(wsk);\
	        return NULL;\
	    }\
	    wsk->data=ptr;\
	    wsk->capacity = size;\
	    wsk->size = 0;\
	    return wsk;\
}

#define SORT_ARRAY(TYPE)\
	int sort_array_##TYPE(struct array_##TYPE##_t *array)\
	{\
		if(array==NULL || array->data==NULL) return 1;\
		int l1=array->size;\
		int l2=array->capacity;\
		if(l1<=0 || l2<=0 || l1>l2) return 1;\
		TYPE *data=array->data;\
		int size=array->size;\
		int klucz;\
		int i=0,j=0;\
		for(;i<size;i++)\
		{\
			klucz=i;\
			for(j=i;j<size;j++)\
			{\
				if(*(data+j)<*(data+klucz)) klucz=j;\
			}\
			TYPE temp=*(data+klucz);\
			*(data+klucz)=*(data+i);\
			*(data+i)=temp;\
		}\
	    return 0;\
	}

 #define LOAD_ARRAY(TYPE)\
 	int load_array_##TYPE(struct array_##TYPE##_t **array, const char *filename)\
	{\
		if(array==NULL) return 1;\
		if(filename==NULL) return 1;\
		FILE *f;\
		int num,y;\
		int s=sizeof(int);\
		f=fopen(filename,"rb");\
		if(f==NULL) return 2;\
		y=fread(&num,s,1,f);\
		if(y!=1 || num<=0)\
		{\
			fclose(f);\
			return 3;\
		}\
		struct array_##TYPE##_t *wsk;\
		wsk=create_array_##TYPE(num);\
	    if(wsk==NULL)\
		{\
	    	fclose(f);\
	        return 4;\
		}\
		*array=wsk;\
		int p=sizeof(TYPE);\
	    y=fread(wsk->data,p,num,f);\
	    if(y==num)\
	    {\
	    	wsk->size=num;\
	    	fclose(f);\
	    	return 0;\
		}\
		else\
		{\
			fclose(f);\
			free_array_##TYPE(wsk);\
		}\
		return 3;\
	}


#define SAVE_ARRAY(TYPE)\
	int save_array_##TYPE(const struct array_##TYPE##_t *array, const char *filename)\
	{\
		if(array==NULL || array->data==NULL || filename==NULL) return 1;\
		int l1=array->size;\
		int l2=array->capacity;\
		if(l1<=0 || l2<=0 || l1>l2) return 1;\
		FILE* f;\
		f=fopen(filename,"wb");\
		if(f!=NULL)\
		{\
			int k=array->size;\
			int wielkosc=sizeof(TYPE);\
			int tr=sizeof(int);\
			fwrite(&k, tr, 1, f);\
			struct array_##TYPE##_t *tablica=(struct array_##TYPE##_t *) array;\
			tablica->size=k;\
			fwrite(tablica->data, wielkosc, l1, f);\
			fclose(f);\
			return 0;\
		} \
	return 2;\
	}

DEFINE_ARRAY(double)
CREATE_ARRAY(double)
FREE_ARRAY(double)
SAVE_ARRAY(double)
LOAD_ARRAY(double)
SORT_ARRAY(double)

DEFINE_ARRAY(int)
CREATE_ARRAY(int)
FREE_ARRAY(int)
SAVE_ARRAY(int)
LOAD_ARRAY(int)
SORT_ARRAY(int)

int main ()
{
	int i=0;
	char *wsk=(char *)malloc(31*sizeof(char));
	if(wsk==NULL) return printf("Failed to allocate memory"),8;
	printf("podaj nazwe pliku: ");
	while(1)
	{
		if(i==30)
		{
			*(wsk+i)='\0';
			break;
		}
		char znak;
		scanf("%c",&znak);
		if(znak=='\n')
		{
			*(wsk+i)='\0';
			break;			
		}
		*(wsk+i)=znak;
		i++;
	}
	printf("Podaj operacje: ");
	int type;
	int y=scanf("%d",&type);
	if(y!=1)
	{
		free(wsk);
		return printf("Incorrect input"),1;
	} 
	if(type==INT) //int
	{
		struct array_int_t *ptr;
		int y=load_array_int(&ptr,wsk);
		switch(y)
		{
			case 2:
				{
					free(wsk);
					return printf("Couldn't open file"),4;
				}
			case 3:
				{
					free(wsk);
					return printf("File corrupted"),6;
				}
			case 4:
				{
					free(wsk);
					return printf("Failed to allocate memory"),8;
				}
			default: break;
		}
		sort_array_int(ptr);
		int w=save_array_int(ptr,wsk);
		if(w!=2)
		{
			printf("File saved");
			free_array_int(ptr);
			free(wsk);
		}
		else
		{
			free(wsk);
			free_array_int(ptr);
			return printf("Couldn't create file"),5;
		}
	}
	else if(type==DOUBLE) //double
	{
		struct array_double_t *ptr;
		int y=load_array_double(&ptr,wsk);
		switch(y)
		{
			case 2:
				{
					free(wsk);
					return printf("Couldn't open file"),4;
				}
			case 3:
				{
					free(wsk);
					return printf("File corrupted"),6;
				}
			case 4:
				{
					free(wsk);
					return printf("Failed to allocate memory"),8;
				}
			default: break;
		}
		sort_array_double(ptr);
		int w=save_array_double(ptr,wsk);
		if(w!=2)
		{
			printf("File saved");
			free_array_double(ptr);
			free(wsk);
		}
		else
		{
			free(wsk);
			free_array_double(ptr);
			return printf("Couldn't create file"),5;
		}		
	}
	else 
	{
		free(wsk);
		return printf("Incorrect input data"),2;
	}
	return 0;
}
