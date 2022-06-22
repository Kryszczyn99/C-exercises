#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct linked_list_t* ll_create()
{
	struct linked_list_t* plist = (struct linked_list_t *)malloc(sizeof(struct linked_list_t));
	if (plist == NULL) return NULL;
	plist->head = NULL;
	plist->tail = NULL;
	return plist;
}

int ll_push_back(struct linked_list_t* ll, int value)
{
	if (ll == NULL) return 1;
	if (ll->head == NULL && ll->tail == NULL)
	{
		struct node_t *wsk = (struct node_t *)malloc(sizeof(struct node_t));
		if (wsk == NULL) return 2;
		wsk->data = value;
		wsk->next = NULL;
		ll->head = wsk;
		ll->tail = wsk;
		return 0;
	}
	else if (ll->head == NULL || ll->tail == NULL) return 1;
	struct node_t *wsk = (struct node_t *)malloc(sizeof(struct node_t));
	if (wsk == NULL) return 2;
	wsk->data = value;
	wsk->next = NULL;
	ll->tail->next = wsk;
	ll->tail = wsk;
	return 0;
}
int ll_push_front(struct linked_list_t* ll, int value)
{
	if (ll == NULL) return 1;
	if (ll->head == NULL && ll->tail == NULL)
	{
		struct node_t *wsk = (struct node_t *)malloc(sizeof(struct node_t));
		if (wsk == NULL) return 2;
		wsk->data = value;
		wsk->next = NULL;
		ll->head = wsk;
		ll->tail = wsk;
		return 0;
	}
	else if (ll->head == NULL || ll->tail == NULL) return 1;
	struct node_t *wsk = (struct node_t *)malloc(sizeof(struct node_t));
	if (wsk == NULL) return 2;
	wsk->data = value;
	wsk->next = ll->head;
	ll->head = wsk;
	return 0;
}
int ll_pop_front(struct linked_list_t* ll, int *err_code)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	int size = ll_size(ll);
	if (size == 1)
	{
		int wartosc = ll->head->data;
		free(ll->head);
		ll->head = NULL;
		ll->tail = NULL;
		if (err_code != NULL) *err_code = 0;
		return wartosc;
	}
	int wartosc = ll->head->data;
	struct node_t* ptr = ll->head->next;
	free(ll->head);
	ll->head = ptr;
	if (err_code != NULL) *err_code = 0;
	return wartosc;
}
int ll_pop_back(struct linked_list_t* ll, int *err_code)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	int size = ll_size(ll);
	if (size == 1)
	{
		int wartosc = ll->head->data;
		free(ll->head);
		ll->head = NULL;
		ll->tail = NULL;
		if (err_code != NULL) *err_code = 0;
		return wartosc;
	}
	int wartosc = ll->tail->data;
	struct node_t *ptr = ll->head;
	while (ptr->next != ll->tail)
	{
		ptr = ptr->next;
	}
	struct node_t *temp = ptr->next;
	free(temp);
	ptr->next = NULL;
	ll->tail = ptr;
	if (err_code != NULL) *err_code = 0;
	return wartosc;
}

int ll_back(const struct linked_list_t* ll, int *err_code)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	if (err_code != NULL) *err_code = 0;
	return ll->tail->data;
}
int ll_front(const struct linked_list_t* ll, int *err_code)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 1;
	}
	if (err_code != NULL) *err_code = 0;
	return ll->head->data;
}

struct node_t* ll_begin(struct linked_list_t* ll)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL) return NULL;
	return ll->head;
}
struct node_t* ll_end(struct linked_list_t* ll)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL) return NULL;
	return ll->tail;
}

int ll_size(const struct linked_list_t* ll)
{
	if (ll == NULL) return -1;
	if (ll->head == NULL && ll->tail == NULL) return 0;
	if (ll->head == NULL || ll->tail == NULL) return -1;
	if (ll->tail == ll->head) return 1;
	int size = 0;
	struct node_t *wsk = ll->head;
	while (1)
	{
		if (wsk->next == NULL)
		{
			size += 1;
			break;
		}
		wsk = wsk->next;
		size += 1;
	}
	return size;
}
int ll_is_empty(const struct linked_list_t* ll)
{
	if (ll == NULL) return -1;
	if (ll->head == NULL && ll->tail == NULL) return 1;
	return 0;
}
int ll_at(const struct linked_list_t* ll, unsigned int index, int *err_code)
{
	if (ll == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return -1;
	}
	unsigned int i = 0;
	struct node_t* wsk = ll->head;
	while (i < index)
	{
		wsk = wsk->next;
		if (wsk == NULL)
		{
			if (err_code != NULL) *err_code = 1;
			return 0;
		}
		i++;
	}
	if (err_code != NULL) *err_code = 0;
	return wsk->data;
}

