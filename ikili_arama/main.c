#include <stdio.h>
void ikili_arama(int dizi[],int boyut, int aranan);

int main() {
    int dizi[]={2,6,9,12,14,20,25};
    int aranan = 14;
    int boyut = sizeof(dizi) / sizeof(int);
    ikili_arama(dizi,boyut,aranan);
    return 0;
}

void ikili_arama(int dizi[],int boyut, int aranan){
    int i, ilk, son, orta;
    ilk = 0;
    son = boyut - 1;
    orta =(ilk + son)/2;

    while (ilk <=son)
    {
        printf("Ilk: %d. elaman, Ortanca: %d. eleman, Son: %d. eleman\n",
               ilk+1, orta+1, son+1);

        if (aranan>dizi[orta]) {
            ilk = orta + 1;
        }
        else if (aranan == dizi[orta]){
            printf("%d sayisi, dizinin %d. konumundadir\n", aranan, orta+1);
            break;
        }
        else {
            son = orta - 1;
        }

        orta = (ilk + son) / 2;

        if (ilk > son)
        {
            printf("%d sayisi, dizide bulunamadi\n", aranan);
        }
    }

}