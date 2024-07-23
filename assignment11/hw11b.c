// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here

    if (n == 1) return 1; 
    if (n == 2) return 3;
    // A 2x2 rectangle can be filled in 3 ways by two 1 x 2 or two 2 x 1 tiles or a 2 x 2 tiles
    d[0] = 1;
    d[1] = 1;
    d[2] = 3;

    for (int i = 3; i <= n; ++i) {
        d[i] = d[i-1] + 2 * d[i-2];
    }

    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
