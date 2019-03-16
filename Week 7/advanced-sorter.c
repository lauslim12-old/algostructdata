#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

struct mahasiswa {
    char nama[30];
    int nilaiTugas[15];
    int nilaiAkhir;

    struct mahasiswa *next, *prev;
} mahasiswa;

typedef struct dataku {
    char nama[30];
    int nilaiTugas[15];
    int nilaiAkhir;
} dataku;

void Mainmenu() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                    Grade Sorter by Nicholas Dwiarto                                     \n");
    printf("======================================================================================================== \n");
    printf("1. Input Data \n");
    printf("2. Sort Data \n");
    printf("3. Exit \n");
}

void Sort() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                          Choose your algorithm!                                         \n");
    printf("======================================================================================================== \n");
    printf("1. Quick Sort \n");
    printf("2. Merge Sort \n");
    printf("3. Shell Sort \n");
}

void Opsi() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                             Sorting options?                                            \n");
    printf("======================================================================================================== \n");
    printf("1. Ascending \n");
    printf("2. Descending \n");
}

void Pilihan() {
    printf("1. Next \n");
    printf("2. Prev \n");
    printf("3. Exit \n");
}

/* Sorting Algorithms */
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Quick Sorting
int partition (int *bil, int l, int r){
    int pivot = bil[r];
    int i = l - 1;
    int j;
    for (j = l; j <= r-1; j++){
        if(bil[j] <= pivot){
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i + 1], &bil[r]);
    return (i + 1);
}

void quicksort(int *bil, int l, int r){
    if(l < r){
        int pi = partition(bil, l, r);
        quicksort(bil, l, pi - 1);
        quicksort(bil, pi + 1, r);
    }
}

// Descending
int partitionD (int *bil, int l, int r){
    int pivot = bil[r];
    int i = l - 1;
    int j;
    for (j = l; j <= r-1; j++){
        if(bil[j] >= pivot){
            i++;
            swap(&bil[i], &bil[j]);
        }
    }
    swap(&bil[i + 1], &bil[r]);
    return (i + 1);
}

void quicksortD(int *bil, int l, int r){
    if(l < r){
        int pi = partitionD(bil, l, r);
        quicksortD(bil, l, pi - 1);
        quicksortD(bil, pi + 1, r);
    }
}
// End of Quick Sorting

// Start of Merge Sorting
void mergeA(int *bil, int l, int m, int r){
    int i,j,k;
    //banyak data disisi kiri
    int n1 = m - l + 1;
    //banyak data disisi kanan
    int n2 = r - m;

    //membuat array sementara untuk bilangan di kiri
    int L[n1];

    // array sementara bilangan kanan
    int R[n2];

    // menyalin bilangan di sisi kiri ke array L[]
    for(i = 0; i < n1; i++){
        L[i] = bil[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = bil[m + 1 + j];
    }
    i = 0;// iterator sisi kiri
    j = 0;// iterator sisi kanan
    k = l;// iterator untuk gabungin lagi

    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            bil[k]= L[i];
            i++;
        }
        else {
            bil[k]= R[j];
            j++;
        }
        k++;
    }

    // menyalin jika ada elemen yang tersisa dari L[]
    while( i < n1){
        bil[k] = L[i];
        i++;
        k++;
    }
}

void mergesortA(int *bil, int l, int r){
    if( l < r){
        int m = (l+r)/2;

        mergesortA(bil, l, m);
        mergesortA(bil, m+1, r);

        // proses ketika sudah menelusuri semua bagian kanan dan kiri
        mergeA(bil, l, m, r);
    }
}

