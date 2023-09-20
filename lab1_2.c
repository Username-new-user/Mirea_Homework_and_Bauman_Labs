#include <stdio.h>
#define EPS 0.000001
#define UNDER_THE_LINE -1
#define ABOVE_THE_LINE 1
#define ON_THE_LINE 0 

int read_coordinations(float *x, float *y);

int line_1(float x, float y);
int line_2(float x, float y);
int line_3(float x, float y);

void print_if_not_on_line(int flag_1, int flag_2, int flag_3);
void print_if_on_line(int flag_1, int flag_2, int flag_3);

float equation(float x, float k, float b);

int main() {
    float x, y;
    if (read_coordinations(&x, &y) == 0) {
        line_1(x, y);
        line_2(x, y);
        line_3(x, y);
        print_if_not_on_line(line_1(x, y), line_2(x, y), line_3(x, y));
        print_if_on_line(line_1(x, y), line_2(x, y), line_3(x, y));
    }
    return 0;
}

int read_coordinations(float *x, float *y) {
    printf("Enter point coordinations\n");
    if (scanf("%f %f", x, y) != 2) {
        printf("Incorrect input!\n");
        return 1;
    } else {
        return 0;
    }
}

int line_1(float x, float y) {
    float regarding_to_line_1 = equation(x, 2, 2);
    int flag_1;
    if ((regarding_to_line_1 - EPS < y) && (regarding_to_line_1 + EPS > y)) {
        flag_1 = ON_THE_LINE;
    } else if (regarding_to_line_1 - EPS > y) {
        flag_1 = UNDER_THE_LINE;
    } else {
        flag_1 = ABOVE_THE_LINE;
    }
    return flag_1;
}

int line_2(float x, float y) {
    float regarding_to_line_2 = equation(x, 0.5, -1);
    int flag_2;
    if ((regarding_to_line_2 - EPS < y) && (regarding_to_line_2 + EPS > y)) {
        flag_2 = ON_THE_LINE;
    } else if (regarding_to_line_2 - EPS > y) {
        flag_2 = UNDER_THE_LINE;
    } else {
        flag_2 = ABOVE_THE_LINE;
    }
    return flag_2;
}

int line_3(float x, float y) {
    float regarding_to_line_3 = equation(x, -1, 2);
    int flag_3;
    if ((regarding_to_line_3 - EPS < y) && (regarding_to_line_3 + EPS > y)) {
        flag_3 = ON_THE_LINE;
    } else if (regarding_to_line_3 - EPS > y) {
        flag_3 = UNDER_THE_LINE;
    } else {
        flag_3 = ABOVE_THE_LINE;
    }
    return flag_3;
}

void print_if_not_on_line(int flag_1, int flag_2, int flag_3) {
    printf("Result:\n");
    if (flag_1 * flag_2 * flag_3 != 0) {
        printf("Point is placed in region ");
        if (flag_1 == flag_2 && flag_1 == flag_3 && flag_1 == 1) {
            printf("6.\n");
        } else if (flag_1 == flag_2 && flag_1 == flag_3 && flag_1== -1) {
            printf("3.\n");
        } else if (flag_2 == flag_3 && flag_2 == -1) {
            printf("4.\n");
        } else if (flag_1 == flag_2 && flag_1 == -1) {
            printf("2.\n");
        } else if (flag_1 == flag_3 && flag_1 == -1) {
            printf("7.\n");
        } else if (flag_2 == flag_3 && flag_2 == 1) {
            printf("1.\n");
        } else if (flag_1 == flag_2 && flag_1 == 1) {
            printf("5.\n");
        }
    }
}

void print_if_on_line(int flag_1, int flag_2, int flag_3) {
    if (flag_1 * flag_2 * flag_3 == 0) {
        printf("Point placed on line");
        if (flag_1 == flag_2 && flag_1 == 0) {
            printf("s 1 and 2.\n");
        } else if (flag_1 == flag_3 && flag_1 == 0) {
            printf("s 1 and 3.\n");
        } else if (flag_3 == flag_2 && flag_2 == 0) {
            printf("s 2 and 3.\n");
        } else if (flag_1 == 0) {
            printf(" 1.\n");
        } else if (flag_2 == 0) {
            printf(" 2.\n");
        } else if (flag_3 == 0) {
            printf(" 3.\n");
        }
    }
}

float equation(float x, float k, float b) {
    return k * x + b;
}
