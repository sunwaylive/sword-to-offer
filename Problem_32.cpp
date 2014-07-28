#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

int charNumOfOne(const char *str){
    int numFirstDigit = 0, numOtherDigit = 0, numRecursive = 0;
    const int len = strlen(str);
    int firstDigit = str[0] - '0';
    if(len == 1 && firstDigit == 0)
        return 0;
    if(len == 1 && firstDigit > 0)
        return 1;
    //首位为1的个数
    if(firstDigit == 1)
        numFirstDigit = atoi(str+1) + 1;
    else
        numFirstDigit = pow(10, len-1);
    //other 1s
    numOtherDigit = firstDigit * (len - 1) * pow(10, len - 2);
    //recursive 1s
    numRecursive = charNumOfOne(str + 1);
    return numFirstDigit + numOtherDigit + numRecursive;
}

int numOfOne(int n){
    char str[50];
    sprintf(str, "%d", n);
    return charNumOfOne(str);
}

int main()
{
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        if(a < b) swap(a, b); // a now stores bigger one
        if(b <= 0)
            printf("%d\n", numOfOne(a));
        else
            printf("%d\n", numOfOne(a) - numOfOne(b-1));
    }
    return 0;
}



// int sum_one(int num)
// {
//     int sum = 0, h, L, c, k = 1;
//     while(num/k)
//     {
//         h = num / (k*10);
//         L = num % k;
//         c = num / k % 10;
//         switch(c)
//         {
//         case 0:
//             sum += h * k;
//             break;
//         case 1:
//             sum += h*k + L + 1;
//             break;
//         default:
//             sum += (h+1) * k;
//         }
//         k = k * 10;
//     }
//     return sum;
// }
