#include <stdio.h>
int fact(int i) {
    if (i == 1) {
        return 1;
    }
    return i * fact(i - 1);
}
int main() {
    int n, f;
    scanf("%d", &n);
    f = fact(n);
    printf("%d\n", f);
}
