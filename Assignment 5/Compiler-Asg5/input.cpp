int main() {
    int a;
    a = 0;
    int b;
    b = 0;

    for (a = 0; a < 5; ++a) {
        int b;
        b = 1;
        print(b);
        if (a == 3) {
            break;
        }
    }
    print(b);
}
