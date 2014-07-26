#include <cstdio>
#include <iostream>
#include <fstream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* createTree(int n){
    //get all the nodes array
    TreeNode *Node[1002];
    Node[0] = Node[1] = NULL;
    for(int i = 1; i <= n; ++i){
        int data;
        cin>>data;
        Node[i] = new TreeNode(data);
        Node[i]->left = Node[i]->right = NULL;
    }
    //link the node
    int k, m;
    for(int i = 1; i <= n; ++i){
        cin>>k;
        while(k--){
            cin>>m;
            if(!Node[i]->left) Node[i]->left = Node[m];
            else Node[i]->right = Node[m];
        }
    }
    return Node[1];
}

void preOrder(TreeNode *root){
    if(root){
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

bool isSameTree(TreeNode *A, TreeNode *B){
    if(!B) return true;
    if(!A) return false;
    if(A->val != B->val) return false;
    else return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
}

bool isSubTree(TreeNode *A, TreeNode *B){
    if(!A || !B) return false;
    if(A->val == B->val)
        if (isSameTree(A, B)) return true;
    //if above fails, we should continue;
    return isSameTree(A->left, B) || isSameTree(A->right, B);
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        TreeNode *A = createTree(n);
        TreeNode *B = createTree(m);
        if(isSubTree(A, B)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    in.close();
    return 0;
}
