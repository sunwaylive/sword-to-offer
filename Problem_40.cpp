#include <cstdio>
#include <algorithm>
using namespace std;

int a[1000000];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        int left = 0;
        for(int i = 0; i < n; ++i)
            left ^= a[i];
        int split = 1;
        while(!(split & left)) split <<= 1;
        //now split can be a pivot, use pivot to separate the array
        int left1 = 0, left2 = 0;
        for(int i = 0; i < n; ++i){
            if(split & a[i]) left1 ^= a[i];
            else left2 ^= a[i];
        }

        if(left1 > left2) swap(left1, left2);
        printf("%d %d\n", left1, left2);
    }
    return 0;
}
