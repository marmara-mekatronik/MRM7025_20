#include <stdio.h>

void dizi_yazdir(int dizi[], int boyut);
int bolumle(int dizi[],int ilk, int son);
void hizli_siralama(int dizi[], int ilk, int son){
    int konum = bolumle(dizi,ilk,son);
    if (ilk < konum -1){
        hizli_siralama(dizi,ilk, konum - 1);
    }
    if (konum < son){
        hizli_siralama(dizi, konum, son);
    }
}

int main() {
    int sirasiz_dizi[]={21,13,9,12,4};
    int boyut = sizeof(sirasiz_dizi)/sizeof (int);
    printf("\nSirasiz Dizi :");
    dizi_yazdir(sirasiz_dizi,boyut);
    printf("\n__________________");
    hizli_siralama(sirasiz_dizi,0,boyut-1 );
    printf("\n Sirali :");
    dizi_yazdir(sirasiz_dizi,boyut);
    printf("\n__________________");
    return 0;
}

void dizi_yazdir(int dizi[], int boyut){
    for (int i = 0; i < boyut; i++) {
printf("%d\t", dizi[i]);
    }
    printf("\n____________________");
}

int bolumle(int dizi[],int ilk, int son){
    int i=ilk;
    int j=son;
    int gecici;
    int pivot = dizi[(ilk+son)/2];
    while (i<=j){
        while (dizi[i]<pivot) i++;
        while (dizi[j]>pivot) j--;
        if(i<=j){
            gecici=dizi[i];
            dizi[i]=dizi[j];
            dizi[j]=gecici;
            i++;
            j--;
        }
    }
    return i;
}