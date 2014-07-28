#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createList(int n){
    ListNode dummy(-1);
    ListNode *p = &dummy;
    int data;
    for(int i = 0; i < n; ++i){
        cin>>data;
        ListNode *t = new ListNode(data);
        p->next = t;
        p = p->next;
    }
    return dummy.next;
}

void getFirstCommon(ListNode *head1, ListNode *head2){
    if(!head1 || !head2) return;

    ListNode *hshort = head1, *hlong = head2;
    int lenlong = 0, lenshort = 0;
    for(; hshort; lenshort++, hshort = hshort->next);
    for(; hlong; lenlong++, hlong = hlong->next);

    //reset
    hshort = head1;
    hlong = head2;
    //switch if needed
    if(lenshort > lenlong) {
        hshort = head2;
        hlong = head1;
        swap(lenshort, lenlong);
    }
    //move long first for (lenlong - lenshort) steps
    int gap = lenlong - lenshort;
    while(hlong && gap--){
        hlong = hlong->next;
    }

    while(hlong && hshort){
        if(hlong->val == hshort->val){
            cout<<hlong->val<<endl;
            return;
        }
        hlong = hlong->next;
        hshort = hshort->next;
    }
    cout<<"My God"<<endl;
}

int main()
{
    int m, n;
    while(cin>>m>>n){
        ListNode *h1 = createList(m);
        ListNode *h2 = createList(n);
        getFirstCommon(h1, h2);
    }
    return 0;
}
