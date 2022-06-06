#include<stdio.h>
#include<stdint.h>

void mirrorBits(uint16_t* mask);

int main(){
    uint16_t mask = 1111;
    printf("%d\n", mask);
    mirrorBits(&mask);
    printf("%d\n", mask);
    return 0;
}

void mirrorBits(uint16_t* mask){
    for(int bit = 0; bit < (sizeof(mask)/2); bit++){
        if(!!(*mask & (1<<bit))){
            *mask = (1 << (bit + (sizeof(mask)/2)));
        }else{
            *mask = (0 << (bit + (sizeof(mask)/2)));
        }
    }


}