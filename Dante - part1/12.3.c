#define N   1024 // maksymalna pojemnosc buforow na liczby, na wynik 2*N
 
typedef unsigned char u_char;
 
// sumuje wyniki
// w - bufor wynikowy, k - liczba, ktora dodajemy, p - pozycja w buforze
void _muladd(u_char *w, int k, int p) {
    p += N;
 
    int m = 0;
    do {
        if(w[p] == 0)
            w[p] = '0';
        w[p] += m;
        w[p] += k;
        if(w[p] > '9') {
            w[p] -= '0';
            m = w[p]/10;
            w[p] %= 10;
            w[p] += '0';
        } else
            m = 0;
        k = 0; p -= 1;
    } while(m);
}
 
// mnozy, a oraz b sa wskaznikami na bufory zawierajace liczby do pomnozenia
void multiply(u_char *a, u_char *b) {
    int n = strlen(a), i,
        m = strlen(b), j;
    int k, l;
 
    u_char *w = (u_char*)calloc(N<<1, sizeof(u_char));
// mnozy
    for(j = m-1, l = 0; j >= 0; j--) {
        for(i = n-1; i >= 0; i--) {
            k = (a[i]-'0') * (b[j]-'0');
            _muladd(w, k, i-l);
        }
        l += 1;
    }
// wypisuje
    for(i = 0; i < (N<<1) && !w[i]; i += 1);
    if(w[i] == '0') i += 1;
    while(i < N<<1 && w[i]) putc(w[i++], stdout);
    putc('\n', stdout);
 
    free(w);
}
