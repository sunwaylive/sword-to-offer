#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[1000000];

//O(nlogn)
bool bs(int start, int end, int target){
    while(start < end){
        int middle = (start + end)>>1;
        if(target == a[middle]){
            return true;
        }else if(target < a[middle]){
            end = middle;
        }else if(target > a[middle]){
            start = middle+1;
        }
    }
    return false;
}

void search(int n, int sum){
    unsigned long long product = 0xffffffffffffffff;
    int m1 = -1, m2 = -1;
    for(int i = 0; i < n; ++i){
        //printf("a[i]: %d\nsum-a[i]: %d\n", a[i], sum-a[i]);
        if(bs(i+1, n, sum - a[i])){
            //printf("product: %llu\n", product);
            if(a[i] * (sum - a[i]) < product){
                m1 = a[i];
                m2 = sum - a[i];
                product = m1 * m2;
            }
        }
    }
    //if(m1 > m2) swap(m1, m2);
    printf("%d %d\n", m1, m2);
}

//O(n)
void search2(int n, int k){
    int low = 0, high = n-1;
    while(low < high){
        int sum = a[low] + a[high];
        if(sum == k){
            break;
        }else if(sum < k){
            low++;
        }else{
            high--;
        }
    }
    if(low < high) printf("%d %d\n", a[low], a[high]);
    else printf("-1 -1\n");
}

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);

        search2(n, k);
    }
    return 0;
}
