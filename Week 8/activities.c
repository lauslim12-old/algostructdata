#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <malloc.h>

/*  Information (gabut):
    ----------------------------------------------------------------------------------------------------------------------------------
    Sorting Algorithms used: Bubble Sort, Insertion Sort, Selection Sort, and the more advanced Merge Sort, and Quick Sort.
    Searching Algorithms used: Sequential Search, Binary Search, and Interpolation Search.
    Unique Algorithms used: Storing in arrays for merge sorting and interpolation searching.
    Coded with <3 by Nicholas Dwiarto.
    Website: nicholasdw.com (Homepage)
    LinkedIn: https://www.linkedin.com/in/nicholasdwiarto/
    Instagram: @nicholasnwr.
    Ask me for GitHub and other accounts.
    ----------------------------------------------------------------------------------------------------------------------------------
*/

// Structures to hold the data
struct data {
    int id;
	char nama[50], bidang[50], jenis[20];
    int idTemp;
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
    printf("2. Selection Sort\n");
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

void TambahData() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                        Tampilan Tambah Data                                             \n");
    printf("======================================================================================================== \n");
    printf("Jenis: \t\t\t Bidang \n");
    printf("- UKM \t\t\t - Olahraga \n");
    printf("- Komunitas \t\t - Sains dan Sosial \n");
    printf("- LSO \t\t\t - Seni & Budaya \n");
    printf("\t\t\t - Unspecified \n\n");
}


// Sorting Algorithms
void swap(struct data *penyimpanan1, struct data *penyimpanan2) {
    struct data temp;
    temp = *penyimpanan1;
    *penyimpanan1 = *penyimpanan2;
    *penyimpanan2 = temp;
}

