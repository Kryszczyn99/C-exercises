#ifndef Przesuniecie_o_wektor
#define Przesuniecie_o_wektor
enum direction{ROTATE_RIGHT=1,ROTATE_LEFT=2};
int shift(int *array, int array_size, int positions_to_shift, enum direction dir);
#endif // przesuniecie
