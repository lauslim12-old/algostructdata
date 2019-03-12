#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

// Menus
void Menu() {
    system("cls");
    printf("====================================================== \n");
    printf("              Sorter by Nicholas Dwiarto               \n");
    printf("====================================================== \n");
    printf("1. Enter Data \n");
    printf("2. Bubble Sort \n");
    printf("3. Selection Sort \n");
    printf("4. Insertion Sort \n");
    printf("5. Exit \n");
}

void Sort() {
    printf("Sorting Type: \n");
    printf("1. Ascending \n");
    printf("2. Descending \n");
    printf("Choice: ");
}
// End

// Sorting Algorithms and Structure to hold the data.
struct data {
    int tinggi, berat;
    char nama[500];
};

void swap(struct data *penyimpanan1, struct data *penyimpanan2) {
    struct data temp;
    temp = *penyimpanan1;
    *penyimpanan1 = *penyimpanan2;
    *penyimpanan2 = temp;
}

void bubbleSort(struct data *penyimpanan, int jumlahData) {
    int i, j, pil;

    system("cls");
    Sort();
    scanf("%d", &pil);

    if(pil == 1) {
        for(i = 1; i < jumlahData; i++) {
            for(j = jumlahData-1; j >= 1; j--) {
                if(strcmp(penyimpanan[j].nama, penyimpanan[j-1].nama) < 0) {
                    swap(&penyimpanan[j], &penyimpanan[j-1]);
                }
                else if(strcmp(penyimpanan[j].nama, penyimpanan[j-1].nama) == 0) {
                    if(penyimpanan[j].tinggi < penyimpanan[j-1].tinggi) {
                        swap(&penyimpanan[j], &penyimpanan[j-1]);
                    }
                    else if(penyimpanan[j].tinggi == penyimpanan[j-1].tinggi) {
                        if(penyimpanan[j].berat < penyimpanan[j-1].berat) {
                            swap(&penyimpanan[j], &penyimpanan[j-1]);
                        }
                    }
                }
            }
        }
    }

    else if(pil == 2) {
        for(i = 1; i < jumlahData; i++) {
            for(j = jumlahData-1; j >= 1; j--) {
                if(strcmp(penyimpanan[j].nama, penyimpanan[j-1].nama) > 0) {
                    swap(&penyimpanan[j], &penyimpanan[j-1]);
                }
                else if(strcmp(penyimpanan[j].nama, penyimpanan[j-1].nama) == 0) {
                    if(penyimpanan[j].tinggi > penyimpanan[j-1].tinggi) {
                        swap(&penyimpanan[j], &penyimpanan[j-1]);
                    }
                    else if(penyimpanan[j].tinggi == penyimpanan[j-1].tinggi) {
                        if(penyimpanan[j].berat > penyimpanan[j-1].berat) {
                            swap(&penyimpanan[j], &penyimpanan[j-1]);
                        }
                    }
                }
            }
        }
    }
}

void selectionSort(struct data *penyimpanan, int jumlahData) {
    int i, j, temp, pilih;

    system("cls");
    Sort();
    scanf("%d", &pilih);

    if(pilih == 1) {
        for(i = 0; i < jumlahData; i++) {
            temp = i;
            for(j = i+1; j < jumlahData; j++) {
                if(penyimpanan[j].tinggi < penyimpanan[temp].tinggi) {
                    temp = j;
                }
                else if(penyimpanan[j].tinggi == penyimpanan[temp].tinggi) {
                    if(penyimpanan[j].berat < penyimpanan[temp].berat) {
                        temp = j;
                    }
                    else if(penyimpanan[j].berat == penyimpanan[temp].berat) {
                        if(strcmp(penyimpanan[j].nama, penyimpanan[temp].nama) < 0) {
                            temp = j;
                        }
                    }
                }
            }
            if(temp != i)
                swap(&penyimpanan[temp], &penyimpanan[i]);
        }
    }

    else if(pilih == 2) {
        for(i = 0; i < jumlahData; i++) {
            temp = i;
            for(j = i+1; j < jumlahData; j++) {
                if(penyimpanan[j].tinggi > penyimpanan[temp].tinggi) {
                    temp = j;
                }
                else if(penyimpanan[j].tinggi == penyimpanan[temp].tinggi) {
                    if(penyimpanan[j].berat > penyimpanan[temp].berat) {
                        temp = j;
                    }
                    else if(penyimpanan[j].berat == penyimpanan[temp].berat) {
                        if(strcmp(penyimpanan[j].nama, penyimpanan[temp].nama) > 0) {
                            temp = j;
                        }
                    }
                }
            }
            if(temp != i)
                swap(&penyimpanan[temp], &penyimpanan[i]);
        }
    }
}

