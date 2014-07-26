#include <cstdio>

int a[1000000];
int b[1000000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int idx = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] & 1) b[idx++] = a[i];
        }
        for(int i = 0; i < n; ++i){
            if(!(a[i] & 1)) b[idx++] = a[i];
        }
        for(int i = 0; i < n-1; ++i)
            printf("%d ", b[i]);
        printf("%d", b[n-1]);
    }
    return 0;
}
