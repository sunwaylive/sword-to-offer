#include <iostream>
using namespace std;

int num[1500];

int uglyNum(int n){
    num[1] = 1;
    int start2 = 1, start3 = 1, start5 = 1;
    for(int i = 2; i <= n; ++i){
        int first;
        //* 2
        int j;
        for(j = start2; j < i; ++j){
            if(num[j] * 2 > num[i-1])
                break;
        }
        if(j < i) { first = num[j] * 2; start2 = j;}

        //* 3
        for(j = start3; j < i; ++j){
            if(num[j] * 3 > num[i-1])
                break;
        }
        if(j < i) { first = min(first, num[j] * 3); start3 = j;}

        //* 5
        for(j = start5; j < i; ++j){
            if(num[j] * 5 > num[i-1])
                break;
        }
        if(j < i) { first = min(first, num[j] * 5); start5 = j;}
        num[i] = first;
    }
    return num[n];
}

int main()
{
    int n;
    while(cin>>n){
        cout<<uglyNum(n)<<endl;
    }
    return 0;
}
