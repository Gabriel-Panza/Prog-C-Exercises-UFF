#include <stdio.h>
void tickets(int n, int m) {
    int v[10001] = {0};
    int x;

    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        v[x]++;
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i] > 1) {
            count++;
        }
    }

    printf("%d\n", count);
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) && (n != 0 || m != 0)) {
        tickets(n,m);
    }
    return 0;
}