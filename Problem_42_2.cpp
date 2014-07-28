#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    char str[1004];
    char rot[1004];
    int k;
    while(scanf("%s %d", str, &k) != EOF){
        int len = strlen(str);
        for(int i = 0; i < len; ++i){
            int pos = (i-k) % len;
            if(pos < 0) pos += len;
            rot[pos] = str[i];
        }
        rot[len] = '\0';
        printf("%s\n", rot);
    }
    return 0;
}
