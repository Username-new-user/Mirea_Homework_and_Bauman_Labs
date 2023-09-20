#include <stdio.h>
#define EPS 0.000001
#define ON_THE_LINE 0
#define ABOVE_THE_LINE 1
#define UNDER_THE_LINE -1



void readvalue(float *x, float *y);
int location(float x, float y);
float equation(float x, float k, float b);
void print(int flag);


int main() {
    float x,y;
    readvalue(&x, &y);
    location(x, y);
    print(location(x, y));
    return 0;
}
void readvalue(float *x, float *y) {
    printf("Line equation: y = 0.5*x + 1\n");
    printf("Enter point coordinations\n");
    int a = scanf("%f %f", x, y);
    if (a != 2) {
        printf("Incorrect input\n");
    }
}

int location(float x, float y){
    float line = equation(x, 0.5, 1);
    int flag;
    if (line + EPS < y) {
        flag = ABOVE_THE_LINE;
    } else if (line - EPS > y)  {
        flag = UNDER_THE_LINE;
    } else {
        flag = ON_THE_LINE;
    }
    return flag;
}

void print(int flag) {
    printf("Result: ");
     switch (flag) {
        case 0:            
            printf("Point is on the line\n");
            break;        
        case -1:
            printf("Point is under the line\n");         
            break;
        case 1: 
            printf("Point is above the line\n");
            break;   
    }

}

float equation(float x, float k, float b){
    return k * x + b;
}