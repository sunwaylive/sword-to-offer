#include <iostream>
#include <map>

using namespace std;

int a[100002];

int main()
{
    int n;
    while(cin>>n){
        map<int, int> cache;
        for(int i = 0; i < n; ++i){
            cin>>a[i];
            cache[a[i]]++;
        }

        int i;
        for(i = 0; i < n; ++i){
            if(cache[a[i]] > n / 2){
                cout<<a[i]<<endl;
                break;
            }
        }
        if(i == n) cout<<-1<<endl;
    }
    return 0;
}
