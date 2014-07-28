#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next, *spe;
    ListNode(int x) : val(x), next(NULL), spe(NULL){}
};

ListNode* Nodes[1002];

ListNode* createList(int n){
    ListNode dummy(-1);
    ListNode *p = &dummy;
    //get the normal list
    int data;
    for(int i = 0; i < n; ++i){
        cin>>data;
        ListNode *t = new ListNode(data);
        p->next = t;
        p = p->next;
        Nodes[i] = t;
    }
    //link the special pointer
    for(int i = 0; i < n; ++i){
        int spe;
        cin>>spe;
        if(spe - 1 < 0)
            Nodes[i]->spe = NULL;
        else
            Nodes[i]->spe = Nodes[spe-1];
    }
    return dummy.next;
}

ListNode* cpList(ListNode *head){
    if(!head) return NULL;

    ListNode *p = head;
    map<ListNode*, ListNode*> cache;
    while(p){
        ListNode *t = new ListNode(p->val);
        cache.insert(pair<ListNode*, ListNode*>(p, t));
        p = p->next;
    }

    p = head;
    while(p){
        cache[p]->next = cache[p->next];
        if(!p->spe)
            cache[p]->spe = NULL;
        else
            cache[p]->spe = cache[p->spe];
        p = p->next;
    }
    return cache[head];
}


int main()
{
    //ifstream in;
    //in.open("input.txt");
    //cin.rdbuf(in.rdbuf());
    int n;
    while(cin>>n){
        ListNode *head = createList(n);
        ListNode *chead = cpList(head);
        ListNode *p = chead;
        for(; p; p = p->next){
            int speval = p->spe ? p->spe->val : 0;
            cout<<p->val <<" " <<speval<<endl;
        }
    }

    //in.close();
    return 0;
}
