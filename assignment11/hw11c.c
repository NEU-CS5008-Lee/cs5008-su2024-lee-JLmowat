// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    // 3 x N rectangular floor using 1 x 2 and 2 x 1 tiles.
    if (n == 0) return 1;
    if (n == 1) return 0; // A 3x1 rectangular can not be filled
    if (n == 2) return 3; // A 3x2 rectangle can be filled 3 ways
    
    d[0] = 1;
    d[1] = 0;
    d[2] = 3;

    for (int i = 3; i <= n; i++) {
        d[i] = 3 * d[i - 2];
        for (int j = i - 4; j >= 0; j-=2) {
            d[i] += 2 * d[j];
        }
    }
    
    return d[n];
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));
}
