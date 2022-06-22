#include<stdio.h>
#include<math.h>


double mySin(double x, int n){
    if(n<0) return -1;
    double sil=1;
    double pot=1;
//  float mianownik = 1;
    double s=0;
    double znak=-1;
    for(int k=0;k<n+1;k++){
        znak=-znak;
        for(int d=1;d<2*k+2;d++){
            sil=sil*(double)d;
            pot=pot*x;
        }
        
        s=s+znak*pot/sil;
        sil=1;
        pot=1;
    }

    return s;
    
        
}
double myCos(double x,int n){
    if(n<0) return -1;
    double sil=1;
    double pot =1;
    double wynik=0;
    double znak=-1;
    for(int k=0;k<n+1;k++){
        znak=-znak;
        for(int a=1;a<2*k+1;a++){
        sil=sil*(double)a;
        pot=pot*x;
        }
        wynik=wynik+znak*pot/sil;
        sil=1;
        pot=1;
    }
    return wynik;
    
    
}
int main(void){

    float x;
    int n;
    printf("Podaj wartosc kata, dla ktorego chcesz obliczyc wartosc funkcji sin i cos:");
    int a=scanf("%f",&x);
        if(a!=1){
            printf("Incorrect input");
            return 1;
        }
    printf("Podaj liczb? wyraz?w szegegu Taylora:");
    int b=scanf("%d",&n);
    if(b!=1||n<0){
        printf("Incorrect input");
        return 1;
    }
    printf("Wynik: %lf\n",mySin(x,n));
    printf("Wynik: %f",myCos(x,n)); 
}