// Descending Sort
void mergeD(int *bil, int l, int m, int r){
    int i,j,k;
    //banyak data disisi kiri
    int n1 = m - l + 1;
    //banyak data disisi kanan
    int n2 = r - m;

    //membuat array sementara untuk bilangan di kiri
    int L[n1];

    // array sementara bilangan kanan
    int R[n2];

    // menyalin bilangan di sisi kiri ke array L[]
    for(i = 0; i < n1; i++){
        L[i] = bil[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = bil[m + 1 + j];
    }
    i = 0;// iterator sisi kiri
    j = 0;// iterator sisi kanan
    k = l;// iterator untuk gabungin lagi

    while(i < n1 && j < n2){
        if(L[i] >= R[j]){
            bil[k]= L[i];
            i++;
        }
        else {
            bil[k]= R[j];
            j++;
        }
        k++;
    }

    // menyalin jika ada elemen yang tersisa dari L[]
    while( i < n1){
        bil[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        bil[k] = R[j];
        j++;
        k++;
    }
}

void mergesortD(int *bil, int l, int r){
    if(l < r){
        int m = (l+r)/2;

        mergesortD(bil, l, m);
        mergesortD(bil, m+1, r);

        // proses ketika sudah menelusuri semua bagian kanan dan kiri
        mergeD(bil, l, m, r);
    }
}


// End of Merge Sorting

// Start of Shell Sorting
void shellsortA(int *arr, int n){
    int i, j, gap;

    for(gap = n/2; gap > 0; gap /= 2){
        //lakukan insertion sort untuk gap size ini
        for(i = gap; i < n; i++){
            //simpan arr[i] ke temp
            int temp = arr[i];
            // pindahkan nilai yang benar ke tempat seharusnya
            for(j = i; j >= gap && arr[j - gap] > temp; j-= gap)
                arr[j] = arr[j - gap];

                // taruh temp ke lokasi yang benar
                arr[j] =  temp;
        }
    }
}

// Descending Sort
void shellsortD(int *arr, int n){
    int i, j, gap;

    for(gap = n/2; gap > 0; gap /= 2){
        //lakukan insertion sort untuk gap size ini
        for(i = gap; i < n; i++){
            //simpan arr[i] ke temp
            int temp = arr[i];
            // pindahkan nilai yang benar ke tempat seharusnya
            for(j = i; j >= gap && arr[j - gap] < temp; j-= gap)
                arr[j] = arr[j - gap];

                // taruh temp ke lokasi yang benar
                arr[j] =  temp;

        }
    }
}
// End of Shell Sorting

int main() {
    // Variables for Linked List
    struct mahasiswa *head, *curr, *node, *tail, *temp;
    head = curr = tail = NULL;
    char nama[30];
    int nilaiTugas[15], nilaiAkhir;

    // Utility variables
    dataku dataku[500];
    int pilihanMenu, pilihanSort, pilihanOpsi, pilihanData, nilaiKe, i, j, banyak;
    int dataSekarang = 0, hasilRerata = 0, currentData = 1;

    while(1) {
        Awal:
        Mainmenu();
        printf("Choose your input: ");
        scanf("%d", &pilihanMenu);

        switch(pilihanMenu) {
            case 1:
                system("cls");
                nilaiKe = 1;
                printf("Masukkan nama Anda dan 14 nilai anda! \n");
                fflush(stdin);
                printf("Nama: "); scanf("%[^\n]", dataku[dataSekarang].nama);

                for(i = 0; i < 14; i++) {
                    printf("Nilai ke %d: ", nilaiKe);
                    nilaiKe++;
                    scanf("%d", &dataku[dataSekarang].nilaiTugas[i]);
                }

                printf("Data berhasil dimasukkan! \n");
                dataSekarang++;
                system("pause");
                break;

            case 2:
                PilihSorting:
                system("cls");
                Opsi();
                printf("Input: "); scanf("%d", &pilihanOpsi);
                switch(pilihanOpsi) {
                    case 1:
                        Sort();
                        printf("Pilih input sorting: ");
                        scanf("%d", &pilihanSort);
                        switch(pilihanSort) {
                            case 1:
                                for(i = 0; i < dataSekarang; i++) {
                                    quicksort(dataku[i].nilaiTugas, 0, 13);

                                    for(j = 4; j < 14; j++) {
                                        hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                    }
                                    hasilRerata = hasilRerata / 10;
                                    dataku[i].nilaiAkhir = hasilRerata;
                                    hasilRerata = 0;
                                }
                                printf("Dataset telah di sortir secara ascending dengan metode Quick Sort! \n");
                                system("pause");
                                goto LinkedList;
                                break;

                            case 2:
                                for(i = 0; i < dataSekarang; i++) {
                                    mergesortA(dataku[i].nilaiTugas, 0, 13);

                                    for(j = 4; j < 14; j++) {
                                        hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                    }
                                    hasilRerata = hasilRerata / 10;
                                    dataku[i].nilaiAkhir = hasilRerata;
                                    hasilRerata = 0;
                                }
                                printf("Dataset telah di sortir secara ascending dengan metode Merge Sort! \n");
                                system("pause");
                                goto LinkedList;
                                break;

                            case 3:
                                for(i = 0; i < dataSekarang; i++) {
                                    shellsortA(dataku[i].nilaiTugas, 14);

                                    for(j = 4; j < 14; j++) {
                                        hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                    }
                                    hasilRerata = hasilRerata / 10;
                                    dataku[i].nilaiAkhir = hasilRerata;
                                    hasilRerata = 0;
                                }
                                printf("Dataset telah di sortir secara ascending dengan metode Shell Sort! \n");
                                system("pause");
                                goto LinkedList;
                                break;

                            default:
                                printf("Invalid input. Enter a valid one. \n");
                                system("pause");
                                goto PilihSorting;
                        }
                        // End of Ascending Sort.

                    case 2:
                        Sort();
                        printf("Pilih input sorting: ");
                        scanf("%d", &pilihanSort);
                        switch(pilihanSort) {
                            case 1:
                                for(i = 0; i < dataSekarang; i++) {
                                    quicksortD(dataku[i].nilaiTugas, 0, 13);

                                    for(j = 4; j < 14; j++) {
                                        hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                    }
                                    hasilRerata = hasilRerata / 10;
                                    dataku[i].nilaiAkhir = hasilRerata;
                                    hasilRerata = 0;
                                }
                                printf("Dataset telah di sortir secara descending dengan metode Quick Sort! \n");
                                system("pause");
                                break;

                            case 2:
                                for(i = 0; i < dataSekarang; i++) {
                                    mergesortD(dataku[i].nilaiTugas, 0, 13);

                                    for(j = 4; j < 14; j++) {
                                        hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                    }
                                    hasilRerata = hasilRerata / 10;
                                    dataku[i].nilaiAkhir = hasilRerata;
                                    hasilRerata = 0;
                                }
                                printf("Dataset telah di sortir secara descending dengan metode Merge Sort! \n");
                                system("pause");
                                break;

                         case 3:
                            for(i = 0; i < dataSekarang; i++) {
                                shellsortD(dataku[i].nilaiTugas, 14);

                                for(j = 4; j < 14; j++) {
                                    hasilRerata = hasilRerata + dataku[i].nilaiTugas[j];
                                }
                                hasilRerata = hasilRerata / 10;
                                dataku[i].nilaiAkhir = hasilRerata;
                                hasilRerata = 0;
                            }
                            printf("Dataset telah di sortir secara descending dengan metode Shell Sort! \n");
                            system("pause");
                            break;

                        default:
                            printf("Invalid input. Enter a valid one. \n");
                            system("pause");
                            goto PilihSorting;
                        // End of Descending Sort
                        }
                }

                // Making a Doubly Linked List
                LinkedList:
                for(i = 0; i < dataSekarang; i++) {
                    node = (struct mahasiswa*)malloc(sizeof(struct mahasiswa));
                    node->next = NULL;
                    node->prev = NULL;
                    strcpy(node->nama, dataku[i].nama);
                    for(j = 0; j < 14; j++) {
                        node->nilaiTugas[j] = dataku[i].nilaiTugas[j];
                    }
                    node->nilaiAkhir = dataku[i].nilaiAkhir;

                    if(head == NULL) {
                        head = node;
                        tail = node;
                        head->next = NULL;
                        tail->next = NULL;
                    }
                    else {
                        tail->next = node;
                        node->prev = tail;
                        tail = node;
                    }
                    // tail->next = head;
                    // head->prev = tail;
                }

                // Displaying the data from the Linked List.
                system("cls");
               // curr = head;
                printf("======================================================================================================== \n");
                printf("                                           Sorted Data                                                   \n");
                printf("======================================================================================================== \n");

                while(head != NULL) {
                    printf("Nomor       : %d / %d\n", currentData, dataSekarang);
                    printf("Nama        : %s \n", head->nama);
                    for(i = 0; i < 14; i++) {
                        printf("Nilai ke %d : %d \n", i+1, head->nilaiTugas[i]);
                    }
                    printf("Nilai Final : %d \n", head->nilaiAkhir);
                    printf("--------------------- \n");
                    currentData++;
                    head = head->next;
                }
                currentData = 1;
                system("pause");
                goto Awal;
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid input. Please retry! \n");
                system("pause");
            }
        }
    return 0;
}

/* Alternative way to place data in linked lists. I do not prefer them, though.
    while(1) {
        system("cls");
        printf("======================================================================================================== \n");
        printf("                                           Sorted Data                                                   \n");
        printf("======================================================================================================== \n");
        printf("Nomor       : %d / %d\n", currentData, dataSekarang);
        printf("Nama        : %s \n", curr->nama);
        for(i = 0; i < 14; i++) {
            printf("Nilai ke %d : %d \n", i+1, curr->nilaiTugas[i]);
        }
        printf("Nilai Final : %d \n", curr->nilaiAkhir);
        Pilihan();
        printf("Input   : "); scanf("%d", &pilihanData);
        switch(pilihanData) {
            case 1:
                curr = curr->next;
                if(currentData + 1 > dataSekarang){
                    currentData = 1;
                }
                else {
                    currentData++;
                }
                break;

            case 2:
                curr = curr->prev;
                if(currentData - 1 == 0){
                    currentData = 1;
                }
                else {
                    currentData--;
                }
                break;

            case 3:
                banyak = 1;
                while(banyak > 0){
                    temp = head;
                    head = head->next;
                    free(temp);
                    banyak--;
                }
                system("pause");
                goto Awal;
                break;

            default:
                printf("Invalid input!");
            }
    }



*/
