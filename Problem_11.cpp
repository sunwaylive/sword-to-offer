#include <cstdio>
#include <cmath>
using namespace std;

double myPow(double base, int e){
    if(e < 0) return 1.0 / myPow(base, -e);
    if(e == 0) return 1.0;
    double res = myPow(base, e/2) * myPow(base, e/2);
    if(e & 0x1) res *= base;
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; ++i){
        double base;
        int e;
        scanf("%lf %d", &base, &e);
        double res = myPow(base, e);
        if(!isfinite(res)){
            printf("INF\n");
        }else{
            printf("%2.2ef\n", res);
        }
    }
    return 0;
}
