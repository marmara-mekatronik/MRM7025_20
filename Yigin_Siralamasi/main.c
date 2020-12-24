#include <stdio.h>

void dizi_yazdir(int dizi[], int boyut);

void maksimuma_yiginla(int dizi[], int n, int i);

void yigin_siralamasi(int dizi[], int boyut);

int main() {
    int dizi[] = {21, 13, 9, 12, 4};
    int boyut = sizeof(dizi) / sizeof(int);
    printf("\nSirasiz: ");
    dizi_yazdir(dizi, boyut);
    printf("____________________________________");

    yigin_siralamasi(dizi, boyut);
    printf("____________________________________");
    printf("\nSirali: ");
    dizi_yazdir(dizi, boyut);

    return 0;
}

void dizi_yazdir(int dizi[], int boyut) {
    for (int i = 0; i < boyut; i++) {
        printf("%d\t", dizi[i]);

    }
    printf("\n");
}

void maksimuma_yiginla(int dizi[], int n, int i) {
    // en büyük elemanı kok dugum olarak atama
    int enbuyuk = i;
    int sol = 2 * i + 1;
    int sag = 2 * i + 2;
    int gecici;

    // Eger sol alt ağaç kok düğümünden büyükse
    if (sol < n && dizi[sol] > dizi[enbuyuk])
        enbuyuk = sol;

    // Eger sağ alt ağaç kok düğümünden büyükse
    if (sag < n && dizi[sag] > dizi[enbuyuk])
        enbuyuk = sag;

    // Eğer enbüyük eleman kök düğümü değilse
    if (enbuyuk != i) {
        // en büyüğü değiştir
        gecici = dizi[i];
        dizi[i] = dizi[enbuyuk];
        dizi[enbuyuk] = gecici;

        // Özyinelemeli olarak fonksiyonu çağır.
        maksimuma_yiginla(dizi, n, enbuyuk);
    }
}

void yigin_siralamasi(int dizi[], int boyut) {
    int gecici;
    // yigin oluştur
    for (int i = boyut / 2 - 1; i <= 0; i--) {
        maksimuma_yiginla(dizi, boyut, i);
    }
    printf("\n Yigin olustu: ");
    dizi_yazdir(dizi, boyut);

    //Yiğında sıra sıra bir eleman çıkarmak
    for (int i = boyut - 1; i > 0; i--) {
        printf("\n%d. Adim (Once): ", boyut - i);
        dizi_yazdir(dizi, boyut);
        gecici = dizi[0];
        dizi[0] = dizi[i];
        dizi[i] = gecici;
        printf("\n%d. Adim (Sonra): ", boyut - i);
        dizi_yazdir(dizi, boyut);
        maksimuma_yiginla(dizi, i, 0);
    }
}

