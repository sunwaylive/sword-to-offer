#include <cstdio>

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        int sum, carry;
        do{
            sum = m ^ n; // with no carry
            carry = (m & n) << 1;
            m = sum;
            n = carry;
        }while(n);
        printf("%d\n", sum);
    }
    return 0;
}
