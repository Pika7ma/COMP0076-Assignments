#include <stdio.h>
#define NUM 1000000
int main() {
    int a[NUM];
    int b[NUM];
    int c[NUM];
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        a[i] = i;
        b[i] = i;
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // printf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    #pragma omp parallel for
    for (int i = 0; i < NUM; ++i) {
        c[i] = a[i] + b[i];
        // prinf("%d\n", c[i]);
    }
    return 0;
}
