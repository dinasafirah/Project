#include <stdio.h>
#include <string.h>

typedef struct {
    char matkul[6], rombongan[2];
} praktikum_t;

typedef struct {
    char asisten1, asisten2;
} asisten_t;
typedef struct {
    int minggu;
    char hari[10]
} rule_t;

int main(){

  FILE *fileJadwal, *fileAsisten, *fileRule;
  char namaFile[80];
  int kode;
  praktikum_t arrJadwal[12][5][4];
  asisten_t arrAsisten[12][5][4];
  scanf("%d", &kode);
  while ((kode != 1) || (kode != 2) || (kode != 3)){
  switch(kode){
    case 1:
        //Membuat proyek baru
        printf("====== Membuat Proyek Baru ======\nMasukkan nama proyek:");
        scanf("%s", namaFile);
        fileJadwal = fopen(strcat(namaFile, "_rombongan.csv"), "w+");
        fileAsisten = fopen(strcat(namaFile, "_asisten.csv"), "w+");
        fileRule = fopen("Schedule_rule.txt", r);
        printf("[Menu Utama]\nPilih Mode:\n1. Tampilkan Schedule\n2. Schedule Manual\n3. Tampilkan Status Assignment Asisten\n");
        printf("4. Assign Asisten Manual\n5. Schedule Otomatis\n6. Assign Otomatis\n7. Rule Checker\n8. Simpan Proyek dan Keluar\n");
        scanf("%d", &kode);
        while (kode != 8){
          while ((kode != 1) || (kode != 2) || (kode != 3) || (kode != 4) || (kode != 5) || (kode != 6) || (kode != 7)){
             printf("Masukan salah. Masukan pilihan menu ulang");
             printf("[Menu Utama]\nPilih Mode:\n1. Tampilkan Schedule\n2. Schedule Manual\n3. Tampilkan Status Assignment Asisten\n");
             printf("4. Assign Asisten Manual\n5. Schedule Otomatis\n6. Assign Otomatis\n7. Rule Checker\n8. Simpan Proyek dan Keluar\n")
             scanf("%d", &kode);
           }
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
          }
        }
        if (kode) = 8 {
          //Simpan dan keluar
        }
    break;
    case 2:
        //Load proyek dari data
        printf("====== Load Proyek dari Data ======\nMasukkan nama proyek:");
        scanf("%s", namaFile);
        fileJadwal = fopen(strcat(namaFile, "_rombongan.csv"), "r+");
        fileAsisten = fopen(strcat(namaFile, "_asisten.csv"), "r+");
        fileRule = fopen("Schedule_rule.txt", r);

        break;
    case 3:
        printf("Keluar dari program...");
        break;
    default:
        printf("Masukan salah, pilih angka 1, 2 atau 3");
  }
  }
}
