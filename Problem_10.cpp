#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for(int i = 1; i <= t; ++i){
        int cnt = 0;
        int n;
        scanf("%d", &n);
        unsigned int t = (unsigned int) n;
        while(t != 0x0){
            if(t & 0x1) ++cnt;
            t = t>>1;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
