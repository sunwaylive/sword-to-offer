#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
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

TreeNode* buildMirror(TreeNode *root){
    TreeNode *mirror;
    if(!root) {
        mirror = NULL;
    }else{
        mirror = new TreeNode(root->val);
        mirror->left = buildMirror(root->right);
        mirror->right = buildMirror(root->left);
    }
    return mirror;
}

void preOrder(TreeNode *root){
    if(root){
        res.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        TreeNode *root = createTree(n);
        TreeNode *mirror_root = buildMirror(root);

        if(mirror_root){
            preOrder(mirror_root);
            int i;
            for(i = 0; i < res.size()-1; ++i)
                cout<<res[i]<<" ";
            cout<<res[i]<<endl;
        }
        else
            cout<<"NULL"<<endl;
    }
    return 0;
}
