#include <stdio.h>
#include <vector>
using namespace std;

//左闭右开区间查找
bool findValue(const vector<vector<int> > &matrix, const int val){
    if(matrix.empty() || matrix[0].empty()) return false;

    const int m = matrix.size();
    const int n = matrix[0].size();
    int start = 0, end = m * n;
    while(start < end){
	int mid = start + (end - start) / 2;
	if(matrix[mid / n][mid % n] == val) return true;
	else if(matrix[mid / n][mid % n] > val){
            end = mid;
        }else{
            start = mid + 1;
        }
    }
    return false;
}

int main()
{
    int m, n, val;
    //多测试案例输入
    while(scanf("%d %d %d\n", &m, &n, &val) != EOF){
        vector<vector<int> > matrix;
        for(int i = 0; i < m; ++i){
            vector<int> row;
            for(int j = 0; j < n; ++j){
                int tmp;
                scanf("%d", &tmp);
                row.push_back(tmp);
            }
            matrix.push_back(row);
        }
        if(findValue(matrix, val)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
