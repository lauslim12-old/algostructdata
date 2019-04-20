#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct pinjam {
    char nama[30];
    char nim[16];
    char program[30];
    int angkatan;
    char gedung;
    int nomor;
    int urutan;
    char status[15];

    struct pinjam *next,*prev;
} pinjam;

int menu (){
    int pilihan;
    system("cls");
    printf("=============================================\n");
    printf("\n");
    printf("Menu Pemilihan Ruangan\n");
    printf("\n");
    printf("=============================================\n");
    printf("1. Pinjam Ruangan\n");
    printf("2. List Ruangan Yang Dipinjam\n");
    printf("3. Hapus Ruangan Yang Dipinjam (Clear All)\n");
    printf("4. Menyutujui Ruangan\n");
    printf("5. Batalkan Peminjaman Ruangan\n");
    printf("6. Exit\n");
    printf("Pilihan :");scanf("%d",&pilihan);
    return pilihan;
}
int main (int argc, char const *argv[]){
    struct pinjam *head, *node, *tail, *curr,*urttemp, *temp;

    char nama[30],program[30],nim[16],gedung;
     int angkatan,nomor,pilihan, x = 1, i = 0,y,z,inp;

    head = NULL;
    tail = NULL;
    //looping awal
    while( x == 1){
        pilihan = menu();
        //memasukan data
        if (pilihan == 1){
            system("cls");
            fflush(stdin);
            printf("=============================================\n");
            printf("\n");
            printf("Input Data Peminjam\n");
            printf("\n");
            printf("=============================================\n");
            printf("Input Nama    : ");scanf("%[^\n]",&nama);fflush(stdin);
            printf("Input Nim     : ");scanf("%[^\n]",&nim);fflush(stdin);
            printf("Program Studi : ");scanf("%[^\n]",&program);fflush(stdin);
            printf("Angkatan      : ");scanf("%d",&angkatan);fflush(stdin);
            printf("Gedung (A-D)  : ");scanf("%c",&gedung);fflush(stdin);
            printf("No Ruangan    : ");scanf("%d",&nomor);fflush(stdin);


            node = (struct pinjam*)malloc(sizeof(struct pinjam));
            node->next = NULL;
            node->prev = NULL;
            y = 1;


            if (head == NULL){
                strcpy(node->nama, nama);
                strcpy(node->nim, nim);
                strcpy(node->program, program);
                strcpy(node->status, "Unapproved");
                node->angkatan = angkatan;
                node->gedung = gedung;
                node->nomor = nomor;
                node->urutan = i;
                head = node;
                tail = node;
                i++;
            }
            else {
                curr = head;
                //mengecek data double
                 if (gedung == curr->gedung && nomor == curr->nomor){
                printf("Ruangan telah dipinjam!\n");
                y = 0;

                }
                while (curr->next != head){
                curr = curr->next;
                if (gedung == curr->gedung && nomor == curr->nomor){
                printf("Ruangan telah dipinjam!\n");
                y = 0;
                }}
                }

                //jika data kosong memasukan data ke node
                if (y == 1){
                strcpy(node->nama, nama);
                strcpy(node->nim, nim);
                strcpy(node->program, program);
                strcpy(node->status, "Unapproved");
                node->angkatan = angkatan;
                node->gedung = gedung;
                node->nomor = nomor;
                tail->next = node;
                node->prev = tail;
                tail = node;
                tail->next = head;
                head->prev = tail;
                node->urutan = i;
                i++;
                }



            printf("Pencet Tombol untuk melanjutkan..");
            getch();
        }
        //menampilkan data
        if (pilihan == 2){
            if(head != NULL){
           z = 0;
           curr = head;
           while (z == 0) {
            system("cls");
            printf("=============================================\n");
            printf("\n");
            printf(" Data Peminjam\n");
            printf("\n");
            printf("=============================================\n");
            printf("Data (%d/%d) \n",curr->urutan,tail->urutan);
            printf("Nama          : %s\n",curr->nama);
            printf("Nim           : %s\n",curr->nim);
            printf("Program Studi : %s\n",curr->program);
            printf("Angkatan      : %d\n",curr->angkatan);
            printf("Ruangan       : %c%d\n",curr->gedung,curr->nomor);
            printf("Status        : %s\n",curr->status);
            printf("1. Maju\n");
            printf("2. Mundur\n");
            printf("3. Keluar\n");
            printf("Pilihan : ");scanf("%d",&inp);
            //handling pilihan
            if (inp == 1){
            curr = curr->next;
            }
            else if (inp == 2){
                curr = curr->prev;
           }
           else {
            z = 1;
           }
        }
        }
        else {printf("Tidak ada data");
        getch();}
        }

        //menclearkan data
        if (pilihan == 3){
            system("cls");
            if(head != NULL){
            while(head != tail){
                node = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            node->next = node->prev = NULL;
            free(node);}
            free(node);
            head = tail = NULL;
            printf("System Clear");
            getch();
            i = 0;
            }
            else {
                printf("Tidak Ada Data");
                getch();
            }
        }
        //penyetujuan ruangan
        if (pilihan == 4){
           if(head != NULL){
           z = 0;
           curr = head;
           while (z == 0) {
            system("cls");
            printf("=============================================\n");
            printf("\n");
            printf(" Penyetujuaan Ruangan\n");
            printf("\n");
            printf("=============================================\n");
            printf("Data (%d/%d) \n",curr->urutan,tail->urutan);
            printf("Nama          : %s\n",curr->nama);
            printf("Nim           : %s\n",curr->nim);
            printf("Program Studi : %s\n",curr->program);
            printf("Angkatan      : %d\n",curr->angkatan);
            printf("Ruangan       : %c%d\n",curr->gedung,curr->nomor);
            printf("Status        : %s\n",curr->status);
            printf("1. Maju\n");
            printf("2. Mundur\n");
            printf("3. Approve\n");
            printf("4. Keluar\n");
            printf("Pilihan : ");scanf("%d",&inp);
            if (inp == 1){
            curr = curr->next;
            }
            else if (inp == 2){
                curr = curr->prev;
           }
           else if (inp == 3){
                if (strcmp(curr->status, "Approved") == 0){
           printf("Sudah Di Approved");
           getch();}
            else strcpy(curr->status,"Approved");
           }
            else {
            z = 1;
           }
        }
        }
         else {printf("Tidak Ada data");
        getch();}
        }

        //batalan pemijaman ruangan
        if (pilihan == 5){
            if(head != NULL){
           z = 0;
           curr = head;
           while (z == 0) {
            system("cls");
            printf("=============================================\n");
            printf("\n");
            printf(" Pembatalan Peminjaman\n");
            printf("\n");
            printf("=============================================\n");
            printf("Data (%d/%d) \n",curr->urutan,tail->urutan);
            printf("Nama          : %s\n",curr->nama);
            printf("Nim           : %s\n",curr->nim);
            printf("Program Studi : %s\n",curr->program);
            printf("Angkatan      : %d\n",curr->angkatan);
            printf("Ruangan       : %c%d\n",curr->gedung,curr->nomor);
            printf("Status        : %s\n",curr->status);
            printf("1. Maju\n");
            printf("2. Mundur\n");
            printf("3. Cancel\n");
            printf("4. Keluar\n");
            printf("Pilihan : ");scanf("%d",&inp);
            if (inp == 1){
            curr = curr->next;
            }
            else if (inp == 2){
                curr = curr->prev;
           }
           else if (inp == 3){
                if (curr == head){
                    curr->next->urutan = curr->next->urutan - curr->urutan;
                    curr = curr->next;
                    while (curr != head){
                        curr = curr->next;
                        curr->urutan = curr->urutan - (curr->prev->urutan);

                    }
                    curr = head;
                    head = head->next;
                    tail->next = head;
                    head->prev = tail;
                    curr->next = curr->prev = NULL;
                    i--;
                    if(i!=1){free(curr);
                    curr = head;
                    }
                    else{
                    free(curr);
                    head = tail = NULL;
                    i = 0;
                    break;
                    }
                }
                else if (curr == tail){
                    curr->urutan = curr->urutan - head->urutan;
                    curr = tail;
                    tail = tail->prev;
                    tail->next = head;
                    head->prev = tail;
                    curr->next = curr->prev = NULL;
                    i--;
                    if(i!=1){free(curr);
                    curr = head;
                    }
                    else{
                    free(curr);
                    head = tail = NULL;
                    i = 0;
                    break;
                    }
                }

                else if (curr!=NULL) {
                        urttemp = curr;

                        while (urttemp != head){
                            urttemp = urttemp->next;
                            urttemp->urutan = urttemp->urutan - head->urutan;
                        }
                        head->urutan = 1;
                        curr->prev->next = curr->next;
                        curr->next->prev = curr->prev;
                        curr->next = curr->prev = NULL;
                        i--;
                        if(i!=1){
                        free(curr);
                        curr = tail;
                        }
                        else{
                    head = tail = NULL;
                    i = 0;
                    break;
                    }
                    }
                }
            else {
            z = 1;
           }
            }
            }
            else {printf("Tidak Ada Data");
            getch();}
        }

if (pilihan == 6){
    if(head != NULL){
        struct pinjam *bucket[10], *bucketTail[10];
        int i,j,x,iBucket;
        int index = 10;
    for(x = 0; x < 5; x++){
        for(i = 0; i < 10; i++){
            bucket[i] = bucketTail[i] = NULL;
        }

        curr = head;
        head->prev = NULL;
        tail->next = NULL;
        while(curr != NULL){

            struct pinjam *temp = (struct pinjam *)malloc(sizeof(struct pinjam));
            temp->next = NULL;

            strcpy(temp->nama, curr->nama);
            strcpy(temp->nim, curr->nim);
            strcpy(temp->program, curr->program);
            strcpy(temp->status, curr->status);
            temp->angkatan = curr->angkatan;
            temp->gedung = curr->gedung;
            temp->nomor = curr->nomor;
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
                    node = (struct pinjam *)malloc(sizeof(struct pinjam));
                    node->next = NULL;
                    node->prev = NULL;
                    strcpy(node->nama, curr->nama);
                    strcpy(node->nim, curr->nim);
                    strcpy(node->program, curr->program);
                    strcpy(node->status, curr->status);
                    node->angkatan = curr->angkatan;
                    node->gedung = curr->gedung;
                    node->nomor = curr->nomor;
                    node->urutan = i;
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
    printf("Data berhasil di Sort!");
    getch();
    }
    else {
        printf("Tidak ada Data!");getch();
    }
    }

        //keluar
        if(pilihan == 7 ){
            return 0;
        }
    }
}
