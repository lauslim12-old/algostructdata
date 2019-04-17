#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

/*  Information (gabut):
    ----------------------------------------------------------------------------------------------------------------------------------
    Data Structures Used: Hash Tables, Linked Lists
    Algorithms Used: Inserting to Hash Tables, Searching.
    Coded with <3 by Nicholas Dwiarto.
    Website: nicholasdw.com (Homepage)
    LinkedIn: https://www.linkedin.com/in/nicholasdwiarto/
    Instagram: @nicholasnwr.
    Ask me for GitHub and other accounts.
    ----------------------------------------------------------------------------------------------------------------------------------
*/

// Structures to hold the data.
struct data {
	long long nim;
	char nama[50];

	struct data *next;
};

// Algorithms (Hash Checking)
// Position is used to judge the position of the characters that is passed into the array.
void position(char *nama, int *a, int *b, int *c) {
    int i;
    char temp[2][27] = {"abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    for(i=0; i<26; i++)
    {
        if(nama[0] == temp[0][i] || nama[0] == temp[1][i])
        {
            *a = i;
            break;
        }
    }
    for(i=0; i<26; i++)
    {
        if(nama[1] == temp[0][i] || nama[1]==temp[1][i])
        {
            *b = i;
            break;
        }
    }
    for(i=0; i<26; i++)
    {
        if(nama[2] == temp[0][i] || nama[2]==temp[1][i])
        {
            *c = i;
            break;
        }
    }
}

// To insert to the Linked List.
void InsertLinkedList(char nama[], long long nim, struct data **head) {
    struct data *pointer = (*head);
    struct data *node = (struct data*) malloc(sizeof(struct data));
    node->nim = nim;
    strcpy(node->nama, nama);
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
    }
    else {
        while(pointer->next != NULL) {
            pointer = pointer->next;
        }
        pointer->next = node;
    }
}

// To print the Linked Lists.
void printHash(struct data *head, char *nama)
{
    if(head == NULL)
    {
        printf("Nama yang berinisial %s tidak dapat ditemukan! \n", nama);
    }
    else
    {
        int i = 1;
        while(head != NULL)
        {
            printf("Mahasiswa #%d \n", i);
            i++;
            printf("Nama    : %s \n", head->nama);
            printf("NIM     : %011lld \n", head->nim);
            printf("--------------------------------------------- \n");
            head = head->next;
        }
    }
}

// To search for the a certain data inside the Linked List.
bool SearchHash(struct data **head, char nama[])
{
    bool check = false;
    struct data *pointer = *head;
    if(*head == NULL)
    {
        check = false;
    }
    else
    {
        while(pointer != NULL)
        {
            if(strcmpi(nama, pointer->nama) == 0)
            {
                check = true;
                break;
            }
            else
            {
                pointer = pointer->next;
                check = false;
            }
        }
    }
    if(check == true)
    {
        if(pointer == *head)
        {
            *head = (*head)->next;
            free(pointer);
        }
        else
        {
            struct data *front = *head;
            while(front->next != pointer)
            {
                front = front->next;
            }
            struct data *back;
            back = pointer->next;
            front->next = back;
            pointer->next = NULL;
            free(pointer);
        }
    }
    return check;
}

// Menus
void MainMenu(){
    printf("======================================================================================================== \n");
    printf("                                 Hasher Mahasiswa by Nicholas Dwiarto                                    \n");
    printf("======================================================================================================== \n");
	printf("(1). Cari Mahasiswa (berdasar 3 huruf pertama) \n");
	printf("(2). Delete Mahasiswa \n");
	printf("(3). Tambah Mahasiswa \n");
	printf("(4). Exit\n");
	printf("Input: ");
}
void MenuSearching(){
    printf("======================================================================================================== \n");
    printf("                                        Pencarian Mahasiswa                                              \n");
    printf("======================================================================================================== \n");
	printf("Masukkan 3 huruf inisial nama yang ingin dicari: \n");
}

void MenuDelete(){
    printf("======================================================================================================== \n");
    printf("                                        Penghapusan Mahasiswa                                            \n");
    printf("======================================================================================================== \n");
	printf("Masukkan nama mahasiswa: ");
}

