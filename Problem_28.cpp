#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string next_permu(string s){
    const int len = s.length();
    int i, pivot, first_larger;
    //1.find pivot that violates the increasing order from right to left
    for(i = len-2; i >= 0; --i){
        if(s[i] < s[i+1])
            break;
    }
    pivot = i;
    //2.already in descending order
    if(pivot < 0){
        reverse(s.begin(), s.end());
        return s;
    }

    //3.find first larger
    for(i = len-1; i >= 0; --i){
        if(s[i] > s[pivot])
            break;
    }
    first_larger = i;
    swap(s[i], s[pivot]);
    reverse(s.begin() + pivot + 1, s.end());
    return s;
}



int main()
{
    string s, tmp;
    while(cin>>s){
        sort(s.begin(), s.end());
        string tmp = s;
        do{
            cout<<tmp<<endl;
            tmp = next_permu(tmp);
        }while(s != tmp);
    }
    return 0;
}
