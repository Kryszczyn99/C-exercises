#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct doubly_linked_list_t* dll_create()
{
	struct doubly_linked_list_t* wsk = (struct doubly_linked_list_t*)malloc(sizeof(struct doubly_linked_list_t));
	if (wsk == NULL) return NULL;
	wsk->head = NULL;
	wsk->tail = NULL;
	return wsk;
}

int dll_push_back(struct doubly_linked_list_t* dll, int value)
{
	if (dll == NULL) return 1;
	if (dll->head == NULL && dll->tail != NULL) return 1;
	if (dll->head != NULL && dll->tail == NULL) return 1;
	struct node_t* element = (struct node_t*)malloc(sizeof(struct node_t));
	if (element == NULL) return 2;
	element->data = value;
	element->next = NULL;
	element->prev = NULL;
	if (dll->head == NULL && dll->tail == NULL)
	{
		dll->head = element;
		dll->tail = element;
	}
	else
	{
		dll->tail->next = element;
		element->prev = dll->tail;
		dll->tail = element;
	}
	return 0;
}

int dll_size(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return -1;
	if (dll->head == NULL && dll->tail != NULL) return -1;
	if (dll->head != NULL && dll->tail == NULL) return -1;
	if (dll->head == NULL && dll->tail == NULL) return 0;
	struct node_t* wsk = dll->head;
	int size = 0;
	while (wsk != NULL)
	{
		size += 1;
		wsk = wsk->next;
	}
	return size;
}
int dll_is_empty(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return -1;
	if (dll->head == NULL && dll->tail != NULL) return -1;
	if (dll->head != NULL && dll->tail == NULL) return -1;
	if (dll->head == NULL && dll->tail == NULL) return 1;
	return 0;
}


void dll_clear(struct doubly_linked_list_t* dll)
{
	if (dll == NULL) return;
	if (dll->head != NULL && dll->tail != NULL)
	{
		struct node_t* wsk = dll->head;
		while (wsk != NULL)
		{
			struct node_t* temp = wsk->next;
			free(wsk);
			wsk = temp;
		}
	}
	dll->head=NULL;
	dll->tail=NULL;
}

void dll_display(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL || dll->tail == NULL || dll->head == NULL) return;
	struct node_t* wsk = dll->head;
	while (wsk != NULL)
	{
		printf("%d ", wsk->data);
		wsk = wsk->next;
	}
	printf("\n");
}
void dll_display_reverse(const struct doubly_linked_list_t* dll)
{
	if (dll == NULL || dll->tail == NULL || dll->head == NULL) return;
	struct node_t* wsk = dll->tail;
	while (wsk != NULL)
	{
		printf("%d ", wsk->data);
		wsk = wsk->prev;
	}
	printf("\n");
}

int dll_concat_zip(struct doubly_linked_list_t* dll1, struct doubly_linked_list_t* dll2)
{
    if (dll1 == NULL) return 1;
    if (dll1->head == NULL && dll1->tail != NULL) return 1;
    if (dll1->head != NULL && dll1->tail == NULL) return 1;
    if (dll2 == NULL) return 1;
    if (dll2->head == NULL && dll2->tail != NULL) return 1;
    if (dll2->head != NULL && dll2->tail == NULL) return 1;
    int size_1=dll_size(dll1);
    int size_2=dll_size(dll2);
    if(size_1==0 && size_2==0) return 1;    
    if(size_1==0)
    {
        dll1->tail = dll2->tail;
        dll1->head = dll2->head;
        dll2->tail = NULL;
        dll2->head = NULL;
    }
    else if(size_2==0);
    else
    {
    	struct node_t* temp=NULL;
    	struct node_t* ptr = dll2->head;
        struct node_t* wsk = dll1->head;
        while(1)
        {
        	if(ptr!=NULL && wsk!=NULL)
        	{
            	temp=dll2->head;
	            temp=temp->next;
	            if(temp!=NULL) temp->prev = NULL;
	            dll2->head = temp;
	            temp=wsk->next;
	        	if(temp!=NULL)	temp->prev = ptr;
	    		else	dll1->tail = ptr;
	    		
	    		ptr->prev = wsk;
	  		    ptr->next = wsk->next;
			    wsk->next = ptr;
			    wsk = ptr->next;
			    ptr = dll2->head;      		
			}
			if(ptr==NULL)
			{
				dll2->tail = NULL;
				return 0;
			}
            if(wsk==NULL)
            {
            	dll1->tail->next = dll2->head;
                dll2->head->prev = dll1->tail;
                dll1->tail = dll2->tail;
                dll2->tail = NULL;
                dll2->head = NULL;
                return 0;
            }
            
        }
    }
    return 0;
}
int dll_concat_begin(struct doubly_linked_list_t* dll1, struct doubly_linked_list_t* dll2)
{
	if (dll1 == NULL) return 1;
	if (dll1->head == NULL && dll1->tail != NULL) return 1;
	if (dll1->head != NULL && dll1->tail == NULL) return 1;
	if (dll2 == NULL) return 1;
	if (dll2->head == NULL && dll2->tail != NULL) return 1;
	if (dll2->head != NULL && dll2->tail == NULL) return 1;
	int size_1=dll_size(dll1);
	int size_2=dll_size(dll2);
	if(size_1==0 && size_2==0) return 1;
	if(size_2==0);
	else if(size_1==0)
	{
		dll1->tail=dll2->tail;
		dll1->head=dll2->head;
		dll2->tail=NULL;
		dll2->head=NULL;
	}
	else
	{
		dll1->head->prev=dll2->tail;
		dll2->tail->next=dll1->head;
		dll1->head=dll2->head;
		dll2->tail=dll1->head;
	}
	return 0;
}
int dll_concat_end(struct doubly_linked_list_t* dll1, struct doubly_linked_list_t* dll2)
{
	if (dll1 == NULL) return 1;
	if (dll1->head == NULL && dll1->tail != NULL) return 1;
	if (dll1->head != NULL && dll1->tail == NULL) return 1;
	if (dll2 == NULL) return 1;
	if (dll2->head == NULL && dll2->tail != NULL) return 1;
	if (dll2->head != NULL && dll2->tail == NULL) return 1;
	int size_1=dll_size(dll1);
	int size_2=dll_size(dll2);
	if(size_1==0 && size_2==0) return 1;	
	if(size_1==0)
	{
		dll1->tail=dll2->tail;	
		dll1->head=dll2->head;
	}
	else if(size_2==0);
	else
	{
		dll2->head->prev=dll1->tail;
		dll1->tail->next=dll2->head;
		dll1->tail=dll2->tail;
	}
	if(size_1==0)
	{
		dll2->head=NULL;
		dll2->tail=NULL;
	}
	return 0;
}
