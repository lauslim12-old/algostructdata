#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
const float pi = 3.1415;
int ProgramCounter = 0;

struct storage {
    char nama[10];
    int r, t;
    float luas, volume;
};

void hitungTabung(int jari, int tinggi, float *luas, float *volume) {
    *luas = 2 * pi * jari * (jari + tinggi);
    *volume = pi * jari * jari * tinggi;
}

void hitungKerucut(int jari, int tinggi, float *luas, float *volume) {
    float selimut;
    selimut = sqrt((jari * jari) + (tinggi * tinggi));
    *luas = (pi * jari * jari) + (pi * jari * selimut);
    *volume = 0.3333 * pi * jari * jari * tinggi;
}

void hitungBola(int jari, float *luas, float *volume) {
    *luas = 4 * pi * jari * jari;
    *volume = 1.3333 * pi * jari * jari * jari;
}

void Layar() {
    system("cls");
    printf("Program Kalkulator 3D \n");
    printf("1. Tabung \n");
    printf("2. Kerucut \n");
    printf("3. Bola \n");
    printf("4. Tampilkan History Perhitungan \n");
    printf("5. Print To .Txt \n");
    printf("6. Exit Program \n");
}

int main() {
    int pil, jari, tinggi; // main
    int hitung = 0, placeholder = 0; // looper
    int i = 0, j; // untuk menaruh di struktur
    float luas = 0, volume = 0;
    struct storage penyimpanan[150];

    while(placeholder == 0) {
        Layar();
        printf("Silakan pilih pilihanmu: ");
        scanf("%d", &pil);

        switch(pil) {
            case 1:
                // Input
                system("cls");
                printf("Perhitungan Tabung \n");
                printf("Jari-jari: ");
                scanf("%d", &jari);
                printf("Tinggi: ");
                scanf("%d", &tinggi);

                // Process
                hitungTabung(jari, tinggi, &luas, &volume);
                printf("Luas Permukaan: %.2f \n", luas);
                printf("Volume: %.2f \n", volume);
                system("pause");

                // Store in structure
                strcpy(penyimpanan[i].nama, "Tabung");
                penyimpanan[i].r = jari;
                penyimpanan[i].t = tinggi;
                penyimpanan[i].luas = luas;
                penyimpanan[i].volume = volume;
                i++;
                break;

            case 2:
                // Input
                system("cls");
                printf("Perhitungan Kerucut \n");
                printf("Jari-jari: ");
                scanf("%d", &jari);
                printf("Tinggi: ");
                scanf("%d", &tinggi);

                // Process
                hitungKerucut(jari, tinggi, &luas, &volume);
                printf("Luas Permukaan: %.2f \n", luas);
                printf("Volume: %.2f \n", volume);
                system("pause");

                // Store in structure
                strcpy(penyimpanan[i].nama, "Kerucut");
                penyimpanan[i].r = jari;
                penyimpanan[i].t = tinggi;
                penyimpanan[i].luas = luas;
                penyimpanan[i].volume = volume;
                i++;
                break;

            case 3:
                // Input
                system("cls");
                printf("Perhitungan Bola \n");
                printf("Jari-jari: ");
                scanf("%d", &jari);

                // Process
                hitungBola(jari, &luas, &volume);
                printf("Luas Permukaan: %.2f \n", luas);
                printf("Volume: %.2f \n", volume);
                system("pause");

                // Store in structure
                strcpy(penyimpanan[i].nama, "Bola");
                penyimpanan[i].r = jari;
                penyimpanan[i].t = jari;
                penyimpanan[i].luas = luas;
                penyimpanan[i].volume = volume;
                i++;
                break;

            case 4:
                system("cls");
                for(hitung = 0; hitung < i; hitung++) {
                    printf("#%d dengan nama bangun %s \n", hitung+1, penyimpanan[hitung].nama);
                    printf("Jari-jari: %d \n", penyimpanan[hitung].r);
                    printf("Tinggi: %d \n", penyimpanan[hitung].t);
                    printf("Luas Permukaan: %.2f \n", penyimpanan[hitung].luas);
                    printf("Volume: %.2f \n\n", penyimpanan[hitung].volume);
                }
                system("pause");
                break;

            case 5:
                system("cls");
                printf("File sedang di print... \n");
                FILE *filepointer;
                filepointer = fopen("Hasil.txt", "w");
                for(ProgramCounter = 0; ProgramCounter < i; ProgramCounter++) {
                    fprintf(filepointer, "%d#%d#%d#%.2f#%.2f \n", ProgramCounter+1, penyimpanan[ProgramCounter].r,
                            penyimpanan[ProgramCounter].t, penyimpanan[ProgramCounter].luas, penyimpanan[ProgramCounter].volume);
                }
                fclose(filepointer);
                printf("History operasi telah selesai di print dalam file yang bernama Hasil.txt. \n");
                system("pause");
                break;
            case 6:
                exit(0);
                break;
        }
    }
    return 0;
}
