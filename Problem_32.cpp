#include <iostream>
#include <algorithm>
using namespace std;

long long countOnes(long long n){
    if(n <= 0) return 0;
    long long higher, cur, lower, factor = 1;
    long long cnt = 0;
    while(n / factor){
        lower = n - (n / factor) * factor;
        higher = n / (factor * 10);
        cur = (n / factor) % 10;
        if(cur == 0){
            cnt += higher * factor;
        }else if(cur == 1){
            cnt += higher * factor + lower + 1;
        }else{
            cnt += higher * factor + factor;
        }
        factor *= 10;
    }
    return cnt;
}

int main()
{
    int a, b;
    while(cin>>a>>b){
        if(a < b) swap(a, b);

        cout<<(countOnes(a) - countOnes(b-1))<<endl;
    }
    return 0;
}
