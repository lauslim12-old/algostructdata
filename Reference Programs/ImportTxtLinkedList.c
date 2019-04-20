#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

struct data {
    char nama[50];
    int id, jumlah, harga;

    struct data *next, *prev;
};

int main() {
    struct data *head, *tail, *node, *tmp;
    struct data dataku;

    int i, jumlahData, counter;
    FILE *data;

    head = tail = NULL;

    i = 0;
    jumlahData = 0;
    data = fopen("StockSkiffy.txt", "r");
    while(!feof(data)) {
        fscanf(data, "%d#%[^#]#%d#%d \n", &dataku.id, dataku.nama, &dataku.jumlah, &dataku.harga);
        jumlahData++;
        node = (struct data*)malloc(sizeof(struct data));
        node->next = NULL;
        node->prev = NULL;

        node->id = dataku.id;
        strcpy(node->nama, dataku.nama);
        node->jumlah = dataku.jumlah;
        node->harga = dataku.harga;

        // Insertion.
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
    }
    fclose(data);

    printf("Telah dimasukkan ke dalam Linked List! \n");
    system("pause");
    system("cls");

    printf("======================================================================================================================= \n");
    printf("                                             Daftar Produk                                                              \n");
    printf("======================================================================================================================= \n");
    printf("\n");

    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    printf("| %-2s | %-45s | %-30s | %-30s |\n", "ID", "Nama", "Quantity", "Harga (per 1 pieces)");
    printf("----------------------------------------------------------------------------------------------------------------------- \n");

    // Display
    tmp = head;
    while(tmp != NULL) {
        printf("| %-2d | %-45s | %-30d | %-30d \n", tmp->id, tmp->nama, tmp->jumlah, tmp->harga);
        tmp = tmp->next;
    }
    printf("----------------------------------------------------------------------------------------------------------------------- \n");
    system("pause");

    // Check the number of linked list.
    tmp = head;
    counter = 0;

    while(tmp != NULL) {
        counter++;
        tmp = tmp->next;
    }

    printf("Jumlah node: %d \n\n", counter);

    // Check a single node.
    counter = 5;
    i = 0;

    tmp = head;
    while(i < counter-1) {
        i++;
        tmp = tmp->next;
    }

    printf("Data yang ada: \n");
    printf("ID: %d \n", tmp->id);
    printf("Nama: %s \n", tmp->nama);
    printf("Jumlah: %d \n", tmp->jumlah);
    printf("Harga: %d \n\n", tmp->harga);

    printf("Print head: \n");
    printf("ID: %d \n", head->id);
    printf("Nama: %s \n", head->nama);
    printf("Jumlah: %d \n", head->jumlah);
    printf("Harga: %d \n", head->harga);

    system("pause");

    return 0;
}
