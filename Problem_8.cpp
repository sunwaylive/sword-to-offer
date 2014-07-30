#include <stdio.h>
#include <iostream>
using namespace std;

int a[1000002];

//O(n) solution
// int main(){
//     int n, ret;
//     while(scanf("%d", &n) != EOF){
//         scanf("%d", &a[0]);
//         --n;
//         ret = a[0];
//         for(int i = 1; i <= n; ++i){
//             scanf("%d", &a[i]);
//             if(a[i] < ret) ret = a[i];
//         }
//         printf("%d\n", ret);
//     }
//     return 0;
// }

//O(nlogn) solution
void findMin(int start, int end)
{
    //already in order
    if(a[start] < a[end-1]){ //no equal case
        cout<<a[start]<<endl;
        return ;
    }

    int minIdx = 0;
    while(start < end){
        if(start + 2 == end){
            minIdx = end-1;
            break;
        }

        int mid = start + (end - start) / 2;
        //start mid end, all of them are equal
        if(a[mid] == a[start] && a[mid] == a[end-1]){
            minIdx = start;
            //find the minimum;
            for(int i = start+1; i < end; ++i){
                if(a[i] < a[start]){
                    minIdx = i;
                    //cout<<"minIdx: " <<minIdx <<endl;
                }
            }
            break;
        }

        if(a[mid] >= a[start]){
            start = mid;
            //cout<<"start: " <<start<<endl;
        }else if(a[mid] <= a[end-1]){
            end = mid+1;
            //cout<<"end: " <<end<<endl;
        }
    }
    cout<<a[minIdx] <<endl;
    return;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; ++i)
            scanf("%d", &a[i]);
        findMin(0, n);
    }
    return 0;
}
