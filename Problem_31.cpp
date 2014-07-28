#include <cstdio>
using namespace std;

int a[100002];
int maxs, maxe;

int lss(int n){
    int start = 0, end = 0;
    int maxsum = a[0];

    for(int i = 1; i < n; ++i){
        //decide current maxsum
        if(a[i-1] >= 0){
            a[i] += a[i-1];
            end++;
        }else{
            start = i;
            end = i;
        }
        //update max start and max end
        if(a[i] > maxsum){
            maxsum = a[i];
            maxs = start;
            maxe = end;
        }
    }
    return maxsum;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0) return 0;
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        printf("%d %d %d \n", lss(n), maxs, maxe);
    }
    return 0;
}
