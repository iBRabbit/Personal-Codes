#include "stdio.h"

int main(int argc, char const *argv[])
{
    int pilihan = 0;
    char adminName[128];
    printf("Masukkan nama anda : ");
    scanf("%[^\n]", adminName);
    
    printf("Selamat datang di program penghitung nilai! By : %s\n", adminName);
    printf("================================================================\n");

    printf("MENU : \n");
    printf("[1] Konversikan nilai anda ke grade\n");
    printf("[2] Cek apakah anda lulus suatu mata kuliah\n");
    printf("Masukkan pilihan anda : ");

    scanf("%d", &pilihan); getchar();
    int nilai = 0;

    switch (pilihan) {
        
        case 1 : 
            printf("Masukkan nilai anda : ");
            scanf("%d", &nilai); getchar();

            if(nilai < 0 || nilai > 100) {
                printf("Nilai anda tidak valid.\n");
                return 1;
            }

            if(nilai <= 60) printf("Grade anda adalah D\n");
            else if(nilai > 60 && nilai < 70) printf("Nilai anda adalah C\n");
            else if(nilai > 70 && nilai < 80) printf("Nilai anda adalah B\n");
            else if (nilai >= 80 && nilai <= 100) printf("Nilai anda adalah A\n");
            else printf("Input anda tidak valid\n");

            break;
        case 2 : 
            
            printf("Masukkan nilai anda : ");
            scanf("%d", &nilai); getchar();

            if(nilai < 0 || nilai > 100) {
                printf("Nilai anda tidak valid.\n");
                return 1;
            }

            if(nilai >= 70) printf("Selamat anda lulus!\n");
            else printf("Maaf anda tidak lulus\n.");

            break; 
        default : 
            printf("Input anda tidak valid.\n");
            return 1;
    }

    return 0;
}
