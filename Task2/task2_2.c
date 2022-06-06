#include<stdio.h>
#include<stdint.h>
//gcc task2_2.c -o task22; ./task22

void flipOddBits(uint64_t*);

int main(){
    uint64_t mask = 0b00000000;
    printf("%ld\n", mask);
    flipOddBits(&mask);
    printf("%ld\n", mask);

    return 0;
}

void flipOddBits(uint64_t* mask){
    for(int bit = 0; bit < sizeof(mask); bit++){
        if(bit % 2 == 1){
            *mask ^= (1<<bit);
        }
    }

}