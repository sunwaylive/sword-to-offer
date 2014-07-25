#include <stdio.h>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createList()
{
    ListNode dummy(-1);
    ListNode *p = &dummy;
    int data;
    while(scanf("%d\n", &data)){
	if(data == -1) break;
	else{
            ListNode *t = new ListNode(data);
            p->next = t;
            p = p->next;
        }
    }
    return dummy.next;
}

ListNode* reverse(ListNode *head)
{
    ListNode *prev = NULL, *cur = head, *nxt = NULL;
    while(cur){
        nxt = cur->next;//assign value to nxt
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
    return head;
}

int main()
{
    ListNode *head = createList();
    ListNode *rhead = reverse(head);
    ListNode *p = rhead;
    while(p){
        printf("%d\n", p->val);
        p = p->next;
    }
    return 0;
}