void swapQ(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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

void insertionSort(struct data *penyimpanan, int jumlahData, int tipeSorting) {
    int i, j;
    struct data temp;

    if(tipeSorting == 1) {
        for(i = 1; i < jumlahData; i++) {
            temp = penyimpanan[i];
            for(j = i - 1; j >= 0 && strcmp(penyimpanan[j].jenis, temp.jenis) > 0; j--) {
                if(strcmp(penyimpanan[j].jenis, temp.jenis) != 0) {
                    penyimpanan[j+1] = penyimpanan[j];
                }
            }
            penyimpanan[j+1] = temp;
        }
    }
    else {
        for(i = 1; i < jumlahData; i++) {
            temp = penyimpanan[i];
            for(j = i - 1; j >= 0 && strcmp(penyimpanan[j].bidang, temp.bidang) > 0; j--) {
                if(strcmp(penyimpanan[j].bidang, temp.bidang) != 0) {
                    penyimpanan[j+1] = penyimpanan[j];
                }
            }
            penyimpanan[j+1] = temp;
        }
    }
}

void Merge(char* arr[], int low, int mid, int high) {
    int nL = mid - low + 1;
    int nR = high - mid;

    char* L[100];
    char* R[100];
    int i;
    for(i = 0; i < nL; i++) {
        L[i] = malloc(sizeof(arr[low+i])*10);
        strcpy(L[i], arr[low+i]);
    }

    for(i = 0; i < nR; i++) {
        R[i] = malloc(sizeof(arr[mid+i+1])*10);
        strcpy(R[i], arr[mid+i+1]);
    }

    int j = 0, k;
    i = 0;
    k = low;

    while(i < nL && j < nR) {
        if(strcmp(L[i],R[j])<0) {
            strcpy(arr[k++],L[i++]);
        }
        else {
            strcpy(arr[k++],R[j++]);
        }
    }

    while(i < nL) {
        strcpy(arr[k++],L[i++]);
    }

    while(j < nR) {
        strcpy(arr[k++],R[j++]);
    }

}

void MergeSort(char* arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

// Quick Sorting for interpolation search
int partition (int *bil, int l, int r){
    int pivot = bil[r];
    int i = l - 1;
    int j;
    for (j = l; j <= r-1; j++){
        if(bil[j] <= pivot){
            i++;
            swapQ(&bil[i], &bil[j]);
        }
    }
    swapQ(&bil[i + 1], &bil[r]);
    return (i + 1);
}

void quicksort(int *bil, int l, int r){
    if(l < r){
        int pi = partition(bil, l, r);
        quicksort(bil, l, pi - 1);
        quicksort(bil, pi + 1, r);
    }
}

// Interpolation Search
int interpolation_search(int data[], int n, int key) {
    int pos, low, high;
    low = 0;
    high = n - 1;
    do {
        pos = (key - data[low]) * (high - low) / (data[high] - data[low]) + low;
        if(data[pos] == key) return pos;
        if(data[pos] > key) high = pos - 1;
        else low = pos + 1;
    }
    while (key >= data[low] && key <= data[high]);
    return -1;
}

int main() {
    // Core Variables
    int id;
	char nama[50], bidang[50], jenis[20];
    struct data dataku[250];
    struct data temporaryDataku;

    // Utility Variables
    int pil, pilihTampilan, pilihanSorting, pilihanSearching, tipeSorting;
    int jumlahData, i, check = 0, r, j, interpolation[100], item, pos;
    char c, keyword[50];

    // File Operations
    FILE *data;
    srand(time(NULL));

    while(1) {
        Utama:
        MainMenu();

        // File processing and data insertions.
        data = fopen("KegiatanUMN.txt", "r");
        jumlahData = 1;
        while(EOF != (fscanf(data, "%*[^\n]"), fscanf(data, "%*c"))) {
            ++jumlahData;
        }
        fclose(data);

        // Inserting data to struct and array. Do this every time the program cycles.
        i = 0;
        data = fopen("KegiatanUMN.txt", "r");
        while(!feof(data)) {
            fscanf(data, "%d#%[^#]#%[^#]#%[^\n] \n", &dataku[i].id, &dataku[i].nama, &dataku[i].bidang, &dataku[i].jenis);
            i++;
        }
        fclose(data);

        char **arr = malloc(sizeof(char*)*1000);
        memset(interpolation, 0, sizeof(interpolation));

        data = fopen("KegiatanUMN.txt", "r");
        i = 0;
        while(!feof(data)) {
            arr[i] = malloc(sizeof(char)*jumlahData);
            fscanf(data, "%d#%[^#]#%[^#]#%[^\n] \n", &interpolation[i], arr[i], &dataku[i].bidang, &dataku[i].jenis);
            i++;
        }
        fclose(data);
        // End of file processing. Proceed with the program.

        scanf("%d", &pil);

        switch(pil) {
            case 1:
                TampilanKegiatan();
                scanf("%d", &pilihTampilan);
                tipeSorting = 0;

                switch(pilihTampilan) {
                    case 1:
                        DisplayData();

                        data = fopen("KegiatanUMN.txt", "r");
                        while(!feof(data)) {
                            fscanf(data, "%d#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
                            printf("| %-2d | %-45s | %-30s | %-30s \n", id, nama, bidang, jenis);
                        }
                        printf("----------------------------------------------------------------------------------------------------------------------- \n");
                        fclose(data);

                        system("pause");
                        break;

                    case 2:
                        // Tampilan berdasarkan jenis kegiatan.
                        tipeSorting = 1;
                        data = fopen("KegiatanUMN.txt", "w");
                        insertionSort(dataku, jumlahData, tipeSorting);
                        for(i = 0; i < jumlahData; i++) {
                            fprintf(data, "%d#%s#%s#%s", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            if(i < jumlahData - 1) {
                            	fprintf(data, "\n");
							}
                        }
                        printf("Data telah di sort berdasarkan jenis dengan Insertion Sort! \n");
                        system("pause");
                        fclose(data);

                        DisplayData();
                        data = fopen("KegiatanUMN.txt", "r");
                        while(!feof(data)) {
                            fscanf(data, "%d#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
                            printf("| %-2d | %-45s | %-30s | %-30s \n", id, nama, bidang, jenis);
                        }
                        printf("----------------------------------------------------------------------------------------------------------------------- \n");
                        fclose(data);

                        system("pause");
                        break;

                    case 3:
                        // Tampilan berdasarkan bidang.
                        tipeSorting = 2;
                        data = fopen("KegiatanUMN.txt", "w");
                        insertionSort(dataku, jumlahData, tipeSorting);
                        for(i = 0; i < jumlahData; i++) {
                            fprintf(data, "%d#%s#%s#%s", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            if(i < jumlahData - 1) {
                            	fprintf(data, "\n");
							}
                        }
                        printf("Data telah di sort berdasarkan bidang dengan Insertion Sort! \n");
                        system("pause");
                        fclose(data);

                        DisplayData();
                        data = fopen("KegiatanUMN.txt", "r");
                        while(!feof(data)) {
                            fscanf(data, "%d#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
                            printf("| %-2d | %-45s | %-30s | %-30s \n", id, nama, bidang, jenis);
                        }
                        printf("----------------------------------------------------------------------------------------------------------------------- \n");
                        fclose(data);

                        system("pause");
                        break;

                    case 4:
                        goto Utama;
                        break;

                    default:
                        printf("Mohon input yang benar! \n");
                        system("pause");

                }
                break;

            case 2:
                TampilanSorting();
                scanf("%d", &pilihanSorting);
                switch(pilihanSorting) {
                    case 1:
                        data = fopen("KegiatanUMN.txt", "w");
                        bubbleSort(dataku, jumlahData);
                        for(i = 0; i < jumlahData; i++) {
                            fprintf(data, "%d#%s#%s#%s", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            if(i < jumlahData - 1) {
                            	fprintf(data, "\n");
							}
                        }

                        printf("Data telah berhasil di sort dengan Bubble Sort! \n");
                        fclose(data);
                        system("pause");
                        break;

                    case 2:
                        data = fopen("KegiatanUMN.txt", "w");
                        selectionSort(dataku, jumlahData);
                        for(i = 0; i < jumlahData; i++) {
                            fprintf(data, "%d#%s#%s#%s", dataku[i].id, dataku[i].nama, dataku[i].bidang, dataku[i].jenis);
                            if(i < jumlahData - 1) {
                            	fprintf(data, "\n");
							}
                        }
                        printf("Data telah berhasil di sort dengan Selection Sort! \n");
                        fclose(data);
                        system("pause");
                        break;

                    case 3:
                        // merge sort
                        printf("Karena ini hanya optional, maka saya hanya memasukkan ke array karena sulit untuk melakukan merge sort di structure. \n");
                        MergeSort(arr, 0, jumlahData-1);
                        printf("Data telah berhasil di sort dengan Merge Sort! \n");
                        system("pause");
                        system("cls");
                        printf("Sorted data is listed below: \n");
                        for(i = 0; i < jumlahData; i++) {
                            printf("Data ke: %d, %s \n", i+1, arr[i]);
                        }

                        system("pause");
                        break;

                    case 4:
                        goto Utama;
                        break;

                    default:
                        printf("Mohon input yang benar! \n");
                        system("pause");
                }
                break;

            case 3:
                // Searching
                check = 0;
                TampilanSearching();
                scanf("%d", &pilihanSearching);
                switch(pilihanSearching) {
                	case 1:
                		// Sequential search.
                		printf("Masukkan keyword: "); fflush(stdin);
                		scanf("%[^\n]", keyword);
                		for(i = 0; i < jumlahData; i++) {
                			if(strcmpi(dataku[i].nama, keyword) == 0) {
                				check = 1;
                				break;
							}
						}

						if(check == 1) {
							printf("Data ditemukan dengan metode Sequential Search! \n");
							printf("Nama: %s \n", dataku[i].nama);
							printf("ID: %d \n", dataku[i].id);
							printf("Jenis: %s \n", dataku[i].jenis);
							printf("Bidang: %s \n", dataku[i].bidang);
						}
						else {
							printf("Tidak ditemukan! \n");
						}
                		system("pause");
                		break;

                	case 2:
                		// Binary search.
                		check = 0;
						printf("Enter search key: "); fflush(stdin);
						scanf("%[^\n]", keyword);
					    i = 0;
					    int jumlahdata = jumlahData;
					    int low = 0;
					    int high = jumlahData - 1;
					    while(low <= high){
					        int mid;
						    mid = (low + high) / 2;
						    if(strcmpi(keyword, dataku[mid].nama) == 0){
					           check = 1;
					            i = mid;
					            break;
					        }
					        else if(strcmpi(keyword, dataku[mid].nama) < 0){
					            high = mid - 1;
						    }
						    else if(strcmpi(keyword, dataku[mid].nama) > 0){
							    low = mid + 1;
						    }
						}
					    if(check == 1){
					        printf("Data ditemukan dengan metode Binary Search! \n");
					        printf("Nama: %s \n", dataku[i].nama);
							printf("ID: %d \n", dataku[i].id);
							printf("Jenis: %s \n", dataku[i].jenis);
							printf("Bidang: %s \n", dataku[i].bidang);
						}
					    else{
					        printf("Data tidak ditemukan! \n");
					    }
					    system("pause");
					    break;

                    case 3:
                        // Interpolation search with ID.
                        for(i = 0; i < jumlahData; i++) {
                            quicksort(interpolation, 0, jumlahData-1);
                        }
                        printf("Sebelum melakukan searching interpolasi, sudah dilakukan Quick Sorting dalam ID. \n");
                        printf("Untuk sorting ini, mohon masukkan ID, bukan nama. \n");
                        printf("Search ID: "); fflush(stdin);
                        scanf("%d", &item);

                        pos = interpolation_search(interpolation, jumlahData, item);
                        if (pos == -1) {
                            printf("ID %d not found. \n", item);
                            system("pause");
                            goto Utama;
                        }
                        else {
                            printf("ID %d found at pos %d \n", item, pos);
                            j = 0;
                        }

                        // Comparing the interpolation array with the structure.
                        while(j != -1) {
                            if(dataku[j].id != item) {
                                j++;
                                printf("Searching... ");
                                printf("%d \t %d \n", item, dataku[j].id);
                            }
                            else {
                                printf("\n");
                                printf("Data yang ada: \n");
                                printf("Nama: %s \n", dataku[j].nama);
                                printf("ID: %d \n", dataku[j].id);
                                printf("Jenis: %s \n", dataku[j].jenis);
                                printf("Bidang: %s \n", dataku[j].bidang);
                                j = -1;
                            }
                        }
                        system("pause");

                        break;

                    case 4:
                        goto Utama;
                        system("pause");

                    default:
                        printf("Mohon input yang benar! \n");
                        system("pause");
				}
                break;

            case 4:
                // Tambah data.
                TambahData();
                printf("Masukkan data kegiatan di bawah ini! \n");
                printf("Nama: "); fflush(stdin); scanf("%[^\n]", temporaryDataku.nama);

                // Adding data with handlers.
                Jenis:
                printf("Jenis: "); fflush(stdin); scanf("%[^\n]", temporaryDataku.jenis);
                if(strcmpi("UKM", temporaryDataku.jenis) == 0 || strcmpi("Komunitas", temporaryDataku.jenis) == 0 || strcmpi("LSO", temporaryDataku.jenis) == 0) {
                    goto Bidang;
                }
                else {
                    printf("Data tidak valid! Mohon input data yang benar! \n");
                    system("pause");
                    goto Jenis;
                }

                Bidang:
                printf("Bidang: "); fflush(stdin); scanf("%[^\n]", temporaryDataku.bidang);
                if(strcmpi("Olahraga", temporaryDataku.bidang) == 0 || strcmpi("Sains & Sosial", temporaryDataku.bidang) == 0 || strcmpi("Seni & Budaya", temporaryDataku.bidang) == 0 || strcmpi("Unspecified", temporaryDataku.bidang) == 0) {
                    goto RNG;
                }
                else {
                    printf("Data tidak valid! Mohon input data yang benar! \n");
                    system("pause");
                    goto Bidang;
                }

                // Random Number Generator with ID checker.
                RNG:
                for(j = 0; j < jumlahData; j++) {
                    r = rand() % 100;
                    if(r == dataku[j].id){
                        continue;
                    }
                }
                printf("ID: %d \n", r);
                temporaryDataku.idTemp = r;

                data = fopen("KegiatanUMN.txt", "a");
                fprintf(data, "\n%d#%s#%s#%s", temporaryDataku.idTemp, temporaryDataku.nama, temporaryDataku.bidang, temporaryDataku.jenis);
                fclose(data);
                printf("Data telah diinput secara sempurna! \n");
                system("pause");
                break;

            case 5:
                exit(0);
                break;

            default:
                printf("Mohon input angka dengan benar! \n");
                system("pause");
        }

    }

    return 0;
}

