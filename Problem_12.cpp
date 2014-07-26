#include <cmath>
#include <cstdio>

int main()
{
    int n, max;
    scanf("%d", &n);
    max = pow(10, n) - 1;
    for(int i = 1; i <= max; ++i)
        printf("%d\n", i);
    return 0;
}
