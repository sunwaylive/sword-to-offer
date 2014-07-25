#include <cstdio>

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
        scanf("%d", &data);
        ListNode *t = new ListNode(data);
        p->next = t;
        p = p->next;
    }
    return dummy.next;
}

ListNode* reverse(ListNode *head){
    ListNode *prev = NULL, *cur = head, *nxt = NULL;
    while(cur){
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    return head;
}

int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        ListNode *head = createList(n);
        ListNode *rhead = reverse(head);
        if(!rhead){
            printf("NULL\n");
            continue;
        }else{
            while(rhead->next){
                printf("%d ", rhead->val);
                rhead = rhead->next;
            }
            printf("%d\n", rhead->val);
        }
    }
    return 0;
}
