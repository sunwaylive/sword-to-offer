#include <iostream>
using namespace std;

int a[100000];
int b[100000];
//O(n^2)
int reverseNum2(int n){
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt = 0;
        for(int j = i+1; j < n; ++j)
            if(a[i] > a[j])
                cnt++;
        sum += cnt;
    }
    return sum;
}

long long merge(int start, int middle, int end){
    long long cnt = 0;

    for(int i = start; i < end; ++i)
        b[i] = a[i];

    int l = middle-1, r = end-1;
    int bidx = end - 1;
    while(l >= start && r >= middle){
        if(b[l] > b[r]){
            cnt += (r - middle + 1);
            a[bidx--] = b[l--];
        }else{
            a[bidx--] = b[r--];
        }
    }
    while(l >= start) { a[bidx--] = b[l--]; }
    while(r >= middle) { a[bidx--] = b[r--]; }
    return cnt;
}

long long mergeSort(int start, int end){
    if(end - 1 > start){
        int middle = (start + end)>>1;
        long long left = mergeSort(start, middle);
        long long right = mergeSort(middle, end);
        long long cur= merge(start, middle, end);
        return left + right + cur;
    }else return 0;
}

int main()
{
    cout<<INT_MAX<<endl;
    int n;
    while(cin>>n){
        for(int i = 0; i < n; ++i)
            cin>>a[i];
        cout<<mergeSort(0, n)<<endl;
    }
    return 0;
}
