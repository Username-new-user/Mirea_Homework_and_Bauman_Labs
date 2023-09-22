#include <stdio.h>
#include <math.h>

int input(double *x_begin, double *x_end, int *iterations);
float find_step(double x_begin, double x_end, int iterations);
int int_length_finder(double x_begin, double x_end, double iterations);
void for_function(double x_begin, double x_end, double step, int lenght);
void while_function(double x_begin, double x_end, double step, int length);
void do_while_function(double x_begin, double x_end, int iterations, double step, int length);

int main(){
    double x_begin, x_end, step;
    int iterations, length;
    if (input(&x_begin, &x_end, &iterations) == 0) {
        step = find_step(x_begin, x_end, iterations);
        length = int_length_finder(x_begin, x_end, step);
        for_function(x_begin, x_end, step, length);
        while_function(x_begin, x_end, step, length);
        do_while_function(x_begin, x_end, iterations, step, length);
    }
    return 0;
}

int input(double *x_begin, double *x_end, int *iterations) {
    printf("Enter:\n");
    if (scanf("x от %f до %f, %d итерации.", x_begin, x_end, iterations) == 3) {
        return 0;
    } else {
        printf("Incorrect input!");
        return 1;
    }
}

float find_step(double x_begin, double x_end, int iterations) {
    return ((x_end - x_begin) / (iterations - 1));
}

int int_length_finder(double x_begin, double x_end, double step) {
    int max_length = 0;
    for (double x = x_begin; x <= x_end; x = x + step) {
        int local_length = 1;
        int int_x = (int)x;
        while (int_x / 10 != 0) {
            ++local_length;
            int_x = int_x / 10;
        }
        if (max_length < local_length) {
            max_length = local_length;
        }
    }    return max_length;
}

void for_function(double x_begin, double x_end, double step, int length) {
    printf("for:\nx    ");
    for (float x = x_begin; x <= x_end; x = x + step) {
        printf("|% -*.*f ", length + 4, 3, x);
    }
    printf("\nf(x) ");
    for (float x = x_begin; x <= x_end; x = x + step) {
        printf("|% -*.*f ", length + 4, 3, (sin(x) * sin(x)) / x);
    }
}

void while_function(double x_begin, double x_end, double step, int length) {
     x = x_begin;
    printf("\n\nwhile:\nx    ");
    while (x <= x_end) {
        printf("|% -*.*f ", length + 4, 3, x);
        x += step;
    }
    printf("\nf(x) ");
    x = x_begin;
    while (x <= x_end) {
        printf("|% -*.*f ", length + 4, 3 , (sin(x) * sin(x)) / x);
        x += step;
    }
}

void do_while_function(double x_begin, double x_end, int iterations, double step, int length) {
    int i = 0;
    printf("\n\ndo while:\nx    ");
    do {
        float x = x_begin + step * i;
        printf("|% -*.*f ", 2 * length + 2, 3, x);
        ++i;
    } while (i < iterations);
    i = 0;
    printf("\nf(x) ");
    do {
        float x = x_begin + step * i;
        printf("|% -*.*f ", 2 * length + 2, 3, (sin(x) * sin(x)) / x);
        ++i;
    } while (i < iterations);
}
