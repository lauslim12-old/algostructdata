#include <stdio.h>
#include <malloc.h>
#include <conio.h>

// Creating the queue.
typedef struct data {
    int n;
    struct data *next;
} DATA;

// Function prototypes.
void enqueue(DATA **head, DATA **tail, int angka);
void dequeue(DATA **head);
int isempty(DATA *head);
int front(DATA *head);
// End of the prototypes.

int main () {
    DATA *head, *tail, *node,  *tmp;
    int n, angka, i;

    // Linked List initialization.
    head = tail = NULL;

  	while(1) {
   		printf("Masukkan angka: ");
   		fflush(stdin);
   		scanf("%d", &angka);

    	if(isempty(head)) {
			printf("Angka akan di-enqueue sebanyak %d kali. \n", angka);
    		for(i = 0; i < angka; i++) {
    			enqueue(&head, &tail, angka);
			}

            // Printing the queue.
            tmp = head;
            while(tmp !=  NULL) {
                printf("%d \t", tmp->n);
                tmp = tmp->next;
            }
            printf("\n\n");
		}
		else {
			if(angka < front(head)) {
     			printf("Angka akan di de-queue sebanyak %d kali. \n", angka);
				for(i = 0; i < angka; i++) {
       				dequeue(&head);

       				if(isempty(head)) {
						printf("Queue habis! \n\n");
						getch();
						system("cls");
						break;
					 }
				}

   				if(isempty(head)) {
   					continue;
                }
                else {
                    // Printing the queue.
                    tmp = head;
                    while(tmp !=  NULL) {
                        printf("%d \t", tmp->n);
                        tmp = tmp->next;
                     }
                     printf("\n\n");
                }
			}

            if(angka >= front(head)) {
                printf("Angka akan di-enqueue lagi sebanyak %d kali. \n", front(head));
                for(i = 0; i < front(head); i++) {
                    enqueue(&head, &tail, angka);
                }

                tmp = head;
                while(tmp !=  NULL) {
                    printf("%d \t", tmp->n);
                    tmp = tmp->next;

                }
                printf("\n");
            }
        }
    }
    return 0;
}

void enqueue(DATA **head, DATA **tail, int angka){
    DATA *node = (DATA*) malloc(sizeof(DATA));
    node->n = angka;
    node->next = NULL;

    if(*head == NULL) *head = node;
    else (*tail)->next = node;

    *tail = node;
}

void dequeue(DATA **head){
    DATA *hapus = *head;
    *head = (*head)->next;
    free(hapus);
}

int isempty(DATA *head){
    if(head == NULL) return 1;
    else return 0;
}

int front(DATA *head){
    return head->n; //HEAD !ISEMPTY
}
