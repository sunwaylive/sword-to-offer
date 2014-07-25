#include <stdio.h>

long long f[64];

long long fib(int n){
    f[1] = 1;
    f[2] = 2;
    for(int i = 3; i <= n; ++i){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%lld\n", fib(n));
    }
    return 0;
}
