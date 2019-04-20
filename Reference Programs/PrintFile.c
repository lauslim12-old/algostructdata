#include <stdio.h>
int main(){
    char id[10], nama[50], bidang[50], jenis[20];
    FILE *data;
    data = fopen("KegiatanUMN.txt", "r");
    while(!feof(data)) {
        fscanf(data, "%[^#]#%[^#]#%[^#]#%[^\n] \n", &id, &nama, &bidang, &jenis);
        printf("%s %s %s %s \n", id, nama, bidang, jenis);
    }
    fclose(data);
    getchar();
    return 0;
}
