#include <stdio.h>
#include <stdlib.h>

void dizi_yazdir(int dizi[], int boyut);

void birlestirerek_siralama(int dizi[], int ilk, int son);

void birlestir(int dizi[], int ilk, int orta, int son);

int main() {
    int sirasiz_dizi[] = {21, 13, 9, 12, 4, 10, 100, 1};
    int boyut = sizeof(sirasiz_dizi) / sizeof(int);
    printf("\nSirasiz:");
    dizi_yazdir(sirasiz_dizi, boyut);
    printf("\n______________________");
    birlestirerek_siralama(sirasiz_dizi, 0, boyut - 1);
    printf("\nSiralı : ");
    dizi_yazdir(sirasiz_dizi, boyut);
    return 0;
}

void dizi_yazdir(int dizi[], int boyut) {

    for (int i = 0; i < boyut; i++) {
        printf("%d\t", dizi[i]);
    }
}

void birlestirerek_siralama(int dizi[], int ilk, int son) {
    if (ilk < son) {
        int orta = (son + ilk) / 2;
        birlestirerek_siralama(dizi, ilk, orta);
        birlestirerek_siralama(dizi, orta + 1, son);
        birlestir(dizi, ilk, orta, son);
    }
}

void birlestir(int dizi[], int ilk, int orta, int son) {
    int *gecici = (int *) malloc((son - ilk + 1) * sizeof(int));
    int i = ilk;
    int j = orta + 1;
    int k = 0;
    while (i <= orta && j <= son) {
        if (dizi[i] <= dizi[j])
            gecici[k++] = dizi[i++];
        else
            gecici[k++] = dizi[j++];
    }
    while (i <= orta) {
        gecici[k++] = dizi[i++];
    }
    while (j <= son) {
        gecici[k++] = dizi[j++];
    }
    k--;
    while (k >= 0) {
        dizi[ilk + k] = gecici[k];
        k--;
    }
    free(gecici);
}