#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createCircleList(int n){
    ListNode dummy(-1);
    ListNode *p = &dummy;
    for(int i = 1; i <= n; ++i){
        ListNode *t = new ListNode(i);
        p->next = t;
        p = p->next;
    }
    p->next = dummy.next;//make a circle
    return dummy.next;
}

//O(m*n) solution
void josephus(int n, int m){
    ListNode *head = createCircleList(n);
    if(!head) return;

    ListNode *p = head;
    int i = 1;
    while(p->next != p){
        p = p->next;
        i++;
        if(i == m){
            swap(p->val, p->next->val);
            ListNode *tmp = p->next;
            p->next = p->next->next;
            //cout<<"kill val: "<<tmp->val<<endl;
            delete tmp;
            i = 1;
        }
    }
    cout<<p->val<<endl;
}

//O(n) solution, formula: f[i] = (f[i-1] + m ) % n; f[1] = 0;
int calJosephus(int n, int m){
    int f[1000000];
    f[1] = 0;
    for(int i = 2; i <= n; ++i){
        f[i] = (f[i-1] + m) % i;
    }
    return f[n];
}

int main()
{
    int n, m;
    while(cin>>n>>m){
        if(n == 0) break;

        //josephus(n, m);
        cout<<calJosephus(n, m)+1<<endl;
    }
    return 0;
}
