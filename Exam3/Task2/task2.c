#include<stdio.h>
#include<stdint.h>

int main(){
    uint8_t arr[] = {1, 1, 1, 1};
    FILE* fp;
    char fileName[50];
    printf("Enter the name of file (bin): ");
    scanf("%s", fileName);
    char mode[4];
    printf("Enter the mode of file (bin): ");
    scanf("%s", mode);
    fp = fopen(fileName, mode);
    if(fp == NULL){
        fprintf(stderr, "Write error (bin).\n");
    }

    for(int i = 0; i < 4; i++){
        fwrite(&arr[i], sizeof(arr[i]), 1, fp);
    }    
    fclose(fp);

    FILE* fp1;
     fp1 = fopen(fileName, "rb");
     if(fp1 == NULL){
         fprintf(stderr, "Read error (bin).\n");
     }

     FILE* fp2;
    char fileNameTxt[50];
    printf("Enter the name of file (txt): ");
    scanf("%s", fileNameTxt);
    fp2 = fopen(fileNameTxt, "w");
    if(fp2 == NULL){
         fprintf(stderr, "Write error (txt).\n");
    }

    uint8_t num;
    if(fp1 != NULL){
        fscanf(fp1, "%hhd", &num);
        fprintf(fp2, "%hhd\n", num);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}