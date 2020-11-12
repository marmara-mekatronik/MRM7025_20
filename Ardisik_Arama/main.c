#include <stdio.h>

void ardisik_arama(int dizi[], int boyut, int aranan);


int main() {
    int diziZ[5]={10,14,11,26,16};
    ardisik_arama(diziZ,5,8);
    return 0;
}

void ardisik_arama(int dizi[], int boyut, int aranan){
    int i;
    for(i=0;i<boyut;i++)
    {
        if (dizi[i]==aranan){
            printf("%d sayisi, dizinin %d. konumundadir.\n", aranan, i+1);
            break;
        }
    }
    printf("aradiginiz sayi bizi icerisinde bulunmamaktadir.");
}