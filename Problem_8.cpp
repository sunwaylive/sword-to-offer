#include <stdio.h>

int a[1000000];

int main(){
    int n, ret;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &a[0]);
        --n;
        ret = a[0];
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            if(a[i] < ret) ret = a[i];
        }
        printf("%d\n", ret);
    }
    return 0;
}
