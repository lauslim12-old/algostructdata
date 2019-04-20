#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct data {
    char id[10], nama[50], bidang[50], jenis[20];
};

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
    char id[50], nama[50], bidang[50], jenis[50];
    int jumlahData, i;
    FILE *data;

    // Count the number of lines.
    data = fopen("KegiatanUMN.txt", "r");
    jumlahData = 1;
    while(EOF != (fscanf(data, "%*[^\n]"), fscanf(data, "%*c"))) {
        ++jumlahData;
    }

    printf("Jumlah baris: %d \n", jumlahData);
    fclose(data);

    struct data *dataku = (struct data*)malloc(sizeof(struct data)*jumlahData);

    // Insert data from .txt to struct.
    printf("\n");
    printf("Data dalam file: \n");
    data = fopen("KegiatanUMN.txt", "r");
    i = 0;
    while(!feof(data)) {
        fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &dataku[i].id, &dataku[i].nama, &dataku[i].bidang, &dataku[i].jenis);
        printf("%s#%s#%s#%s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
        i++;
    }
    fclose(data);
    // End

    // Insert data from .txt to array for merge sorting.
    // code.
    // End

    // Display struct
    printf("\n\n");
    i = 0;
    printf("Data dalam struct: \n");
    while(i < jumlahData) {
        printf("%s#%s#%s#%s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
        i++;
    }
    // End

    // Before the data is sorted from file.
    printf("\n\n");
    printf("Data sebelum di sort: \n");
    printf("----------------------------------------------------------------------------------------------------------------------- ");
    data = fopen("KegiatanUMN.txt", "r");
    while(!feof(data)) {
        fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
        printf("| %-2s | %-45s | %-30s | %-30s \n", id, nama, bidang, jenis);
    }
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    fclose(data);
    getch();
    // End of initialization.

    // Bubble Sorting.
    printf("Data setelah di sort: \n");
    bubbleSort(dataku, jumlahData);
    printf("----------------------------------------------------------------------------------------------------------------------- ");
    for(i = 0; i < jumlahData; i++) {
        printf("| %-2s | %-45s | %-30s | %-30s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
    }
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    // End

    // Selection Sorting.
    printf("Data setelah di sort: \n");
    selectionSort(dataku, jumlahData);
    printf("----------------------------------------------------------------------------------------------------------------------- ");
    for(i = 0; i < jumlahData; i++) {
        printf("| %-2s | %-45s | %-30s | %-30s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
    }
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    // End

    // Merge Sorting.
    // code.
    // End

    // Write to file.
    data = fopen("KegiatanUMN.txt", "w");
    for(i = 0; i < jumlahData; i++) {
        fprintf(data, "%s#%s#%s#%s \n", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
    }
    fclose(data);
    getch();
    // End

    return 0;
}
