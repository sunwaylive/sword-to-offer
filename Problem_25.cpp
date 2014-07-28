#include <iostream>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int idx;
    int val;
    int left, right;
    TreeNode() {}
    TreeNode(int x) : idx(-1), val(x), left(-1), right(-1){}
};

TreeNode* Nodes[10002];

void dfs(TreeNode *root, int leftsum, vector<int> &path, vector<vector<int> > &paths){
    if(!root) return;

    leftsum -= root->val;
    path.push_back(root->idx);
    if(root->left == -1 && root->right == -1 && leftsum == 0)
        paths.push_back(path);
    dfs(Nodes[root->left], leftsum, path, paths);
    dfs(Nodes[root->right], leftsum, path, paths);
    path.pop_back();
    leftsum += root->val;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    int n, k;
    while(cin>>n>>k){
        //build tree, be careful the idx starts from
        for(int i = 1; i <= n; ++i){
            Nodes[i] = new TreeNode();
            Nodes[i]->idx = i;
            cin>>Nodes[i]->val>>Nodes[i]->left>>Nodes[i]->right;
        }

        vector<vector<int> > paths;
        vector<int> path;
        dfs(Nodes[1], k, path, paths);
        sort(paths.begin(), paths.end());
        cout<<"result:"<<endl;
        for(int i = 0; i < paths.size(); ++i){
            cout<<"A path is found: ";
            int j;
            for(j = 0; j < paths[i].size() - 1; ++j)
                cout<<paths[i][j] <<" ";
            cout<<paths[i][j]<<endl;
        }
    }
    in.close();
    return 0;
}
