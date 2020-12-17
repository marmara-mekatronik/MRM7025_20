#include <stdio.h>

void dizi_yazdir(int dizi[], int boyut);
void araya_sokarak_siralama(int dizi[], int boyut);


int main() {
    int sirasiz_dizi[]={21,13,9,12,4,10,100,1};
    int boyut = sizeof (sirasiz_dizi) / sizeof (int);
    printf("\nSirasiz:");
    dizi_yazdir(sirasiz_dizi,boyut);
    printf("\n______________________");
    araya_sokarak_siralama(sirasiz_dizi,boyut);
    return 0;
}

void dizi_yazdir(int dizi[], int boyut) {

    for (int i = 0; i < boyut; i++) {
        printf("%d\t", dizi[i]);
    }
}

void araya_sokarak_siralama(int dizi[], int boyut){
    int i, j, anahtar;
    for (int i = 1; i < boyut; i++) {
        anahtar=dizi[i];
        j=i-1;
        while (j>=0 && dizi[j]>anahtar){
            dizi[j+1]=dizi[j];
            j--;
        }
        dizi[j+1]=anahtar;
        printf("\n%d. adim :",i);
        dizi_yazdir(dizi,boyut);
    }
    printf("\n________________________\n");
    printf("\nSirali: ");
    dizi_yazdir(dizi,boyut);
}