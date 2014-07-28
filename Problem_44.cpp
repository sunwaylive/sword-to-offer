#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[14];
    int n;
    while(cin>>n){
        if(n == 0) break;

        for(int i = 0; i < n; ++i)
            cin>>a[i];

        sort(a, a+n);
        int zeroNum = 0, gapNum = 0;
        bool can = true;
        for(int i = 0; i < n-1; ++i){
            if(a[i] == 0){
                zeroNum++;
                continue;
            }else{
                if(a[i+1] == a[i]){//if non-zero duplicates appears, it can't be a sequence
                    can = false;
                    break;
                }
                gapNum += (a[i+1] - a[i] - 1);
            }
        }

        if(can && zeroNum >= gapNum)
            cout<<"So Lucky!"<<endl;
        else
            cout<<"Oh My God!"<<endl;
    }
    return 0;
}
