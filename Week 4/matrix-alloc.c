#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

void Layar() {
    system("cls");
    printf("Matrix Calculator \n");
    printf("1. Perkalian Matrix \n");
    printf("2. Penjumlahan Matrix \n");
    printf("3. Transpose Matrix \n");
    printf("4. Exit \n");
}

int main() {
    int pil, **matrix1, **matrix2, i, j, k, a;
    int **res, jumlah = 0;
    int **transpos1, **transpos2;

    while(1) {
        system("cls");

        // Allocating the memory
        matrix1 = (int**)malloc(sizeof(int*)*3);
        matrix2 = (int**)malloc(sizeof(int*)*3);
        res = (int**)malloc(sizeof(int*)*3);
        transpos1 = (int**)malloc(sizeof(int*)*3);
        transpos2 = (int**)malloc(sizeof(int*)*3);

        for(a = 0; a < 3; a++){
            matrix1[a] = (int*)malloc(sizeof(int)*3);
        }
        for(a = 0; a < 3; a++){
            matrix2[a] = (int*)malloc(sizeof(int)*3);
        }
        for(a = 0; a < 3; a++) {
            res[a] = (int*)malloc(sizeof(int)*3);
        }
        for(a = 0; a < 3; a++) {
            transpos1[a] = (int*)malloc(sizeof(int)*3);
        }
        for(a = 0; a < 3; a++) {
            transpos2[a] = (int*)malloc(sizeof(int)*3);
        }
        // End

        printf("Silakan masukkan matriks pertama. \n");
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("Masukkan matriks kedua. \n");
        for(i = 0; i < 3; i++) {
            for(j = 0; j < 3; j++) {
                scanf("%d", &matrix2[i][j]);
            }
        }
        system("cls");

        Layar();
        printf("Silakan masukkan nomor: ");
        scanf("%d", &pil);
        switch(pil) {
            case 1:
                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        for(k = 0; k < 3; k++) {
                            jumlah = jumlah + matrix1[i][k] * matrix2[k][j];
                        }
                        res[i][j] = jumlah;
                        jumlah = 0;
                    }
                }

                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        printf("%d \t", res[i][j]);
                    }
                    printf("\n");
                }
                system("pause");
                break;

            case 2:
                for(i = 0; i < 3; i ++) {
                    for(j = 0; j < 3; j++) {
                        res[i][j] = matrix1[i][j] + matrix2[i][j];
                        printf("%d \t", res[i][j]);
                    }
                    printf("\n");
                }
                system("pause");
                break;

            case 3:
                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        transpos1[j][i] = matrix1[i][j];
                    }
                }
                printf("Transpose matriks pertama adalah:  \n");
                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        printf("%d \t", transpos1[i][j]);
                    }
                    printf("\n");
                }

                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        transpos2[j][i] = matrix2[i][j];
                    }
                }
                printf("\nTranspose matrix kedua adalah: \n");
                for(i = 0; i < 3; i++) {
                    for(j = 0; j < 3; j++) {
                        printf("%d \t", transpos2[i][j]);
                    }
                    printf("\n");
                }
                system("pause");
                break;
            }
        }
    return 0;
}

