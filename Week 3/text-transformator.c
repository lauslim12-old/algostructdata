#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Layar() {
    system("cls");
    printf("Text Transformator \n");
    printf("1. Uppercase \n");
    printf("2. Lowercase \n");
    printf("3. Switching \n");
    printf("4. Exit \n");
}

void upper(char s[]) {
   int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
            s[c] = s[c] - 32;
        }
        c++;
    }
}

void lower(char s[]) {
    int c = 0;

    while (s[c] != '\0') {
        if (s[c] >= 'A' && s[c] <= 'Z') {
            s[c] = s[c] + 32;
        }
        c++;
    }
}

void charswitch(char s[]) {
    int c = 0;

    for(c = 0; s[c] != '\0' ; c++) {
        if(s[c] >= 'A' && s[c] <= 'Z') {
            s[c] = s[c] + 32;
        }
        else {
            s[c] = s[c] - 32;
        }
    }
}

int main() {
    int pil;
    char string[500];

    while(1) {
        Layar();
        printf("Silakan masukkan nomor: ");
        scanf("%d", &pil);
        getchar();

        switch(pil) {
            case 1:
                printf("Masukkan kata: ");
                gets(string);
                upper(string);
                printf("Uppercase: %s \n", string);
                system("pause");
                break;

            case 2:
                printf("Masukkan kata: ");
                gets(string);
                lower(string);
                printf("Lowercase: %s \n", string);
                system("pause");
                break;

            case 3:
                printf("Masukkan kata: ");
                gets(string);
                charswitch(string);
                printf("Switching: %s \n", string);
                system("pause");
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("Invalid input.");
        }
    }
    return 0;
}
