#ifndef DICTIONARY
#define DICTIONARY

struct word_count_t {
  char *word;
  int counter;
};
struct dictionary_t
{
  int size;
  int capacity;
  struct word_count_t *wc;
};
int	my_strcmp(char *s1, char *s2);
struct dictionary_t* create_dictionary(int N, int *err_code);
void destroy_dictionary(struct dictionary_t** d);
char *alokacja(struct dictionary_t *slownik,int rozmiar_tablicy,int size);
void main_zamykanie(FILE *f, struct dictionary_t** slownik, char *wsk);
void zamykanie(FILE *f, int *err_code,struct dictionary_t* slownik,int blad);
int dictionary_add_word(struct dictionary_t *d, const char *word);
struct word_count_t* dictionary_find_word(const struct dictionary_t *d, const char *word);

void dictionary_display(const struct dictionary_t *d);

int dictionary_sort_alphabetically(struct dictionary_t *d);
int dictionary_sort_occurence(struct dictionary_t *d);

int save_dictionary_b(const struct dictionary_t *d, const char *filename);
struct dictionary_t* load_dictionary_b(const char *filename, int *err_code);
#endif //slownik
