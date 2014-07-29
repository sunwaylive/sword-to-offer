#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(){
    TreeNode *T;
    int data;
    cin>>data;
    if(data == 0){
        T = NULL;
    }else{
        T = new TreeNode(data);
        T->left = createTree();
        T->right = createTree();
    }
    return T;
}

bool isFather(TreeNode *root, int target){
    if(!root) return false;
    if(root->val == target) return true;
    else return isFather(root->left, target) || isFather(root->right, target);
}

void firstAncestor(TreeNode* root, int first, int second, TreeNode *&ans){
    if(!root) return;
    if(isFather(root, first) && isFather(root, second)){
        ans = root;
        firstAncestor(root->left, first, second, ans);
        firstAncestor(root->right, first, second, ans);
    }
}

void preorder(TreeNode *root){
    if(root){
        cout<<root->val<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    //ifstream in;
    //in.open("input.txt");
    //cin.rdbuf(in.rdbuf());

    int n;
    cin>>n;
    while(n--){
        TreeNode *root = createTree();
        //preorder(root);
        int first, second;
        cin>>first>>second;
        //core part
        TreeNode *ans = NULL;
        firstAncestor(root, first, second, ans);
        if(!ans) printf("My God\n");
        else printf("%d\n", ans->val);
    }

    //in.close();
    return 0;
}
