#include<stdio.h>
#include<math.h>

int input(double *eps);
double counter(double eps);
void print(double counter);

int main() {
    double eps;
    if (input(&eps) == 0) {
        print(counter(eps));
    } else {
        printf("Incorrect input!\n");
    }
}

int input(double *eps) {
    printf("Enter the value of eps:\n");
    if (scanf("%lf", eps) == 1) {
        return 0;
    } else {
        return 1;
    }
}

double counter(double eps) {
    int factorial = 1, n = 1;
    double sum_now = 1, sum_before = 0;
    while (sum_now - sum_before > eps) {
        ++n;
        sum_before = sum_now;
        factorial *= n;
        sum_now += pow(-1.0, n) / factorial;
    }
    return sum_now; //or sum_before
}

void print(double count) {
    printf("%.*f\n", 20, count);
}
