#include <iostream>
using namespace std;

int pre[1000];
int in[1000];
int n;

struct TreeNode{
    int val;
    TreeNode *lchild, *rchild;
    TreeNode(int x) : val(x), lchild(NULL), rchild(NULL){}
};

int findRootPos(int val, int in[]){
    for(int i = 0; i < n; ++i)
        if(in[i] == val) return i;
    return -1;
}

TreeNode* build(int pre[], int in[], int ps, int pe, int is, int ie, bool &can){
    if(ps >= pe || is >= ie || !can) return NULL;
    TreeNode *root = new TreeNode(pre[ps]);

    int pos = findRootPos(pre[ps], in);
    if(pos == -1) { can = false; return NULL; }

    root->lchild = build(pre, in, ps+1, pos-is+ps+1, is, pos, can);
    root->rchild = build(pre, in, pe-ie+pos+1, pe, pos+1, ie, can);
    return root;
}

void postOrder(TreeNode *root){
    if(root){
        postOrder(root->lchild);
        postOrder(root->rchild);
        cout<<root->val<<" ";
    }
}

void printfArray(int a[], int n){
    for(int i = 0; i < n; ++i)
        cout<<a[i]<< " ";
    cout<<endl;
}

int main()
{
    while(cin>>n){
        for(int i = 0; i < n; ++i)
            cin>>pre[i];
        for(int i = 0; i < n; ++i)
            cin>>in[i];

        bool can = true;
        TreeNode *root = build(pre, in, 0, n, 0, n, can);
        if(can){
            postOrder(root);
            cout<<endl;
        }else
            cout<<"No"<<endl;
    }
    return 0;
}
