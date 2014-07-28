#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* Nodes[16];

TreeNode* createTree(int n){
    for(int i = 1; i <= n; ++i)
        Nodes[i] = new TreeNode(-1);
    int l, r;
    for(int i = 1; i <= n; ++i){
        cin>>l>>r;
        Nodes[i]->left = (l == -1) ? NULL : Nodes[l];
        Nodes[i]->right = (r == -1) ? NULL : Nodes[r];
    }
    return Nodes[1];
}

void deleteTree(TreeNode *root){
    if(!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int depth(TreeNode *root){
    if(!root) return 0; //don't use ifroot->left != NULL && root->right != NULL then return 1;
    return max(depth(root->left), depth(root->right)) + 1;
}

int main()
{
    int n;
    while(cin>>n){
        TreeNode *root = createTree(n);
        cout<<depth(root)<<endl;
        deleteTree(root);
    }
    return 0;
}
