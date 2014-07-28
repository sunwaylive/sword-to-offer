#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int firstOnceLetter(string s){
    map<char, int> cache;
    const int len = s.length();
    for(int i = 0; i < len; ++i)
        cache[s[i]]++;

    for(int i = 0; i < len; ++i)
        if(cache[s[i]] == 1)
            return i;
    return -1;
}

int main()
{
    string str;
    while(cin>>str){
        cout<<firstOnceLetter(str)<<endl;
    }
    return 0;
}
