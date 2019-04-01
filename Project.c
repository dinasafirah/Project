#include <stdio.h>
#include <string.h>

printJadwal(char **arrJadwal);

int main(){

  FILE *fileJadwal, *fileAsisten, *fileRule;
  char namaFile[80];
  int kode;
  scanf("%d", &kode);
  while ((kode != 1) || (kode != 2) || (kode != 3)){
  switch(kode){
    case 1:
        //Membuat proyek baru
        printf("====== Membuat Proyek Baru ======\nMasukkan nama proyek:");
        scanf("%s", namaFile);
        fileJadwal = fopen(strcat(namaFile, "_rombongan.csv");, "wb");
        fileAsisten = fopen(strcat(namaFile, "_asisten.csv");, "wb");
        printf("[Menu Utama]\nPilih Mode:\n1. Tampilkan Schedule\n2. Schedule Manual\n3. Tampilkan Status Assignment Asisten\n");
        printf("4. Assign Asisten Manual\n5. Schedule Otomatis\n6. Assign Otomatis\n7. Rule Checker\n8. Simpan Proyek dan Keluar\n");
        scanf("%d", &kode);
        switch(kode){
        case 1:
            //tampilkan schedule
            break;
        case 2:
            //schedule manual
            break;
        case 3:
            //Tampilkan Status Assignment Asisten
            break;
        case 4:
            //Assign Asisten Manual
            break;
        case 5:
            //Schedule Otomatis
            break;
        case 6:
            //Assign Otomatis
            break;
        case 7:
            //Rule Checker
            break;
        case 8:
            //Keluar dan Simpan
            break;
        }
        break;
    case 2:
        //Load proyek dari data


        break;
    case 3:
        printf("Keluar dari program...");
        break;
    default:
        printf("Masukan salah, pilih angka 1, 2 atau 3");
  }
  }
}
printJadwal(char **arrJadwal){
    int i = 3;
    int j = 0;
    char hari[6][5] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"}
    printf("[Schedule Praktikum Sementara]");
    printf("|--------------------------------------------------------------------|\n");
    printf("|Ruang Praktikum\t|    LAB1    |    LAB2    |     LAB3   |   LSS     |\n");
    printf("|-----------------|------------|------------|------------|-----------|\n");
    printf("|Minggu\t|\tHari\t|------------|------------|------------|-----------|\n");
    printf("|-----------------|------------|------------|------------|-----------|\n");
    for (i = 3; i <= 12; i++){
        for j = 0; j < 5; j++){
            printf("|%d\t|\t%s\t|\t\s\t|\t\t\t|\t\t\t|\t\t\t|\n", i, *hari[j]);
        }
    }
}


