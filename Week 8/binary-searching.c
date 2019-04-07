#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 50

void sortStrings(char data[][MAX], int n)
{
    char temp[MAX];
    int i, j;

    // Sorting strings using bubble sort
    for (j=0; j<n-1; j++)
    {
        for (i=j+1; i<n; i++)
        {
            if (strcmp(data[j], data[i]) > 0)
            {
                strcpy(temp, data[j]);
                strcpy(data[j], data[i]);
                strcpy(data[i], temp);
            }
        }
    }
}

int main () {
    char data[10][50] = {"sapi","kambing","guguk","domba","ayam","bebek","burung","ikan","lebah","kuda"};
    int i;
    bool check = false;
    char key[20];

    // Sorting
    int n = sizeof(data)/sizeof(data[0]);
    printf("Jumlah data (n) = %d \n",n);
    sortStrings(data, n);
	for(i = 0; i < 10; i++) {
		printf("Data sorted: %s \n", data[i]);
	}

    printf("Masukan keyword: ");
    scanf("%s", &key);
    i = 0;
    int jumlahdata = 10;
    int low = 0;
    int high = jumlahdata - 1;
    while(low <= high){
        int mid;
        mid = (low + high) / 2;
        if(strcmpi(key, data[mid]) == 0){
            check = true;
            i = mid;
            break;
        }
        else if(strcmpi(key, data[mid]) < 0){
            high = mid - 1;
        }
        else if(strcmpi(key, data[mid]) > 0){
            low = mid + 1;
        }
    }
    if(check == true){
        printf("Data ditemukan! \n");
        printf("Nama data: %s \n", data[i]);
    }
    else {
        printf("Data tidak ditemukan! \n");
    }
    return 0;
}
