#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

void header(){
    printf("==============================================\n");
    printf("         Town Connector Initialization        \n");
    printf("==============================================\n");
}

void Menu() {
    printf("======================================================================================================== \n");
    printf("                                   Town Connector by Nicholas Dwiarto                                    \n");
    printf("                                          Application of UFDS                                            \n");
    printf("======================================================================================================== \n");
    printf("1. Masukkan Kota \n");
    printf("2. Hubungkan Kota \n");
    printf("3. Cek Hubungan \n");
    printf("4. Keluar \n");
    printf("Pilihan: ");
}

void initialize(int *parent, int *ranks, int n) {
	int i;

	for(i = 1; i <= n; i++)
	{
		parent[i] = i;
		ranks[i] = 0;
	}
}

int findSet(int *parent, int x) {
	if(parent[x] == x) return x;
	else {
		parent[x] = findSet(parent, parent[x]);
		return parent[x];
	}
}

int isSameSet(int *parent, int x, int y) {
	if(findSet(parent, x) == findSet(parent, y)) return 1;
	else return 0;
}

void unionFind(int *parent, int *ranks, int x, int y) {
	int i = findSet(parent, x);
	int j = findSet(parent, y);

	if(i != j)
	{
		if(ranks[i] > ranks[j]) parent[j] = 1;
		else
		{
			if(ranks[i] == ranks[j]) ranks[j]++;
			parent[i] = j;
		}
	}
}

int main() {
	int n; //jumlah kota
	int x, y;
	int pilihan;
	int counter = 1;
	char kota1[20], kota2[20];

    header();
	printf("Masukkan jumlah kota: ");
	scanf("%d", &n);

	int parent[n+1], ranks[n+1];
	char nama_kota[n+1][20];

	initialize(parent, ranks, n);

	while(1) {
        system("cls");
        Menu();
		scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                printf("Masukkan nama kota: "); fflush(stdin);
                scanf("%[^\n]", &kota1);
                printf("Kota %s berhasil dimasukkan!", kota1);
                getch();
                strcpy(nama_kota[counter], kota1);
                counter++;
                break;

            case 2:
                printf("Masukkan kota ke-1: ");	fflush(stdin); scanf("%[^\n]", &kota1);
                printf("Masukkan kota ke-2: ");	fflush(stdin); scanf("%[^\n]", &kota2);

                x = y = 0;
                int check_1 = 0;
                int check_2 = 0;

                for(int i = 1; i <= n; i++) {
                    if(strcmpi(nama_kota[i], kota1) == 0) {
                        x = i;
                        check_1 = 1;
                        break;
                    }
                }

                for(int i = 1; i <= n; i++) {
                    if(strcmpi(nama_kota[i], kota2) == 0) {
                        y = i;
                        check_2 = 1;
                        break;
                    }
                }

                if(check_1 == 1 && check_2 == 1) {
                    if(isSameSet(parent, x, y))	printf("Kedua kota sudah berada di dalam set yang sama\n");
                    else {
                        unionFind(parent, ranks, x, y);
                        printf("Kedua kota berhasil dihubungkan! \n");
                    }
                }
                else {
                    printf("Invalid input. Please try again.\n");
                }
                getch();
                break;

            case 3:
                printf("Masukkan kota ke-1: "); fflush(stdin); scanf("%[^\n]", &kota1);
                printf("Masukkan kota ke-2: "); fflush(stdin); scanf("%[^\n]", &kota2);

                x = y = 0;
                check_1 = 0, check_2 = 0;

                for(int i = 1; i <= n; i++)
                {
                    if(strcmpi(nama_kota[i], kota1) == 0)
                    {
                        x = i;
                        check_1 = 1;
                        break;
                    }
                }

                for(int i = 1; i <= n; i++)
                {
                    if(strcmpi(nama_kota[i], kota2) == 0)
                    {
                        y = i;
                        check_2 = 1;
                        break;
                    }
                }

                if(check_1 == 1 && check_2 == 1)
                {
                    if(isSameSet(parent, x, y))
                    {
                        printf("%s dan %s dalam set yang sama\n", kota1, kota2);
                    }
                    else
                    {
                        printf("%s dan %s tidak dalam set yang sama\n", kota1, kota2);
                    }
                }
                else
                {
                    printf("Invalid input. Please try again.\n");
                }
                getch();
                break;

            case 4:
                printf("Terima kasih telah menggunakan program ini.");
                getch();
                exit(0);
                break;

            default:
                printf("Mohon input yang benar! \n");
                getch();
        }
	}

	return 0;
}
