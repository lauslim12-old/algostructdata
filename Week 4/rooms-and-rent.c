#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

struct penyimpanan {
    char nama[50], nim[50], prodi[50], gedung[50], ruangan[50], status[50];
    int angkatan;

    struct penyimpanan *next;
};

struct temporaryDuplicateChecker {
    char gedung[50], ruangan[50];
};

void Menu() {
    system("cls");
    printf("======================= \n");
    printf("Menu Peminjaman Ruangan \n");
    printf("======================= \n");
    printf("1. Pinjam Ruangan \n");
    printf("2. Borrowed Rooms List \n");
    printf("3. Clear All Borrowed Rooms \n");
    printf("4. Exit \n");
}

int main() {
    // Variables for the linked lists
    struct penyimpanan *head, *curr, *node;
    struct temporaryDuplicateChecker duplikat[1000];
    char nama[50], nim[50], prodi[50], gedung[50], ruangan[50];
    int angkatan;

    // Variables for main functions
    int input, dataNumber, hasDeleted;
    int i = 0, j, status; // for the duplicate checking
    int hasDuplicate = 0;

    // Linked list declaration
    head = curr = NULL;

    while(1) {
        Menu();
        printf("Input: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                // Input
                system("cls");
                fflush(stdin);
                printf("============================= \n");
                printf("Input Data Peminjaman Ruangan \n");
                printf("============================= \n");
                printf("Nama            : "); scanf("%[^\n]", nama);
                printf("NIM             : "); scanf("%s", &nim);
                printf("Program Studi   : "); fflush(stdin); scanf("%[^\n]", prodi);
                printf("Angkatan        : "); scanf("%d", &angkatan);
                printf("Gedung (A-D)    : "); scanf("%s", &gedung);
                printf("Nomor Ruangan   : "); scanf("%s", &ruangan);

                node = (struct penyimpanan*)malloc(sizeof(struct penyimpanan));
                node->next = NULL;

                // Check for duplicates - Nicholas Dwiarto Way
                i++;
                status = 0;
                i++;
                strcpy(duplikat[i].gedung, gedung);
                strcpy(duplikat[i].ruangan, ruangan);

                for(j = 0; j < i-1; j++) {
                    int res = strcmp(duplikat[j].gedung, gedung);
                    int res2 = strcmp(duplikat[j].ruangan, ruangan);
                    if(res == 0 && res2 == 0) {
                        printf("Duplikat terdeteksi. \n");
                        status = 0;
                        break;
                    }
                    else {
                        status = 1;
                        continue;
                    }
                }

                if(status == 1) {
                    // Store in linked list
                    strcpy(node->nama, nama);
                    strcpy(node->nim, nim);
                    strcpy(node->prodi, prodi);
                    node->angkatan = angkatan;
                    strcpy(node->status, "Unapproved");
                    strcpy(node->ruangan, ruangan);
                    strcpy(node->gedung, gedung);
                    strcat(node->gedung, node->ruangan);
                    printf("Ruangan berhasil dipinjam dengan status unapproved! \n");
                    system("pause");
                }
                else {
                    printf("Ruangan sudah dipinjam! Mohon input ulang! \n");
                    node = node->next;
                    system("pause");
                }
                // End of algorithm

                // Loops for checking the linked lists. IF to chain nodes.
                if(head == NULL) {
                    head = node;
                }
                else {
                    curr = head;
                    while(curr->next != NULL) {
                        curr = curr->next;
                    }
                    curr->next = node;
                }
                break;

            case 2:
                if(head == NULL) {
                    printf("Tidak ada yang sedang meminjam ruangan. Masukkan data. \n");
                    system("pause");
                }
                else {
                    system("cls");
                    printf("============================ \n");
                    printf("Daftar Nama Peminjam Ruangan \n");
                    printf("============================ \n");

                    curr = head;
                    dataNumber = 0;

                    while(curr != NULL) {
                        dataNumber++;
                        printf("Peminjam ke: %d \n", dataNumber);
                        printf("Nama: %s \n", curr->nama);
                        printf("NIM: %s \n", curr->nim);
                        printf("Prodi: %s \n", curr->prodi);
                        printf("Angkatan: %d \n", curr->angkatan);
                        printf("Ruangan: %s \n", curr->gedung);
                        printf("Status: %s \n", curr->status);
                        printf("--------------------- \n");
                        curr = curr->next;
                    }
                    system("pause");
                }
                break;

            case 3:
                hasDeleted = 0;
                memset(duplikat, 0, sizeof(duplikat));
                while(head != NULL) {
                    hasDeleted++;
                    node = head;
                    head = head->next;
                    free(node);
                    printf("Data dalam Linked List ke %d telah dihapus. \n", hasDeleted);
                }
                system("pause");
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid input. Mohon input ulang. \n");
                system("pause");
        }
    }
    return 0;
}
