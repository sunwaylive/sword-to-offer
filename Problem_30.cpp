#include <iostream>
#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF){
        priority_queue<int, vector<int>, greater<int> > que;
        int data;
        for(int i = 0; i < n; ++i){
            scanf("%d", &data);
            que.push(data);
        }

        for(int i = 0; i < k-1; ++i){
            printf("%d ", que.top());
            que.pop();
        }
        printf("%d\n", que.top());
    }
    return 0;
}
