#include <cstdio>
#include <vector>
using namespace std;

int matrix[1002][1002];

vector<int> spiralMatrix(int m, int n){
    vector<int> res;
    int beginx = 0, endx = n - 1;
    int beginy = 0, endy = m - 1;
    while(true){
        //from left to right
        for(int j = beginx; j <= endx; ++j) res.push_back(matrix[beginy][j]);
        if(++beginy > endy) break;
        //from top to bottom
        for(int i = beginy; i <= endy; ++i) res.push_back(matrix[i][endx]);
        if(beginx > --endx) break;
        //from right to left
        for(int j = endx; j >= beginx; --j) res.push_back(matrix[endy][j]);
        if(beginy > --endy) break;
        //from bottom to top
        for(int i = endy; i >= beginy; --i) res.push_back(matrix[i][beginx]);
        if(++beginx > endx) break;
    }
    return res;
}

int main()
{
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        vector<int> res;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                scanf("%d", &matrix[i][j]);
        res = spiralMatrix(m, n);

        int i;
        for(i = 0; i < res.size(); ++i)
            printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}
