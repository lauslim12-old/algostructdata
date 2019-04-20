#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct temp {
    int id;
    char nama[50], bidang[50], jenis[50];
};

int main() {
    srand(time(NULL));
    int i = 0, j = 0, flag=0, r;
    struct temp dataku[50];
    FILE *fp;
    fp = fopen("KegiatanUMN.txt", "r");

    while(!feof(fp)) {
        fscanf(fp, "%d#%[^#]#%[^#]#%[^\n] \n", &dataku[i].id, &dataku[i].nama, &dataku[i].bidang, &dataku[i].jenis);
        i++;
    }

    fclose(fp);

    // Random number generation

    for(j = 0; j < i; j++) {
        r = rand() % 100;
        if(r == dataku[j].id){
            continue;
        }
    }

    printf("Random number: %d", r);
    return 0;
}
