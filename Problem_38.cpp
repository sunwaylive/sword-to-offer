#include <cstdio>
#include <map>
using namespace std;

int a[1000000];

//binary search
int bs(int start, int end, int target, bool searchLeft){
    while(start < end){
        int middle = (start + end)>>1;
        if(a[middle] == target){
            if(searchLeft) { end = middle; }
            else start = middle+1;
        }else if(target < a[middle]){
            end = middle;
        }else if(target > a[middle]){
            start = middle + 1;
        }
    }
    return start;//end is the same
}

int main()
{
    int n, m;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        scanf("%d", &m);
        int query;
        for(int i = 0; i < m; ++i){
            scanf("%d", &query);
            int res = bs(0, n, query, false) - bs(0, n, query, true);
            printf("%d\n", res);
        }
    }
    return 0;
}
