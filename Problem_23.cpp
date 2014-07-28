#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

vector<int> res;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* createTree(int n){
    //store all the nodes
    TreeNode* Nodes[1002];
    Nodes[0] = NULL;
    for(int i = 1; i <= n; ++i){
        int data;
        cin>>data;
        Nodes[i] = new TreeNode(data);
    }
    //link the nodes
    char op;
    int l, r;
    for(int i = 1; i <= n; ++i){
        cin>>op;
        if(op == 'd') {
            cin>>l>>r;
            Nodes[i]->left = Nodes[l];
            Nodes[i]->right = Nodes[r];
        }else if(op == 'l'){
            cin>>l;
            Nodes[i]->left = Nodes[l];
        }else if(op == 'r'){
            cin>>r;
            Nodes[i]->right = Nodes[r];
        }else if(op == 'z'){
            continue;
        }
    }

    return Nodes[1];
}

vector<int> bfs(TreeNode *root){
    vector<int> ret;
    if(!root) return ret;

    queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode *t = que.front(); que.pop();
        ret.push_back(t->val);

        if(t->left) que.push(t->left);
        if(t->right) que.push(t->right);
    }
    return ret;
}

int main()
{
    //ifstream in;
    //in.open("input.txt");
    //cin.rdbuf(in.rdbuf());

    int n;
    while(cin>>n){
        vector<int> ret;
        TreeNode *root = createTree(n);
        ret = bfs(root);

        int i;
        for(i = 0; i < ret.size() - 1; ++i)
            cout<<ret[i]<<" ";
        cout<<ret[i]<<endl;
    }

    //in.close();
    return 0;
}
