/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 4 - Structures and Dynamic Arrays
*Percobaan        : -
*Hari dan Tanggal : Selasa, 15 Maret 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char *sekuens;
	char *nama_sampel;
	int panjang_sekuens;
} Data_sampel;

Data_sampel* open_file(Data_sampel* data, int* jml_sampel){
    FILE* seq_file;
    char namaFile[10]; //asumsi maksimal panjang nama file 7
    char line[255]; 
    char* token;
    int n=0;

    printf("Masukkan nama file: ");
    scanf("%s", &namaFile);

    seq_file=fopen(namaFile, "r");

    while (fgets(line, 81, seq_file)){
        if(n>0){
            data=...;
        }
        token = strtok(line,",");
        (data+n)->sekuens = ...;
        strcpy((data+n)->sekuens,token);

        (data+n)->panjang_sekuens=strlen(token);

        token = strtok(NULL, ",");
        (data+n)->nama_sampel = ...;
        strcpy((data+n)->nama_sampel,token);
    
        n++; 
    }fclose(seq_file);

    *jml_sampel=n;

    return data;
}


int main(){
	Data_sampel* data;
    
    data=...;
	
	//template input output
    data=open_file(..., &...);

	printf("Masukkan 3 sekuens referensi: ");
	scanf("%s", ...);

	printf("Nama sampel - Jumlah 3 sekuens yang sama dengan sekuens referensi\n");
	printf("%s - %d\n", ..., ...);

	return 0;
}
