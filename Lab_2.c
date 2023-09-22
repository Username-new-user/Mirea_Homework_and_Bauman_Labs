#include <stdio.h>
#include <math.h>

int input(float *x_begin, float *x_end, int *iterations);
float find_step(float x_begin, float x_end, int iterations);
int local_int_length_finder(float x);
int max_int_length_finder(float x_begin, float x_end, float step);
void for_function(float x_begin, float x_end, float step, int max_length);
void while_function(float x_begin, float x_end, float step, int max_length);
void do_while_function(float x_begin, float x_end, int iterations, float step, int max_length);

int main(){
    float x_begin, x_end;
    int iterations;
    if (input(&x_begin, &x_end, &iterations) == 0) {
        float step = find_step(x_begin, x_end, iterations);
        int max_length = max_int_length_finder(x_begin, x_end, step);
        for_function(x_begin, x_end, step, max_length);
        while_function(x_begin, x_end, step, max_length);
        do_while_function(x_begin, x_end, iterations, step, max_length);
    }
    return 0;
}

int input(float *x_begin, float *x_end, int *iterations) {
    printf("Enter x_begin, x_end and number of iterations:w\n");
    if (scanf("%f %f %d", x_begin, x_end, iterations) == 3) {
        return 0;
    } else {
        printf("Incorrect input!");
        return 1;
    }
}

float find_step(float x_begin, float x_end, int iterations) {
    return ((x_end - x_begin) / (iterations - 1));
}

int local_int_length_finder(float x) {
    int max_length = 0;
    int local_length = 1;
    long int_x = (long)x;
    while (int_x / 10 != 0) {
        ++local_length;
        int_x = int_x / 10;
    }
    if (max_length < local_length) {
        max_length = local_length;
    }
    return max_length;
}

int max_int_length_finder(float x_begin, float x_end, float step) {
    int max_length = 0;
    for (float x = x_begin; x <= x_end; x = x + step) {
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

void for_function(float x_begin, float x_end, float step, int max_length) {
    printf("for:\nx    ");
    for (float x = x_begin; x <= x_end; x = x + step) {
        if (x != 0) {
            printf("|% -*.*f ", local_int_length_finder(x) + 4, 3, x);
        } else {
            printf("|    0 ");
        }
    }
    printf("\nf(x) ");
    for (float x = x_begin; x <= x_end; x = x + step) {
        int length = local_int_length_finder((sin(x) * sin(x)) / x);
        printf("|");
        for (int i = 0; i < local_int_length_finder(x) - length; ++i) {
            printf(" ");
        }
        if (x != 0) {
            printf("% -*.*f ", length + 4, 3, (sin(x) * sin(x)) / x);
        } else {
            printf(" none ");
        }
    }
}

void while_function(float x_begin, float x_end, float step, int max_length) {
    float x = x_begin;
    printf("\n\nwhile:\nx    ");
    while (x <= x_end) {
        if (x != 0) {
            printf("|% -*.*f ", local_int_length_finder(x) + 4, 3, x);
        } else {
            printf("|    0 ");
        }
        x += step;
    }
    printf("\nf(x) ");
    x = x_begin;
    while (x <= x_end) {
        int length = local_int_length_finder((sin(x) * sin(x)) / x);
        printf("|");
        for (int i = 0; i < local_int_length_finder(x) - length; ++i) {
            printf(" ");
        }
        if (x != 0) {
            printf("% -*.*f ", length + 4, 3, (sin(x) * sin(x)) / x);
        } else {
            printf(" none ");
        }
        x += step;
    }
}

void do_while_function(float x_begin, float x_end, int iterations, float step, int max_length) {
    int i = 0;    
    printf("\n\ndo while:\nx    ");
    do {
        float x = x_begin + step * i;
        int length = local_int_length_finder(x);
        if (x != 0) {
            printf("|% -*.*f ", local_int_length_finder(x) + 4, 3, x);
        } else {
            printf("|    0 ");
        }
        ++i;
    } while (i < iterations);
    i = 0;
    printf("\nf(x) ");
    do {
        float x = x_begin + step * i;
        int length = local_int_length_finder((sin(x) * sin(x)) / x);
        printf("|");
        for (int i = 0; i < local_int_length_finder(x) - length; ++i) {
            printf(" ");
        }
        if (x != 0) {
            printf("% -*.*f ", length + 4, 3, (sin(x) * sin(x)) / x);
        } else {
            printf(" none ");
        }
        ++i;
    } while (i < iterations);
}