void insertionSort(struct data *penyimpanan, int jumlahData) {
    int i, j, pilihan;
    struct data temp;

    system("cls");
    Sort();
    scanf("%d", &pilihan);

    if(pilihan == 1) {
        for(i = 1; i < jumlahData; i++) {
            temp = penyimpanan[i];
            for(j = i - 1; j >= 0 && penyimpanan[j].berat > temp.berat; j--) {
                if(penyimpanan[j].berat == temp.berat) {
                    if(strcmp(penyimpanan[j].nama, temp.nama) > 0) {
                        penyimpanan[j+1] = penyimpanan[j];
                    }
                    else if(strcmp(penyimpanan[j].nama, temp.nama) == 0) {
                        if(penyimpanan[j].tinggi > temp.tinggi) {
                            penyimpanan[j+1] = penyimpanan[j];
                        }
                    }
                }
                else if(penyimpanan[j].berat > temp.berat) {
                    penyimpanan[j+1] = penyimpanan[j];
                }
            }
            penyimpanan[j+1] = temp;
        }
    }

    else if(pilihan == 2) {
        for(i = 0; i < jumlahData; i++) {
            temp = penyimpanan[i];
            for(j = i - 1; j >= 0 && penyimpanan[j].berat < temp.berat; j--) {
                if(penyimpanan[j].berat == temp.berat) {
                    if(strcmp(penyimpanan[j].nama, temp.nama) < 0) {
                        penyimpanan[j+1] = penyimpanan[j];
                    }
                    else if(strcmp(penyimpanan[j].nama, temp.nama) == 0) {
                        if(penyimpanan[j].tinggi < temp.tinggi) {
                            penyimpanan[j+1] = penyimpanan[j];
                        }
                    }
                }
                else if(penyimpanan[j].berat < temp.berat) {
                    penyimpanan[j+1] = penyimpanan[j];
                }
            }
            penyimpanan[j+1] = temp;
        }
    }
}

int main() {
    // Variables for the main
    int pil, jumlahData, i;

    // Introduction
    printf("Tulis jumlah data yang ingin dimasukkan: ");
    scanf("%d", &jumlahData);

    // Memory allocation
    struct data *penyimpanan = (struct data*)malloc(sizeof(struct data)*jumlahData);

    while(1) {
        Menu();
        scanf("%d", &pil);
        switch(pil) {
            case 1:
                for(i = 0; i < jumlahData; i++) {
                    system("cls");
                    printf("====================================================== \n");
                    printf("                      Enter Data                       \n");
                    printf("====================================================== \n");
                    printf("Insert name: "); fflush(stdin); scanf("%[^\n]", penyimpanan[i].nama);
                    printf("Insert your height: "); scanf("%d", &penyimpanan[i].tinggi);
                    printf("Insert your weight: "); scanf("%d", &penyimpanan[i].berat);
                    printf("Data berhasil dimasukkan! \n");
                    system("pause");
                }
                break;

            case 2:
                bubbleSort(penyimpanan, jumlahData);
                printf("Data setelah bubble sorting: \n");
                for (i = 0; i < jumlahData; i++) {
                    printf("Data ke %d: \n", i+1);
                    printf("Nama   : %s \n", penyimpanan[i].nama);
                    printf("Tinggi : %d \n", penyimpanan[i].tinggi);
                    printf("Berat  : %d \n", penyimpanan[i].berat);
                }
                system("pause");
                break;

            case 3:
                selectionSort(penyimpanan, jumlahData);
                printf("Data setelah selection sorting: \n");
                for (i = 0; i < jumlahData; i++) {
                    printf("Data ke %d: \n", i+1);
                    printf("Nama   : %s \n", penyimpanan[i].nama);
                    printf("Tinggi : %d \n", penyimpanan[i].tinggi);
                    printf("Berat  : %d \n", penyimpanan[i].berat);
                }
                system("pause");
                break;

            case 4:
                insertionSort(penyimpanan, jumlahData);
                printf("Data setelah insertion sorting: \n");
                for (i = 0; i < jumlahData; i++) {
                    printf("Data ke %d: \n", i+1);
                    printf("Nama   : %s \n", penyimpanan[i].nama);
                    printf("Tinggi : %d \n", penyimpanan[i].tinggi);
                    printf("Berat  : %d \n", penyimpanan[i].berat);
                }
                system("pause");
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Invalid input! Mohon ketik ulang!");
                system("pause");

        }
    }
    return 0;
}
