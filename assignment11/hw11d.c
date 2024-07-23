// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 5;
    
    d[0] = 1;
    d[1] = 1;
    d[2] = 5;
    
    for (int i = 3; i <= n; i++) {
        d[i] = 3 * d[i - 2] + 2 * d[i - 1];
        for (int j = i - 3; j >= 0; j--) {
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
