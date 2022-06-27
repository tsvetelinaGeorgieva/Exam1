#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>



int main(int argc, char **argv){
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < argc - 1; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            for(int p = 1; p < argc; p++){
                close(fd[0]);
                FILE* fp;
                fp = fopen(argv[p], "r");
                if (fp == NULL){
                    fprintf(stderr, "%s - don't have reading permissions!\n", argv[p]);
                    return EXIT_FAILURE;
                }
                int num;
                int sum = 0;
                while((fscanf(fp, "%d", &num)) != EOF){
                    while(num != 0){
                        sum += num%10;
                        num /=10;
                    }
                }
                if(sum == 0){
                   fprintf(stderr, "%s - not exists!\n", argv[p]);
                }else{
                    printf("%s - %d\n", argv[p], sum);
                }
                write(fd[1], &sum, sizeof(sum));
                close(fd[1]);
                fclose(fp);
            }
            exit(EXIT_SUCCESS);
        }else{
            int totalsum = 0;
            for(int p = 1; p < argc; p++){
            close(fd[1]);
            int sum;
            read(fd[0], &sum, sizeof(sum));
            totalsum += sum;
            close(fd[0]);
            }
            //sleep(1);
            printf("Total sum: %d\n", totalsum);
        }
    }
    for (int i = 0; i < argc; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}