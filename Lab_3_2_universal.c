#include<stdio.h>
#include<math.h>

int input(float *a, float *b, double *eps);

void print(double answer);

double function_we_use(double x);
double (get_x_0i(float a, float b, int n, int i));
double (get_x_2i(float a, float b, int n, int i));
double get_delta(double x_0i, double x_2i);
double area_i(float a, float b, int n, int i);
double summary_of_areas(float a, float b, int n);
double answer_finder(float a, float b, double eps);

int main() {
    float a, b;
    double eps;
    if (input(&a, &b, &eps) == 0) {
        if (a <= 0) {
            printf("Function does not exist!\n");
        } else {
            print(answer_finder(a, b, eps));
        }
    }
    return 0;
}

int input(float *a, float *b, double *eps) {
    printf("Enter a, b and eps:\n");
    if (scanf("%f %f %lf", a, b, eps) == 3) {
        return 0;
    } else {
        printf("Incorrect input!\n");
        return 1;
    }
}

double function_we_use(double x) {
    double f_x = 2 * x;
    return f_x;
}

double (get_x_0i(float a, float b, int n, int i)) {
    double x_0i;
    x_0i = a + ((b - a) / n) * (i - 1);
    return x_0i;
}

double get_x_2i(float a, float b, int n, int i) {
    double x_2i;
    x_2i = a + ((b - a) / n) * i;
    return x_2i;
}

double get_delta(double x_0i, double x_2i) {
    double delta = (x_2i - x_0i) / 2;
    return delta;
}

double area_i(float a, float b, int n, int i) {
    double area;
    double x_0i = get_x_0i(a, b, n, i);
    double x_2i = get_x_2i(a, b, n, i);
    double delta = get_delta(x_0i, x_2i);
    double x_1i = x_0i + delta;
    area = (delta / 3) * (function_we_use(x_0i) + 4 * function_we_use(x_1i) + function_we_use(x_2i));
    return area;
}

double summary_of_areas(float a, float b, int n) {
    double summary = 0;
    for (int i = 1; i <= n; ++i) {
        summary += area_i(a, b, n, i);
    }
    return summary;
}

double answer_finder(float a, float b, double eps) {
    double answer_now = -10, answer_previous;
    int n = 1;
    do {
        answer_previous = answer_now;
        answer_now = summary_of_areas(a, b, n);
        n *= 2;
    } while(fabs(answer_previous - answer_now) >= eps);
    return answer_now;
}

void print(double answer) {
    printf("%.*f\n", 8, answer);
}