void MenuTambah(){
    printf("======================================================================================================== \n");
    printf("                                        Penambahan Mahasiswa                                             \n");
    printf("======================================================================================================== \n");
	printf("Masukkan nama mahasiswa baru: ");
}


int main(){
    int pilih;
    char cariNama[10], nama[50], namaBaru[50];
    long long nim;
    int i, j, k, a, b, c;

    struct data *HashTable[26][26][26];
    struct data *pointer = NULL;

    FILE *fp;

    while(1) {
        system("cls");
        MainMenu();
        scanf("%d", &pilih); fflush(stdin);

        // Creating the hash tables and File Processing
        for(i = 0; i < 26; i++) {
            for(j = 0; j < 26; j++) {
                for(k = 0; k < 26; k++) {
                    HashTable[i][j][k] = NULL;
                }
            }
        }

        fp = fopen("datamhs.txt", "a+");
        while(!feof(fp)) {
            fscanf(fp, "%lld-%[^\n]\n", &nim, &nama); fflush(stdin);
            position(nama, &a, &b, &c);
            InsertLinkedList(nama, nim, &HashTable[a][b][c]);
        }
        fclose(fp);

        switch(pilih) {
            case 1:
                // Searching based on initials.
                system("cls");
                MenuSearching();
                scanf("%s", &cariNama);fflush(stdin);

                position(cariNama, &a, &b, &c);
                printHash(HashTable[a][b][c], cariNama);
                system("pause");
                break;

            case 2:
                // Delete data.
                system("cls");
                MenuDelete();
                scanf("%[^\n]", &nama);fflush(stdin);
                position(nama, &a, &b, &c);
                bool check = SearchHash(&HashTable[a][b][c], nama);
                if(check == true) {
                    fp = fopen("datamhs.txt", "w");
                    fclose(fp);
                    fp = fopen("datamhs.txt", "a+");

                    for(i = 0; i < 26; i++) {
                        for(j = 0; j < 26; j++) {
                            for(k = 0; k < 26; k++) {
                                if(HashTable[i][j][k] != NULL) {
                                    pointer = HashTable[i][j][k];

                                    while(pointer != NULL) {
                                        fprintf(fp, "%011lld-%s\n", pointer->nim, pointer->nama);
                                        pointer = pointer->next;
                                    }
                                }
                            }
                        }
                    }
                    fclose(fp);

                    printf("Mahasiswa dengan nama %s berhasil dihapus! \n", nama);
                }
                else {
                    printf("Tidak ada anak bernama %s yang ditemukan dalam database! \n", nama);
                }

                system("pause");
                break;

            case 3:
                // Add a new data.
                system("cls");
                MenuTambah();
                scanf("%[^\n]", &namaBaru); fflush(stdin);

                printf("Masukkan NIM mahasiswa baru: ");
                scanf("%lld", &nim); fflush(stdin);

                position(namaBaru, &a, &b, &c);
                InsertLinkedList(namaBaru, nim, &HashTable[a][b][c]);

                fp = fopen("datamhs.txt", "w");
                fclose(fp);

                fp = fopen("datamhs.txt", "a+");
                for(i = 0; i < 26; i++){
                    for(j = 0; j < 26; j++) {
                        for(k = 0; k < 26; k++) {
                            if(HashTable[i][j][k] != NULL) {
                                pointer = HashTable[i][j][k];

                                while(pointer != NULL) {
                                    fprintf(fp, "%011lld-%s\n", pointer->nim, pointer->nama);
                                    pointer = pointer->next;
                                }
                            }
                        }
                    }
                }
                fclose(fp);
                printf("Mahasiswa baru telah dimasukkan! \n");
                system("pause");
                break;

            case 4:
                // Exiting the program and deleting the hash tables.
                for(i = 0; i < 26; i++) {
                    for(j = 0; j < 26; j++) {
                        for(k = 0; k < 26; k++) {
                            if(HashTable[i][j][k] != NULL) {
                                free(HashTable[i][j][k]);
                            }
                        }
                    }
                }
                exit(0);
            break;

            default:
                printf("Mohon input angka dengan benar! \n");
                system("pause");

        }
    }

    return 0;
}



