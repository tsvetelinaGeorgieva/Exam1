#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct node* next;
} node_t;

void print_list(node_t*);
void push(node_t**, int);
void listFree(node_t**);
void print(struct node_t *);
void print(struct node_t *);
struct Node* insertAfter(struct Node*, int, int);


int main(){
    node_t* list = NULL;
    int n, num;
    printf("Enter n: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Enter valid n >0!\n");
        int flag = 1; 
        while(flag != 0){
            scanf("%d", &n);
            if(n <= 0){
                printf("Enter valid n >0!\n");
                flag++;
            }else{
                flag = 0;
            }
        }
        
        for(int i = 0; i < n; i++){
            scanf("%d", &num);
            push(&list, num);
        }
    }

    print(list);
    insertAfter(list, 2, 5);
    listFree(&list);
    return 0;
}

void push(node_t** list, int data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = list;
    if (*list == NULL){
        *list = n;
        return;
    }
    node_t* current = *list;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = n;
}

void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%d ", current->data);
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

void print(struct node_t *cll){
    node_t* first = *cll;
    while(first != NULL){
        print("%d ", first->data);
        first = first->next;
        if(cll == first->next){
            return;
        }
    }
}

struct Node* insertAfter(struct Node* cll, int skipCount, int newElement){
    if(skipCount < 0 || skipCount > 1000000){
        return;
    }
    node_t* n = malloc(sizeof(node_t));
    n->data = newElement;
    node_t* current = *cll;
    node_t* prev = current;
    while(skipCount != 0){
        prev = current;
        current = current->next;
        skipCount--;
    }
    prev->next = n;
    n->next = current;

    return n;
}
