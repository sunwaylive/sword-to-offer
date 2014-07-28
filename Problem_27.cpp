#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
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

void convert(TreeNode* root, TreeNode *&last){
    if(!root) return;

    TreeNode *p = root;
    convert(p->left, last);
    //left, last means the one right before the node
    p->left = last;
    if(last != NULL)
        last->right = p;
    //right
    last = p;
    convert(p->right, last);
}

int main()
{
    int n;
    cin>>n;
    while(n--){
        TreeNode *root = createTree();
        TreeNode *last = NULL;
        convert(root, last);
        //now last point to the root
        if(!last) continue;
        while(last->left)
            last = last->left;
        while(last){
            cout<<last->val<<" ";
            last = last->right;
        }
        cout<<endl;
    }
    return 0;
}
