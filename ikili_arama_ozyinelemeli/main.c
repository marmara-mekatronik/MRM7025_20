#include <stdio.h>

void ikili_arama_ozyinelemeli(int dizi[], int boyut, int aranan, int ilk, int son);

int main() {
    int dizi[]={2,6,9,12,14,20,25};
    int aranan = 14;
    int ilk=0, son;
    int boyut = sizeof(dizi) / sizeof(int);
    son = boyut -1;
    ikili_arama_ozyinelemeli(dizi,boyut,aranan,ilk,son);
    return 0;
}

void ikili_arama_ozyinelemeli(int dizi[], int boyut, int aranan, int ilk, int son){
    int i, orta;
    orta = (ilk + son) / 2;
    if (ilk > son) {
        printf("%d sayisi, dizide bulunamadi\n", aranan);
        return;
    }
    printf("Ilk: %d. eleman, Ortanca: %d. eleman, Son: %d. eleman\n", ilk+1,orta+1,son+1);
    if (aranan> dizi[orta]){
        ilk = orta +1;
        ikili_arama_ozyinelemeli(dizi, boyut,aranan,ilk,son);
    } else if (aranan==dizi[orta]){
        printf("%d sayisi, dizinin %d. konumundadir\n", aranan, orta+1);
    }
    else
    {
        son = orta -1;
        ikili_arama_ozyinelemeli(dizi, boyut,aranan,ilk,son);
    }
}