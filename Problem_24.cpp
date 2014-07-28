#include <iostream>
using namespace std;

int a[10002];

int findSplit(int start, int end, int target){
    int i;
    //find the split position
    for(i = start; i < end && a[i] < target; ++i) ;

    return i;
}

//左闭右开区间
bool check(int start, int end){
    if(start >= end) return true;

    int root = a[end - 1];
    int pos = findSplit(start, end - 1, root);
    //check whether right sub-tree is qualified
    int i;
    for(i = pos; i < end - 1 && a[i] > root; ++i) ;
    if(i != end - 1)
        return false;
    //iterative
    return check(start, pos) && check(pos, end - 1);
}

int main()
{
    int n;
    while(cin>>n){
        for(int i = 0; i < n; ++i)
            cin>>a[i];

        if(check(0, n))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
