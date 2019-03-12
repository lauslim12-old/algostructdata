#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <conio.h>

struct penyimpanan {
    char nama[50], nim[50], prodi[50], gedung[50], ruangan[50], status[50];
    int angkatan;

    struct penyimpanan *next, *prev;
};

struct temporaryDuplicateChecker {
    char gedung[50], ruangan[50];
};

void Menu() {
    system("cls");
    printf("======================================================================================================== \n");
    printf("                                    Rent-A-Room by Nicholas Dwiarto                                      \n");
    printf("======================================================================================================== \n");
    printf("1. Pinjam Ruangan \n");
    printf("2. Borrowed Rooms List \n");
    printf("3. Clear All Borrowed Rooms \n");
    printf("4. Approve Rooms \n");
    printf("5. Batalkan Approval Ruangan \n");
    printf("6. Sorting NIM - Radix Sort \n");
    printf("7. Exit \n");
}

void Approval(){
    printf("Menu: \n");
    printf("1. Next \n");
    printf("2. Prev \n");
    printf("3. Approve \n");
    printf("4. Exit \n");
    printf("Input: ");
}

void Unapproval(){
    printf("Menu: \n");
    printf("1. Next \n");
    printf("2. Prev \n");
    printf("3. Cancel \n");
    printf("4. Exit \n");
    printf("Input: ");
}


