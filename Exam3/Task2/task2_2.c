#include<stdio.h>
#include<stdint.h>

int main(){
    uint16_t num;
    FILE* fp;
    char nameTxt[50];
    printf("Enter yhe name of txt file: ");
    scanf("%s", nameTxt);
    char mode[3];
    printf("Enter the mode of file (txt): ");
    scanf("%s", mode);
    fp = fopen(nameTxt, mode);
    if(fp == NULL){
        fprintf(stderr, "Read error txt.\n");
    }
    FILE* fpB;
    char nameBin[50];
    printf("Enter the name of bin file: ");
    scanf("%s", nameBin);
    fpB = fopen(nameBin, "wb");
    if(fpB == NULL){
        fprintf(stderr, "Write error bin.\n");
    }

    while(fp != NULL){
        fscanf(fp, "%hd", &num);
        fwrite(&num, sizeof(num), 1, fpB);
    }

    fclose(fp);
    fclose(fpB); 
    return 0;
}