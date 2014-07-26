#include <cstdio>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createList(int n){
    ListNode dummy(-1);
    ListNode* p = &dummy;
    int data;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &data);
        ListNode *t = new ListNode(data);
        p->next = t;
        p = p->next;
    }
    return dummy.next;
}

ListNode* merge(ListNode *h1, ListNode *h2){
    ListNode dummy(-1);
    ListNode *p = &dummy;
    while(h1 && h2){
        if(h1->val < h2->val){
            p->next = h1; p = p->next;
            h1 = h1->next;
        }else{
            p->next = h2; p = p->next;
            h2 = h2->next;
        }
    }
    p->next = h1 ? h1 : h2;
    return dummy.next;
}

void printList(ListNode *head){
    for(; head && head->next; head = head->next)
        printf("%d ", head->val);
    printf("%d\n", head->val);
}

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        ListNode *h1 = createList(n);
        ListNode *h2 = createList(m);
        ListNode *m = merge(h1, h2);
        if(m == NULL) printf("NULL\n");
        else printList(m);
    }
    return 0;
}
