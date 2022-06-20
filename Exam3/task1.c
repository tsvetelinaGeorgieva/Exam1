#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<time.h>

#define COUNT 5

typedef struct point{
    double x;
    double y;
}point_t;

typedef struct rectangle{
    point_t A;
    point_t B;
}rectangle_t;

typedef struct node {
    rectangle_t rec;
    struct node* next;
} node_t;

void print_list(node_t*);
void listFree(node_t**);
void push(node_t**, rectangle_t);
double randDouble(double, double);
double areaRects(node_t*);
void deleteNth(node_t**, size_t, size_t);
node_t* sortedMerge(node_t*, node_t*, int(*)(rectangle_t, rectangle_t));
void frontBackSplit(node_t*, node_t**, node_t**);
void mergeSort(node_t**, int(*)(rectangle_t, rectangle_t));
int cmp(rectangle_t, rectangle_t);


int main(){
    srand(time(NULL));
    node_t* list = NULL;

    for(int i = 0; i < COUNT; i++){
        rectangle_t* r1 = malloc(sizeof(rectangle_t));
        r1->A.x = randDouble(-10.0, 10.0);
        r1->B.x = randDouble(-10.0, 10.0);
        r1->A.y = randDouble(-10.0, 10.0);
        r1->B.y = randDouble(-10.0, 10.0);
        push(&list, *r1);
    }
    print_list(list);
    printf("The sum of rec areas is: %.2lf\n", areaRects(list));
    deleteNth(&list, -5, 1);
    print_list(list);

    mergeSort(&list, cmp);
    print_list(list);

    listFree(&list);
    return 0;
}



void print_list(node_t* list){
    node_t* current = list;
    while (current){
        printf("%.2lf %.2lf %.2lf %.2lf \n", current->rec.A.x, current->rec.A.y, current->rec.B.x, current->rec.B.y);
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

void push(node_t** list, rectangle_t rec){
    node_t* n = malloc(sizeof(node_t));
    n->rec = rec;
    n->next = *list;
    *list = n;
}

double randDouble(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

double areaRects(node_t* list){
    if(list == NULL){
        return -1;
    }
    node_t* arear = list;
    double fabsX = 0, fabsY = 0;
    double area = 1;
    double sumArea = 0;

    for(int i = 0; i < COUNT; i++){
        fabsX = fabs(arear->rec.A.x - arear->rec.B.x);
        fabsY = fabs(arear->rec.A.y - arear->rec.B.y);
        area = fabsX *fabsY;
        sumArea += area;
       // printf("%.2lf %.2lf %.2lf %.2lf \n", arear->rec.A.x, arear->rec.A.y, arear->rec.B.x, arear->rec.B.y);
        //printf("Area: %.2lf\n", area);
        arear = arear->next;
    }
    return sumArea;
}

void deleteNth(node_t** list, size_t min, size_t max){
    if (*list == NULL){
        return;
    }
    node_t* current = *list;
    node_t* prev = current;
    double area = 1;    
    while(current != NULL){
        area = fabs(current->rec.A.x - current->rec.B.x) * fabs(current->rec.A.y - current->rec.B.y);
    if(area > min && area < max){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
    }
}


node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(rectangle_t, rectangle_t)){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->rec, listB->rec) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(node_t** list, int(*cmp)(rectangle_t, rectangle_t)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

int cmp(rectangle_t r1, rectangle_t r2){
    double areaR1 = 1;
    double areaR2 = 1;

    areaR1 = fabs(r1.A.x - r1.B.x) * fabs(r1.A.y - r1.B.y);
    areaR2 = fabs(r2.A.x - r2.B.x) * fabs(r2.A.y - r2.B.y);

    return areaR1 - areaR2;
}