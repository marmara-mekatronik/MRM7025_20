#include <stdio.h>

int lineer_arama(int A[], int n, int aranan);

int main() {
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d . indisde bulundu", lineer_arama(A,10,7));

    return 0;
}

int lineer_arama(int A[], int n, int aranan){
    int c;
    int sonuc = -1;
    for (c=0; c<n; c++){
        if (A[c] == aranan)
        {
            sonuc = c;
            break;
        }
    }
    return sonuc;
}