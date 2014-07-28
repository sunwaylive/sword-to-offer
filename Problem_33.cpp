#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

bool myCmp(const string &a, const string &b){
    string _a = a;
    string _b = b;
    _a.append(b);
    _b.append(a);
    return _a < _b;
}

int main()
{
    int m;
    while(cin>>m){
        vector<string> vec;
        string numStr;
        for(int i = 0; i < m; ++i){
            cin>>numStr;
            vec.push_back(numStr);
        }
        sort(vec.begin(), vec.end(), myCmp);
        for(int i = 0; i < m; ++i)
            cout<<vec[i];
        cout<<endl;
    }
    return 0;
}
