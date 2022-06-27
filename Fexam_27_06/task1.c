#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define ITEMS_COUNT 5

typedef struct item{
    uint16_t num;
    char des[251];
    double teglo;
    double price;
} Item;

typedef struct node {
    Item item;
    struct node* next;
} node_t;

int randInt(int, int);
double randDouble(double, double);
void randomDes(char*);
void push(node_t**, Item);
void print_list(node_t*);
void listFree(node_t**);
double totalItemWeigth(node_t *);
node_t* minPriceItem(node_t*);

int main(){
    srand(time(NULL));
    node_t* list = NULL;
    int arr[ITEMS_COUNT];
    for(int i = 0; i < ITEMS_COUNT; i++){
        Item *item = malloc(sizeof(Item));
        arr[i] = randInt(0, 256);
        int id = arr[i];
        int flag = 1;
        while(flag != 0){
            for(int j = 0; j < ITEMS_COUNT; j++){
                if(arr[j] == id){
                    id = randInt(0, 256);
                    flag++;
                }
                break;
            }
            if(flag == 1){
                flag = 0;
            }else{
                flag = 1;
            }
        }
        item->num = id;
        randomDes(item->des);
        item->teglo = randDouble(0.1, 100.0);
        item->price = randDouble(1.0, 1500.0);
        push(&list, *item);
    }
    print_list(list);
    if(totalItemWeigth == -1){
        fprintf(stderr, "Error in totalItemWeight.\n");
    }else{
        printf("Total weight: %.2lf\n", totalItemWeigth(list));
    }
    node_t* minPrice;
    minPrice = minPriceItem(list);
    if(minPrice == NULL){
        fprintf(stderr, "Error in minPriceItem.\n");
    }else{
        printf("Min price: %.2f\n", minPrice->item.price);
    }
    
    listFree(&list);
    return 0; 
}

int randInt(int min, int max){
    return min + (rand()% (max + 1 - min)); 
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void randomDes(char* des){
    int countOfword = randInt(5, 10);
    des[0] = randInt('A', 'Z');
    int len = randInt(1, 10);
    for(int j = 1; j < len; j++){
            des[j] = randInt('a', 'z');
        }
        des[len] = ' ';
    for(int i = 1; i < countOfword; i++){
        int lenW = randInt(1, 10);
        for(int p = len; p < len + lenW; p++){
            des[p] = randInt('a', 'z');
        }
        des[len + lenW] = ' ';
        len += lenW;
    }
    des[strlen(des) + 1] = '\0';
}

void push(node_t** list, Item item){
    node_t* n = malloc(sizeof(node_t));
    n->item = item;
    n->next = *list;
    *list = n;
}
void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("Number: %d Des: %s Weight: %.2lf Price: %.2lf \n", current->item.num, current->item.des, current->item.teglo, current->item.price);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

double totalItemWeigth(node_t *item){
    if(item == NULL){
        return -1;
    }

    double weight = 0;
    while(item != NULL){
        weight += item->item.teglo;
        item = item->next;
    }

    if(weight == 0){
        return -1;
    }else{
        return weight;
    }

}

node_t* minPriceItem(node_t* items){
    if(items == NULL){
        return NULL;
    }
    node_t *min = NULL;
    min->item.price = items->item.price;
    items = items->next;
    while(items != NULL){
        if(min->item.price > items->item.price){
            min->item.price = items->item.price;
        }
        items = items->next;
    }
    return min;
}