int main() {
    // Variables for the linked lists
    struct penyimpanan *head, *curr, *node, *tail, *temp;
    struct temporaryDuplicateChecker duplikat[1000];
    char nama[50], nim[50], prodi[50], gedung[50], ruangan[50];
    int angkatan;
    int choice4;

    // Variables for main functions
    int input, input1, dataNumber, hasDeleted, currentData, compareData;
    int i = 0, j, status; // for the duplicate checking
    int hasDuplicate = 0;

    // Linked list declaration
    head = curr = NULL;
    tail->next = NULL;

    while(1) {
        Mainmenu:
        Menu();
        printf("Input: ");
        scanf("%d", &input);
        switch(input) {
            case 1:
                // Input
                system("cls");
                fflush(stdin);
                printf("======================================================================================================== \n");
                printf("                                    Input Data Peminjaman Ruangan                                        \n");
                printf("======================================================================================================== \n");
                printf("Nama            : "); scanf("%[^\n]", nama);
                printf("NIM             : "); scanf("%s", &nim);
                printf("Program Studi   : "); fflush(stdin); scanf("%[^\n]", prodi);
                printf("Angkatan        : "); scanf("%d", &angkatan);
                printf("Gedung (A-D)    : "); scanf("%s", &gedung);
                printf("Nomor Ruangan   : "); scanf("%s", &ruangan);

                node = (struct penyimpanan*)malloc(sizeof(struct penyimpanan));
                node->next = NULL;
                node->prev = NULL;

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
                    printf("Ruangan berhasil dipinjam dengan status unapproved! \n");
                    system("pause");
                }
                else {
                    printf("Ruangan sudah dipinjam! Mohon input ulang! \n");
                    node = node->next;
                    system("pause");
                    goto Mainmenu;
                }
                // End of algorithm

                // Loop to make linked lists.
                if(head == NULL) {
                    head = node;
                    tail = node;
                }
                else {
                    temp = head;
                    tail->next = node;
                    node->prev = tail;
                    tail = node;

                    while(temp->next != NULL) {
                        curr = head;
                        while(curr->next != NULL) {
                            curr = curr->next;
                        }
                        tail = node;
                        tail->next = NULL;
                        temp = temp->next;
                    }
                }
                // End
                break;

            case 2:
                if(head == NULL) {
                    printf("Tidak ada yang sedang meminjam ruangan. Masukkan data. \n");
                    system("pause");
                }
                else {
                    system("cls");
                    printf("======================================================================================================== \n");
                    printf("                                    Daftar Nama Peminjam Ruangan                                         \n");
                    printf("======================================================================================================== \n");

                    curr = head;
                    dataNumber = 0;

                    while(curr != NULL) {
                        dataNumber++;
                        printf("Peminjam ke: %d \n", dataNumber);
                        printf("Nama: %s \n", curr->nama);
                        printf("NIM: %s \n", curr->nim);
                        printf("Prodi: %s \n", curr->prodi);
                        printf("Angkatan: %d \n", curr->angkatan);
                        printf("Ruangan: %s%s \n", curr->gedung, curr->ruangan);
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
                system("cls");

                if(head != NULL) {
                    curr = head;
                    dataNumber = 0;

                    while(curr != NULL) {
                        dataNumber++;
                        curr = curr->next;
                    }
                    curr = head;
                    currentData = 1;

                    while(1){
                        system("cls");
                        printf("======================================================================================================== \n");
                        printf("                                      Penyetujuan Ruangan                                                \n");
                        printf("======================================================================================================== \n");
                        printf("Nomor       : %d / %d\n", currentData, dataNumber);
                        printf("Nama        : %s\n", curr->nama);
                        printf("NIM         : %s\n", curr->nim);
                        printf("Prodi       : %s\n", curr->prodi);
                        printf("Angkatan    : %d\n", curr->angkatan);
                        printf("Ruangan     : %s%s\n", curr->gedung, curr->ruangan);
                        printf("Status      : %s\n", curr->status);

                        Approval();
                        scanf("%d", &input1);

                        switch(input1){
                        case 1:
                            if(curr->next != NULL){
                                curr = curr->next;
                                currentData++;
                            }
                            else {
                                 printf("Next data itu kosong! \n");
                                 system("pause");
                            }
                            break;

                        case 2:
                            if(curr->prev != NULL){
                                curr = curr->prev;
                                currentData--;
                            }
                            else {
                                 printf("Data sebelumnya kosong! \n");
                                 system("pause");
                            }
                            break;

                        case 3:
                            strcpy(curr->status, "Approved!");
                            break;

                        case 4:
                            system("cls");
                            goto Mainmenu;
                            break;
                        }
                    }
                }
                else {
                    system("cls");
                    printf("Data telah dihapus atau belum diisi! \n");
                    system("pause");
                }
                break;

            case 5:
                system("cls");
                if(head != NULL) {
                    curr = head;
                    dataNumber = 0;

                    while(curr != NULL) {
                        dataNumber++;
                        curr = curr->next;
                    }
                    curr = head;
                    currentData = 1;

                    while(1){
                        system("cls");
                        printf("======================================================================================================== \n");
                        printf("                                    Pembatalan Ruangan                                                   \n");
                        printf("======================================================================================================== \n");
                        printf("Nomor       : %d / %d\n", currentData, dataNumber);
                        printf("Nama        : %s\n", curr->nama);
                        printf("NIM         : %s\n", curr->nim);
                        printf("Prodi       : %s\n", curr->prodi);
                        printf("Angkatan    : %d\n", curr->angkatan);
                        printf("Ruangan     : %s%s\n", curr->gedung, curr->ruangan);
                        printf("Status      : %s\n", curr->status);

                        Unapproval();
                        scanf("%d", &input1);
                        compareData = 0;

                        switch(input1){
                        case 1:
                            if(curr->next != NULL){
                                curr = curr->next;
                                currentData++;
                                compareData++;
                            }
                            else {
                                 printf("Next data itu kosong! \n");
                                 system("pause");
                            }
                            break;

                        case 2:
                            if(curr->prev != NULL){
                                curr = curr->prev;
                                currentData--;
                                compareData--;
                            }
                            else {
                                 printf("Data sebelumnya kosong! \n");
                                 system("pause");
                            }
                            break;

                        case 3:
                            temp = curr;
                            if(head == temp) {
                                head = temp->next;
                            }
                            if(temp->next != NULL) {
                                temp->next->prev = temp->prev;
                            }
                            if(temp->prev != NULL) {
                                temp->prev->next = temp->next;
                            }

                            free(curr);
                            strcpy(duplikat[i].gedung, "Null");
                            strcpy(duplikat[i].ruangan, "Null");
                            printf("Cancel berhasil. Program akan kembali ke main menu... \n");
                            system("pause");
                            goto Mainmenu;
                            break;

                        case 4:
                            system("cls");
                            goto Mainmenu;
                            break;
                        }
                    }
                }
                else {
                    system("cls");
                    printf("Data telah dihapus atau belum diisi! \n");
                    system("pause");
                }
                break;

            case 6:
                system("cls");
                printf("=========================================================================\n");
                printf("NIM - Radix Sorting\n");
                printf("=========================================================================\n");
                printf("1. Ascending\n");
                printf("2. Descending\n");
                printf("Pilih: "); scanf("%d", &choice4);

                struct penyimpanan *bucket[10], *bucketTail[10];
                int i, j, x, iBucket;
                int index = 10;

                for(x = 0; x < 5; x++) {
                    for(i = 0; i < 10; i++){
                        bucket[i] = bucketTail[i] = NULL;
                    }
                }

                curr = head;
                head->prev = NULL;
                tail->next = NULL;

                switch(choice4) {
                    case 1:
                        while(curr != NULL) {
                            struct penyimpanan *temp = (struct penyimpanan*)malloc(sizeof(struct penyimpanan));
                            temp->next = NULL;

                            strcpy(temp->nama, curr->nama);
                            strcpy(temp->nim, curr->nim);
                            strcpy(temp->prodi, curr->prodi);
                            strcpy(temp->status, curr->status);
                            temp->angkatan = curr->angkatan;
                            strcpy(temp->gedung, curr->gedung);
                            strcpy(temp->ruangan, curr->ruangan);
                            iBucket = temp->nim[index] - 48;

                            if(bucket[iBucket] == NULL){
                                bucket[iBucket] = bucketTail[iBucket] = temp;
                            }
                            else {
                                bucketTail[iBucket]->next = temp;
                                bucketTail[iBucket] = temp;
                            }
                            curr = curr->next;
                        }

                        curr = head;
                        while(curr != NULL){
                            head = head->next;
                            curr->next = NULL;
                            free(curr);
                            curr = head;
                        }

                        head = tail = NULL;

                        i = 1;
                        for(j=0; j < 10; j++){
                            if(bucket[j] != NULL){
                                curr = bucket[j];
                                while(curr != NULL){
                                    node = (struct penyimpanan*)malloc(sizeof(struct penyimpanan));
                                    node->next = NULL;
                                    node->prev = NULL;
                                    strcpy(temp->nama, curr->nama);
                                    strcpy(temp->nim, curr->nim);
                                    strcpy(temp->prodi, curr->prodi);
                                    strcpy(temp->status, curr->status);
                                    temp->angkatan = curr->angkatan;
                                    strcpy(temp->gedung, curr->gedung);
                                    strcpy(temp->ruangan, curr->ruangan);
                                    if(head == NULL){
                                        head = tail = node;
                                        i++;
                                    }
                                    else{
                                        tail->next=node;
                                        node->prev = tail;
                                        tail = node;
                                        i++;
                                    }
                                    curr = curr->next;
                                }

                            }

                        }
                         for(i = 0; i<10; i++){
                            bucket[i] = bucket[j] = NULL;
                         }

                         index--;
                    }
                    tail->next = head;
                    head->prev = tail;
                    printf("Data berhasil di sorting!");
                    getch();
                break;

            case 7:
                exit(0);
                break;

            default:
                printf("Invalid input. Mohon input ulang. \n");
                system("pause");
        }
    }
    return 0;
}
