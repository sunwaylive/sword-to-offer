#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        unsigned long long ret = (unsigned long long)1<<(n-1);
        printf("%llu\n", ret);
    }
    return 0;
}
