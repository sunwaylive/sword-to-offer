#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    char str[1000];
    //oj上测试数据不严谨
    while(scanf("%s", str) != EOF){
        if(str == NULL) printf("My God\n");

        char *p = str;
        int sign = 1;
        //skip spaces
        while(*p == ' ') p++;

        //set the sign
        if(*p == '-'){
            sign = -1;
            p++;
        }else if(*p == '+'){
            p++;
        }

        //decode the num
        int num = 0;
        while(*p){
            if(*p > '9' || *p < '0')
                break;

            num = num * 10 + (*p - '0');
            p++;
        }

        if(*p == '\0')
            printf("%d\n", num * sign);
        else
            printf("My God\n");
    }
    return 0;
}
