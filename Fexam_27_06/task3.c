#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int comp(const void*, const void*);
pthread_mutex_t lock;

void *routine(void* arg){
    pthread_mutex_lock(&lock);
    qsort(arr, M, sizeof(arr[0][0]), comp);
    pthread_mutex_unlock(&lock);
}

int main(int argc, char **argv){
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    char arr[N][M];
    FILE* fp;
    
    int  index = 0;
    while(i < N){
        char str[4];
        gets(str);
        if(strcmp("ROW", str) == 0){
            int ind;
            getc(ind);
            if((ind - '0')== i){
                for(int r = 0; r < M; r++){
                   arr[i][r] =  getc(stdin);
                }
            }else{
            fprintf(stderr,"Invalid data!\n");
        }
        }else{
            fprintf(stderr,"Invalid data!\n");
        }
        i++
    }

    pthread_t th[N];
    for (int i = 0; i < N; i++){
        if(pthread_create(&th[i], NULL, routine, *arr)){
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < N; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }

    char file[200];
    scanf("%s", &file);
    fp = fopen(file, "w");
    for(int o = 0; o < N; o++){
    fprintf(fp, "ROW %d ", (o+1));
    for(int g = 0; g < M; g++){
        fprintf(fp, "%d ", arr[o][g]);
    }
    fprintf(fp, " ");
        fclose(fp);
    }

    return 0;
}


int comp(const void* num1, const void* num2){
    return *(int*)num2 - *(int*)num1;
}