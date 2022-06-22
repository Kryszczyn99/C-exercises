#include <stdio.h>
#include <stdlib.h>
#define G 0
#define N 5
int main() 
{   
    int tablica1[N][N],tablica3[N][6];
    printf("Podaj macierz N na N:\n");
    int i,j;
    for(i=G; i<N; ++i)
    for(j=G; j<N; ++j)
        {
        int skan1=scanf("%d", &tablica1[i][j]);
        if(skan1!=1){printf("Incorrect input\n");return 1;}
        }
        
    int tablica2[N][N];
    printf("Podaj macierz N na N:\n");
    for(i=G;i<N;i=i+1)
    for(j=G;j<N;j=j+1)
        {
        int skan2=scanf("%d", &tablica2[i][j]);
        if(skan2!=1){printf("Incorrect input\n");return 1;}
        }
    
    i=G;
    while(i<N)
    {
        int n=G;
        for(j=G;j<N;j=j+1)
        {
            int k;
            for(k=G; k<N; ++k) if(tablica1[i][k]!=tablica2[k][j]) break;
            if(k==N) tablica3[i][n++]=j;
            
        }
        tablica3[i][n]=-1;
        i=i+1;
    }
	i=G;
    while(i<N)
    {
        printf("%2d", i);
        for(j=G;tablica3[i][j]!=-1;j=j+1)
            printf("%2d", tablica3[i][j]);
        printf("\n");
        i=i+1;
    }
    
    
    
    
    
    return G;
}
