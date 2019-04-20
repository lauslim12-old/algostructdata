#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct data {
    char id[10], nama[50], bidang[50], jenis[20];
};

void Merge(char* arr[],int low,int mid,int high) //Merging the Array Function
{
    int nL= mid-low+1;
    int nR= high-mid;

    char* L[100];
    char* R[100];
    int i;
    for(i=0;i<nL;i++) {
        L[i]= malloc(sizeof(arr[low+i])*10);
        strcpy(L[i],arr[low+i]);
    }

    for(i=0;i<nR;i++) {
        R[i]=malloc(sizeof(arr[mid+i+1])*10);
        strcpy(R[i],arr[mid+i+1]);
    }

    int j=0,k;
    i=0;
    k=low;

    while(i<nL&&j<nR) {
        if(strcmp(L[i],R[j])<0)strcpy(arr[k++],L[i++]);
        else strcpy(arr[k++],R[j++]);
    }
    while(i<nL)strcpy(arr[k++],L[i++]);
    while(j<nR)strcpy(arr[k++],R[j++]);

}

void MergeSort(char* arr[],int low,int high) //Main MergeSort function
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}


int main() {
    int i, jumlahData;
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
    char **arr = malloc(sizeof(char*)*10000);

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

    // Insert into array.
    printf("\n");
    printf("Data dalam array: \n");
    data = fopen("KegiatanUMN.txt", "r");
    i = 0;
    while(!feof(data)) {
        arr[i] = malloc(sizeof(char)*jumlahData);
        fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &dataku[i].id, arr[i], &dataku[i].bidang, &dataku[i].jenis);
        printf("%s#%s#%s#%s \n", dataku[i].id, arr[i], dataku[i].bidang, dataku[i].jenis);
        i++;
    }
    fclose(data);

    // Print to console.
    printf("\n");
    printf("Hasil sorting Merge: \n");
    printf("----------------------------------------------------------------------------------------------------------------------- ");
    MergeSort(arr, 0, jumlahData-1);
    for(i = 0; i < jumlahData; i++) {
        printf("| %-2s | %-45s | %-30s | %-30s \n", dataku[i].id, arr[i], dataku[i].bidang, dataku[i].jenis);
    }
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    return 0;
}
