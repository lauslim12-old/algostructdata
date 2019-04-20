#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void swap(int *bil1, int *bil2) {
    int temp = *bil1;
    *bil1 = *bil2;
    *bil2 = temp;
}

void printArray(int *bil, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", bil[i]);
    }
}

void bubbleSort(int *bil, int n) {
    int i,j;
    for(i = 1; i < n; i++) {
        for(j = n-1; j >= 1; j--) {
            if(bil[j] < bil[j-1])
                swap(&bil[j], &bil[j-1]);
        }
    }
}

void selectionSort(int *bil, int n) {
    int i, j, temp;
    for(i = 0; i < n; i++) {
        temp = i;
        for(j = i+1; j < n; j++) {
            if(bil[j] < bil[temp])
                temp = j;
        }
        if(temp != i)
            swap(&bil[temp], &bil[i]);
    }
}

void insertionSort(int *bil, int n) {
    int i, j, temp;
    for(i = 1; i < n; i++) {
        temp = bil[i];
        for(j = i-1; j >= 0 && bil[j] > temp; j--) {
            bil[j+1] = bil[j];
        }
        bil[j+1] = temp;
    }
}

int main() {
    int i, n, *bil;
    printf("Jumlah angka: ");
    scanf("%d", &n);
    bil = (int*) malloc(sizeof(int)*n);

    for (i = 0; i < n; i++) {
        printf("Input number %d: ", i+1);
        scanf("%d", &bil[i]);
    }

    bubbleSort(bil, n);
    // selectionSort(bil, n);
    // insertionSort(bil, n);
    printf("Array after sorting: ");
    printArray(bil, n);
    free(bil);

    return 0;
}

