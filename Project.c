#include <stdio.h>
#include <string.h>

typedef struct {
    char matkul[6], rombongan;
    int nomor;
} praktikum_t;

typedef struct {
    char asisten1, asisten2;
} asisten_t;
typedef struct {
    int minggu;
    char hari[10]
} rule_t;

int ruleCheck(FILE fRule, praktikum_t arrP, asisten_t arrA);
int main(){

  FILE *fileJadwal, *fileAsisten, *fileRule;
  char namaFile[80], line[100];
  int kode, i, j, k, minggu, hari;
  char* token = NULL;
  char arrHari[5][6] = {"Senin", "Selasa", "Rabu", "Kamis", "Jumat"};
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
              printf("[DRC]\nMasukkan File DRC (dalam format .txt):");
              scanf("%s", namaFile);
              fileRule = fopen(strcat(namaFile,".txt"), "r");
              while (fileRule==NULL){
                printf("Masukan file salah, coba masukan kembali");
                printf("[DRC]\nMasukkan File DRC (dalam format .txt):");
                scanf("%s", namaFile);
                fileRule = fopen(strcat(namaFile,".txt"), "r");
              }
              ruleCheck(fileRule, arrJadwal, arrAsisten);
              break;
          }
        }
        if (kode) = 8 {
          fprintf(fileJadwal, "Ruang Praktikum, LAB1, LAB2, LAB3 , LSS\n");
          for (minggu=3; minggu<12; minggu++){
                for(hari=0; hari<5; hari++){
                    for (i = 0; i<4; i++){
                        fprintf(fileJadwal, "%d,%s,", minggu, arrHari[hari]);
                        if (arrJadwal[minggu][hari][i].rombongan != NULL)
                            if (arrJadwal[minggu][hari][i].nomor != NULL)
                                fprintf(fileJadwal,"%s-%c%d",arrJadwal[minggu][hari][i].matkul,arrJadwal[minggu][hari][i].rombongan,
                                        arrJadwal[minggu][hari][i].nomor);
                            else
                                fprintf(fileJadwal,"%s-%c",arrJadwal[minggu][hari][i].matkul,arrJadwal[minggu][hari][i].rombongan);
                        else
                            fprintf(fileJadwal,",,");
                        fprintf("\n");
                    }
                }
          }
          fprintf(fileAsisten, "Ruang Praktikum, LAB1, LAB2, LAB3 , LSS\n");
          for (minggu=3; minggu<12; minggu++){
                for(hari=0; hari<5; hari++){
                    for (i = 0; i<4; i++){
                        fprintf(fileAsisten, "%d,%s,", minggu, arrHari[hari]);
                        if (arrAsisten[minggu][hari][i].asisten1 != NULL)
                                fprintf(fileAsisten,"%c,%c",arrAsisten[minggu][hari][i].asisten1,arrAsisten[minggu][hari][i].asisten2);
                        else
                            fprintf(fileAsisten,",,");
                        fprintf("\n");
                    }
                }
          }
        }
        fclose(fileAsisten);
        fclose(fileJadwal);
        fclose(fileRule);
    break;
    case 2:
        //Load proyek dari data
        printf("====== Load Proyek dari Data ======\nMasukkan nama proyek:");
        scanf("%s", namaFile);
        fileJadwal = fopen(strcat(namaFile, "_rombongan.csv"), "r+");
        fileAsisten = fopen(strcat(namaFile, "_asisten.csv"), "r+");
        i = 0;
        while ((fgets(line, 100, fileJadwal) != NULL)&&(i < 60)){
            j = 0;
            for (token = strtok(line, ","); token != NULL && j < 6; token = strtok(NULL, ",")){
                if (j = 0)
                    minggu = token;
                else if (j = 1){
                    for (k=0;k<5;k++){
                        if(strcmp(token, *arrHari[k])=0)
                            hari = k;
                    }
                } else {
                    strncpy(arrJadwal[minggu][hari][j].matkul,token,6);
                    strncpy(arrJadwal[minggu][hari][j].rombongan,&token[7],1);
                    if (strlen(token) = 8)
                        strncpy(arrJadwal[minggu][hari][j].nomor,&token[8],1);
                }
            }
            i++;
        }
        i = 0;
        while ((fgets(line, 100, fileAsisten) != NULL)&&(i < 60)){
            j = 0;
            for (token = strtok(line, ","); token != NULL && j < 6; token = strtok(NULL, ",")){
                if (j = 0)
                    minggu = token;
                else if (j = 1){
                    for (k=0;k<5;k++){
                        if(strcmp(token, *hari[k])=0)
                            hari = k;
                    }
                } else {
                    strncpy(arrAsisten[minggu][hari][j].asisten1,token,1);
                    strncpy(arrAsisten[minggu][hari][j].asisten2,&token[2],1);
                }
            }
            i++;
        }
        //Asalnya mau disatuin, tapi karena berada dalam kondisional dan ada kondisional ke 3 jadinya susah. Copas yang atas deh.
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
              printf("[DRC]\nMasukkan File DRC (dalam format .txt):");
              scanf("%s", namaFile);
              fileRule = fopen(strcat(namaFile,".txt"), "r");
              while (fileRule==NULL){
                printf("Masukan file salah, coba masukan kembali");
                printf("[DRC]\nMasukkan File DRC (dalam format .txt):");
                scanf("%s", namaFile);
                fileRule = fopen(strcat(namaFile,".txt"), "r");
              }
              ruleCheck(fileRule, arrJadwal, arrAsisten);
             break;
          }
        }
        if (kode) = 8 {
          //Simpan dan keluar
            fprintf(fileJadwal, "Ruang Praktikum, LAB1, LAB2, LAB3 , LSS\n");
            for (minggu=3; minggu<12; minggu++){
                for(hari=0; hari<5; hari++){
                    for (i = 0; i<4; i++){
                        fprintf(fileJadwal, "%d,%s,", minggu, arrHari[hari]);
                        if (arrJadwal[minggu][hari][i].rombongan != NULL)
                            if (arrJadwal[minggu][hari][i].nomor != NULL)
                                fprintf(fileJadwal,"%s-%c%d",arrJadwal[minggu][hari][i].matkul,arrJadwal[minggu][hari][i].rombongan,
                                        arrJadwal[minggu][hari][i].nomor);
                            else
                                fprintf(fileJadwal,"%s-%c",arrJadwal[minggu][hari][i].matkul,arrJadwal[minggu][hari][i].rombongan);
                        else
                            fprintf(fileJadwal,",,");
                        fprintf("\n");
                    }
                }
          }
          fprintf(fileAsisten, "Ruang Praktikum, LAB1, LAB2, LAB3 , LSS\n");
          for (minggu=3; minggu<12; minggu++){
                for(hari=0; hari<5; hari++){
                    for (i = 0; i<4; i++){
                        fprintf(fileAsisten, "%d,%s,", minggu, arrHari[hari]);
                        if (arrAsisten[minggu][hari][i].asisten1 != NULL)
                                fprintf(fileAsisten,"%c,%c",arrAsisten[minggu][hari][i].asisten1,arrAsisten[minggu][hari][i].asisten2);
                        else
                            fprintf(fileAsisten,",,");
                        fprintf("\n");
                    }
                }
          }
        }
        fclose(fileAsisten);
        fclose(fileJadwal);
        fclose(fileRule);
    break;
        break;
    case 3:
        printf("Keluar dari program...");
        break;
    default:
        printf("Masukan salah, pilih angka 1, 2 atau 3");
  }
  }
}
int ruleCheck(FILE fRule, praktikum_t arrP, asisten_t arrA){
    rule_t arrR;
    int i,j,x,check = 1;
    j=0;
    while (fscanf(fRule,"%d %s", &(arrR.minggu),arrR.hari) == 1){
        for (i =0; i<5; i++){
            if (strcmp(arrR.hari,*arrHari[i])=0)
                x = i;
        }
        i = 0;
        for (i =0; i<4; i++){
            if (arrP[arrR.minggu][x][i].matkul != NULL){
                check = 0;
                printf("Rule ke %d tidak terpenuhi", j+1);
            }
        j++;
        }
    printf("%d/%d Rule Is Checked", j, j);
    if (check = 1)
        printf("Program Lulus Pengecekan");
    else
        printf("Program Gagal Pengecekan");
    }
    return(0);
}
