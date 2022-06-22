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



