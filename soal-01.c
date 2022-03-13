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
			data=realloc(data,(n+1)*sizeof(Data_sampel));
		}
		token = strtok(line,",");
		(data+n)->sekuens=(char*)malloc((strlen(token)) * sizeof(char));
		strcpy((data+n)->sekuens,token);

		(data+n)->panjang_sekuens=strlen(token);

		token = strtok(NULL, ",");
		(data+n)->nama_sampel=(char*)malloc((strlen(token)) * sizeof(char));
		strcpy((data+n)->nama_sampel,token);
	
		n++; 
	}fclose(seq_file);

	*jml_sampel=n;

	return data;
}

int tiga_sekuens(Data_sampel* data, int n, char sekuens_ref[4]){
	int sama=1;
	int total_sama=0;
	for(int i=0; i<(data+n)->panjang_sekuens; i++){
		if((i+1)%3==1 && (data+n)->sekuens[i]!=sekuens_ref[0]){
			sama=0;
		}
		else if((i+1)%3==2 && (data+n)->sekuens[i]!=sekuens_ref[1]){
			sama=0;
		}
		else if((i+1)%3==0 && (data+n)->sekuens[i]!=sekuens_ref[2]){
			sama=0;
		}

		if((i+1)%3==0){
			if (sama==1){
				total_sama++;
			}
			sama=1;
		}
	}
	return total_sama;
}

int main(){
	Data_sampel* data;
	int jml_sampel, i, total_sama_per_sampel =0;
	char sekuens_ref[4];

	data=(Data_sampel*)malloc(sizeof(Data_sampel));

	data=open_file(data, &jml_sampel);

	printf("Masukkan 3 sekuens referensi: ");
	scanf("%s", &sekuens_ref);

	printf("Nama sampel - Jumlah 3 sekuens yang sama dengan sekuens referensi\n");
	for(i=0; i<jml_sampel; i++){
		total_sama_per_sampel=tiga_sekuens(data, i, sekuens_ref);
		printf("%s - %d\n", (data+i)->nama_sampel, total_sama_per_sampel);
	}    

	free(data);

	return 0;
}
