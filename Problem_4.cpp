#include <iostream>
#include <string>
using namespace std;

int main()
{
    string src;
    while(getline(cin, src)){
        int src_len = src.size();
        int dst_len = 0;
        for(int i = 0; i < src_len; ++i){
            if(src[i] == ' ') dst_len += 3;
            else dst_len += 1;
        }
        //now dst_len store the result length
        string dst(dst_len, ' ');
        int dst_idx = dst_len - 1;
        for(int i = src_len - 1; i >= 0; --i){
            if(src[i] != ' ') dst[dst_idx--] = src[i];
            else{
		dst[dst_idx--] = '0';
		dst[dst_idx--] = '2';
		dst[dst_idx--] = '%';
            }
        }//end for
        cout<<dst<<endl;
    }//end while
    return 0;
}
