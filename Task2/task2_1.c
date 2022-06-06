#include<stdio.h>
#include<stdint.h>
//gcc task2_1.c -o task21; ./task21

unsigned bitsNCount(uint64_t, uint32_t, uint16_t, uint8_t);

int main(){
    uint64_t mask1 = 4;
    uint32_t mask2 = 6;
    uint16_t mask3 = 2;
    uint8_t mask4 = 1; 
    int count = 0;


    count = bitsNCount(mask1, mask2, mask3, mask4);
    printf("%d\n", count);

    return 0;
}

unsigned bitsNCount(uint64_t mask1, uint32_t mask2, uint16_t mask3, uint8_t mask4){
    int count = 0;
    for(int bit1 = 0; bit1 < sizeof(mask1); bit1++){
        if(!!(mask1 & (1 << bit1))){
        count++;
        }
    }

    for(int bit2 = 0; bit2 < sizeof(mask2); bit2++){
        if(!!(mask2 & (1 << bit2))){
        count++;
        }
    }

    for(int bit3 = 0; bit3 < sizeof(mask3); bit3++){
        if(!!(mask3 & (1 << bit3))){
        count++;
        }
    }

    for(int bit4 = 0; bit4 < sizeof(mask4); bit4++){
        if(!!(mask4 & (1 << bit4))){
        count++;
        }
    }

    return count;
}