#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct search {
    int num;
    char kelas[50], gedung[50];

    struct search *next;
};

struct test {
    char kelas[50], gedung[50];
};

int main() {
    struct search *head, *curr, *node;
    struct test duplikat[1000];
    head = NULL;
    int num, inp, i = 0, j = 0, hasDeleted, status;
    char kelas[50], gedung[50];

    while(1) {
        system("cls");
        printf("1. Input a new data. \n");
        printf("2. Check the linked list. \n");
        printf("3. Exit \n");
        printf("4. Clear the linked list. \n");
        scanf("%d", &inp);

        switch(inp) {
            case 1:
                system("cls");
                printf("Masukkan gedung dan kelas! \n");
                printf("Gedung: "); scanf("%s", gedung);
                printf("Kelas: "); scanf("%s", kelas);

                node = (struct search*)malloc(sizeof(struct search));
                node->next = NULL;
                i++;
                status = 0;

                // Check for duplicates - Algorithm 1
                strcpy(duplikat[i].gedung, gedung);
                strcpy(duplikat[i].kelas, kelas);
                i++;

                for(j = 0; j < i-1; j++) {
                    int res = strcmp(duplikat[j].gedung, gedung);
                    int res2 = strcmp(duplikat[j].kelas, kelas);
                    if(res == 0 && res2 == 0) {
                        printf("Duplikat sama \n");
                        status = 0;
                        system("pause");
                        break;
                    }
                    else {
                        status = 1;
                        continue;
                    }
                }

                if(status == 1) {
                    strcpy(node->kelas, kelas);
                    strcpy(node->gedung, gedung);
                }
                else {
                    printf("Not printed. Duplicate.");
                    node = node->next;
                    system("pause");
                }

                // END

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
                system("cls");
                if(head == NULL) {
                    printf("Head is null. Enter some data. \n");
                    system("pause");
                }
                else {
                    curr = head;
                    while(curr != NULL) {
                        printf("------------------------- \n");
                        printf("Gedung: %s \n", curr->gedung);
                        printf("Kelas: %s \n", curr->kelas);
                        printf("------------------------- \n");
                        curr = curr->next;
                    }
                    system("pause");
                }
                break;
            case 3:
                exit(0);
                break;

            case 4:
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
        }
    }
    return 0;
}