int ll_insert(struct linked_list_t* ll, unsigned int index, int value)
{
	if (ll == NULL) return 1;
	if (ll->head == NULL && ll->tail != NULL) return 1;
	if (ll->head != NULL && ll->tail == NULL) return 1;
	if (ll->head == NULL && ll->tail == NULL && index == 0)
	{
		int g = ll_push_front(ll, value);
		if (g == 2) return 2;
		return 0;
	}
	else if (index == 0)
	{
		int g = ll_push_front(ll, value);
		if (g == 2) return 2;
		return 0;
	}
	if (ll->head == NULL && ll->tail == NULL && index != 0) return 1;
	int size = ll_size(ll);
	unsigned int rozmiar = (unsigned int)size;
	if (rozmiar == index)
	{
		int g = ll_push_back(ll, value);
		if (g == 2) return 2;
		return 0;
	}
	struct node_t* wsk = ll->head;
	unsigned int i = 1;
	while (i < index)
	{
		wsk = wsk->next;
		if (wsk == NULL) return 1;
		i++;
	}
	struct node_t* element = (struct node_t*)malloc(sizeof(struct node_t));
	if (element == NULL) return 2;
	element->data = value;
	element->next = NULL;

	struct node_t* poprzednik = wsk;
	struct node_t* nastepnik = wsk->next;

	poprzednik->next = element;
	element->next = nastepnik;
	return 0;
}

int ll_remove(struct linked_list_t* ll, unsigned int index, int *err_code)
{
	if (ll == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	if (ll->head == NULL && ll->tail != NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	if (ll->head != NULL && ll->tail == NULL)
	{
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	if (ll_is_empty(ll))
	{
		if (err_code != NULL) *err_code = 1;
		return 0;
	}
	int size = ll_size(ll);
	unsigned int rozmiar = (unsigned int)size;
	if (rozmiar-1 == index)
	{
		int blad = 0;
		int value = ll_pop_back(ll, &blad);
		if (blad != 0)
		{
			if (err_code != NULL) *err_code = 1;
			return 0;
		}
		if (err_code != NULL) *err_code = 0;
		return value;
	}
	if (index == 0)
	{
		int blad = 0;
		int value = ll_pop_front(ll, &blad);
		if (blad != 0)
		{
			if (err_code != NULL) *err_code = 1;
			return 0;
		}
		if (err_code != NULL) *err_code = 0;
		return value;
	}
	struct node_t* wsk = ll->head;
	unsigned int i = 1;
	while (i < index)
	{
		wsk = wsk->next;
		if (wsk == NULL)
		{
			if (err_code != NULL) *err_code = 1;
			return 0;
		}
		i++;
	}
	int value = wsk->next->data;
	struct node_t* poprzednik = wsk;
	struct node_t* nastepnik = wsk->next->next;
	free(wsk->next);
	poprzednik->next = nastepnik;
	if (err_code != NULL) *err_code = 0;
	return value;
}

void ll_clear(struct linked_list_t* ll)
{
	if (ll == NULL) return;
	if (ll->head != NULL && ll->tail != NULL)
	{
		struct node_t* wsk = ll->head;
		while (wsk != NULL)
		{
			struct node_t* temp = wsk->next;
			free(wsk);
			wsk = temp;
		}
	}
	ll->head=NULL;
	ll->tail=NULL;
}

void ll_display(const struct linked_list_t* ll)
{
	if (ll == NULL || ll->head == NULL || ll->tail == NULL) return;
	struct node_t *wsk = ll->head;
	while (wsk != NULL)
	{
		printf("%d ", wsk->data);
		wsk = wsk->next;
	}
	printf("\n");
}

