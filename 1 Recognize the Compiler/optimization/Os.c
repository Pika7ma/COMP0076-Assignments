#include <stdio.h>
#define N 20
#define TIMES 10000000
int main() {
    int time = 0;
    while (time < TIMES) {
        int a[N];
        int i;
        i = 0;
        while (i < N) {
            a[i] = 0;
            i += 1;
        }
        a[0] = 1;
        a[1] = 1;
        i = 2;
        while (i < N) {
            a[i] = a[i - 1] + a[i - 2];
            i += 1;
        }
        time += 1;
    }
    return 0;
}
