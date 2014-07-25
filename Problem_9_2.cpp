#include <stdio.h>

long long fib(int n){
    if(n == 1 || n == 2) return 1;
    long long p1 = 1, p2 = 1;
    for(int i = 3; i <= n; ++i){
        long long tmp = p1 + p2;
        p1 = p2;
        p2 = tmp;
    }
    return p2;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        printf("%lld\n", fib(n+1));
    }
    return 0;
}
