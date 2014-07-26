#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int pushseq[100000];
int popseq[100000];

bool check(int n){
    stack<int> stk;
    int popidx = 0, pushidx = 0;
    while(popidx < n && pushidx < n){
        //if equal before push, we should pop
        while(!stk.empty() && stk.top() == popseq[popidx]){
                stk.pop();
                popidx++;
        }

        stk.push(pushseq[pushidx]);
        pushidx++;
    }
    //elements left in the stack
    while(!stk.empty()){
        if(stk.top() == popseq[popidx]){
            stk.pop();
            popidx++;
        }else
            return false;
    }

    if(popidx == n && pushidx == n) return true;
    else return false;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &pushseq[i]);
        for(int i = 0; i < n; ++i)
            scanf("%d", &popseq[i]);
        //simulate
        if(check(n)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}
