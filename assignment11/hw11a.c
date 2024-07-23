// name: Jonathan Mowat
// email: mowat.j@northeastern.edu

#include <stdio.h>

int d[20];

long long int dp(int n) {

    // Add your code here
    if (n == 0) return 1; // A 2x0 rectangle can be filled in only one way?
    if (n == 1) return 1; // A 2x1 rectangle can be filled by one 2 x 1 tiles
    if (d[n] != 0) return d[n];
    // recurisive approach
    //return d[n] = dp(n-1) + dp(n-2);
    
    // iterative approach
    // Base case:
    d[0] = 1; 
    d[1] = 1; 

    // start i after the num of base cases
    for (int i = 2; i <= n; i++) {
        d[i] = 2 * d[i - 1] + d[i - 2];
    }

    return d[n];
    

}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));


}
