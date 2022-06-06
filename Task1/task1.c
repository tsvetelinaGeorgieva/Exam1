#include<stdio.h>
#include<math.h>

#define PI 3.142857

int cylinder(double, double, double*, double*);

int main(){
    double r, h, V, S;

    while(scanf("%lf %lf", &r, &h) != EOF){
        if(cylinder(r, h, &V, &S) == -1){
            printf("Invalid data\n");
        }else{
            printf("V = %.2lf, S = %.2lf\n", V, S);
        }
    }


    return 0;
}

int cylinder(double r, double h, double* V, double* S){
    if(r <= 0 || h <= 0){
        return -1;
    }else{
            *V = PI * pow(r, 2) * h;
            *S = 2 * PI * r * ( r + h);
        return 0;
    }
}