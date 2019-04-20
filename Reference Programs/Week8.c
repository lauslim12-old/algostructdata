#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structures to hold the data
struct data {
    char id[10], nama[50], bidang[50], jenis[20];
};

// Menus
void MainMenu() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                 Daftar Kegiatan by Nicholas Dwiarto                                     \n");
    printf("======================================================================================================== \n");
    printf("1. Tampilkan Kegiatan \n");
    printf("2. Urutkan Kegiatan \n");
    printf("3. Cari Kegiatan \n");
    printf("4. Tambah Kegiatan \n");
    printf("5. Exit Program \n");
    printf("Input: ");
}

void DisplayData() {
    system("cls");
    printf("======================================================================================================================= \n");
    printf("                                             Daftar Kegiatan                                                            \n");
    printf("======================================================================================================================= \n");
    printf("\n");

    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    printf("| %-2s | %-45s | %-30s | %-30s |\n", "ID", "Nama", "Bidang", "Jenis");
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
}

void TampilanKegiatan() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                        Tampilan Kegiatan                                                \n");
    printf("======================================================================================================== \n");
    printf("1. Tampilkan Semua \n");
    printf("2. Tampilkan Berdasarkan Jenis Kegiatan \n");
    printf("3. Tampilkan Berdasarkan Bidang \n");
    printf("4. Kembali \n");
    printf("Input: ");
}

void TampilanSorting() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                        Tampilan Sorting                                                 \n");
    printf("======================================================================================================== \n");
    printf("1. Bubble Sort \n");
    printf("2. Selection Sort \n");
    printf("3. Merge Sort \n");
    printf("4. Kembali \n");
    printf("Input: ");
}

void TampilanSearching() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                        Tampilan Searching                                               \n");
    printf("======================================================================================================== \n");
    printf("1. Sequential Search \n");
    printf("2. Binary Search \n");
    printf("3. Interpolation Search \n");
    printf("4. Kembali \n");
    printf("Input: ");
}

void swap(struct data *penyimpanan1, struct data *penyimpanan2) {
    struct data temp;
    temp = *penyimpanan1;
    *penyimpanan1 = *penyimpanan2;
    *penyimpanan2 = temp;
}

void bubbleSort(struct data *penyimpanan, int jumlahData) {
    int i, j;

    for(i = 1; i < jumlahData; i++) {
        for(j = jumlahData-1; j >= 1; j--) {
            if(strcmp(penyimpanan[j].nama, penyimpanan[j-1].nama) < 0) {
                swap(&penyimpanan[j], &penyimpanan[j-1]);
            }
        }
    }
}

void selectionSort(struct data *penyimpanan, int jumlahData) {
    int i, j, temp;

    for(i = 0; i < jumlahData; i++) {
        temp = i;
        for(j = i+1; j < jumlahData; j++) {
            if(strcmp(penyimpanan[j].nama, penyimpanan[temp].nama) < 0) {
                temp = j;
            }
        }
        if(temp != i)
            swap(&penyimpanan[temp], &penyimpanan[i]);
    }
}

int main() {
    // Core Variables
    char id[10], nama[50], bidang[50], jenis[20];

    // Utility Variables
    int pil, pilihTampilan, pilihanSorting, pilihanSearching, telahSorting = 0;
    int jumlahData, i;
    char c, key[20];

    // File Operations
    FILE *data;

    // Count the number of lines.
    data = fopen("KegiatanUMN.txt", "r");
    jumlahData = 1;
    while(EOF != (fscanf(data, "%*[^\n]"), fscanf(data, "%*c"))) {
        ++jumlahData;
    }
    fclose(data);

    struct data *dataku = (struct data*)malloc(sizeof(struct data)*jumlahData);

    // Insert data from .txt to struct.
    data = fopen("KegiatanUMN.txt", "r");
    i = 0;
    while(!feof(data)) {
        fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &dataku[i].id, &dataku[i].nama, &dataku[i].bidang, &dataku[i].jenis);
        i++;
    }
    fclose(data);
    // File processing complete.

    while(1) {
        Utama:
        MainMenu();
        scanf("%d", &pil);

        switch(pil) {
            case 1:
                TampilanKegiatan();
                scanf("%d", &pilihTampilan);

                switch(pilihTampilan) {
                    case 1:
                        DisplayData();
                        data = fopen("KegiatanUMN.txt", "r");
                        while(!feof(data)) {
                            fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
                            printf("| %-2s | %-45s | %-30s | %-30s \n", id, nama, bidang, jenis);
                        }
                        printf("----------------------------------------------------------------------------------------------------------------------- \n");
                        fclose(data);
                        system("pause");
                        break;

                    case 2:
                        // Tampilan berdasarkan jenis kegiatan.
                        break;

                    case 3:
                        // Tampilan berdasarkan bidang.
                        break;

                    case 4:
                        goto Utama;
                        break;

                }
                break;

            case 2:
                if(telahSorting == 1) {
                    printf("Data telah di sorting sebelumnya! \n");
                    system("pause");
                }
                else {
                    TampilanSorting();
                    scanf("%d", &pilihanSorting);
                    switch(pilihanSorting) {
                        case 1:
                            data = fopen("KegiatanUMN.txt", "w");
                            bubbleSort(dataku, jumlahData);
                            for(i = 0; i < jumlahData; i++) {
                                fprintf(data, "%s#%s#%s#%s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            }
                            printf("Data telah berhasil di sort dengan Bubble Sort! \n");
                            fclose(data);
                            system("pause");
                            break;

                        case 2:
                            data = fopen("KegiatanUMN.txt", "w");
                            selectionSort(dataku, jumlahData);
                            for(i = 0; i < jumlahData; i++) {
                                fprintf(data, "%s#%s#%s#%s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            }
                            printf("Data telah berhasil di sort dengan Selection Sort! \n");
                            fclose(data);
                            system("pause");
                            break;
                        }
                        telahSorting = 1;
                }

            case 3:
                // Searching
                TampilanSearching();
                scanf("%d", &pilihanSearching);
                switch(pilihanSearching) {
                    case 1:
                        printf("Masukkan kata kunci! \n");
                        scanf("%s", keyword);
                        for(i = 0; i < jumlahData; i++) {
                            if(strcmpi())
                        }
                }

                break;

            case 4:
                // Tambah data.
                break;

            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}

