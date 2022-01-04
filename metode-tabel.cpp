#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAKS 150

void menu();
void metodeTabel();
void metodeBiseksi();
float fcX(float);
int i,j,k;
int main(){
    menu();
    return 0;
}
void menu(){
    int pil;
    printf("<<   Metode Numerik    >>\n");
    printf("<<   1.Metode Tabel    >>\n");
    printf("<<   2.Metode Biseksi  >>\n");
    printf("-----------------------\n");
    printf("Masukan Pilihan Anda : ");
    scanf("%d",&pil);
    switch(pil){
        case 1:
            metodeTabel();
            break;
        case 2:
            metodeBiseksi();
            break;
        default:
            printf("Menu yang anda pilih tidak ada");
    }
}
void metodeTabel(){
    double a,b,n,h,x[MAKS],y[MAKS];
    puts("\tMetode Tabel");
    printf("\tMasukan Batas Bawah : ");
    scanf("%lf",&a);
    printf("\tMasukan Batas Atas : ");
    scanf("%lf",&b);
    printf("\tMasukan Banyak Iterasi : ");
    scanf("%lf",&n);
    puts("\t--------------------------");
    h = (b-a)/n;
    printf("\t  i\t  x\t   fx\n");
    for(i=0;i<=n;i++){
        x[i] = a+i*h;
        y[i] = fcX(x[i]);
        printf("\t  %d\t%.2f\t%.5f\n",i,x[i],y[i]);
    }
    puts("\t--------------------------");
    for(j=0;j<=n;j++){
        if(y[j] == 0)
            printf("Titik Potong sumbu-x saat nilai x = %f\n",x[j]);
        else if(y[j]*y[j+1]<0){
            printf("\tAkar diantara %lg & %lg\n",x[j],x[j+1]);
            if(fabs(y[j])<fabs(y[j+1])){
                printf("\tAkar lebih dekat ke %lg\n",x[j]);
            } else {
                printf("\tAkar lebih dekat ke %lg\n",x[j+1]);
            }
        }
    }
    puts("\t--------------------------");

}
void metodeBiseksi(){
    float a,b,tErr,x,fa,fb;
    int n,i;

    puts("\t|     Metode Biseksi      |");
    printf("\tMasukan Batas Bawah : ");
    scanf("%f",&a);
    printf("\tMasukan Batas Atas : ");
    scanf("%f",&b);
    printf("\tMasukan Toleransi Error : ");
    scanf("%f",&tErr);
    printf("\tMasukan Banyak Iterasi : ");
    scanf("%d",&n);
    fa = fcX(a);
    fb = fcX(b);
    if (fa * fb > 0 )
        printf("Tidak ada akar di antara kedua batas persamaan \n");
    else{
        printf("\t  i\t   a\t   b\t   x\t   f(a)\t  f(x)\n");
        for(i=0;i<=n;i++){
            x=(a+b)/(2);
            printf("\t  %d\t%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",i,a,b,x,fa,fcX(x));
            if(fa*fcX(x)<0){
                b=x;
                fb=fcX(x);
            }
            else{
                a=x;
                fa=fcX(x);
            }
            if(fabs(b-a) < tErr)
                i = n+1;
        }
        printf("\tAkar Persamaan : %.4f\n",x);
        printf("\tF(x) : %.4f",fcX(x));
    }


}
float fcX(float x){
    return(exp(x)+x);
}
