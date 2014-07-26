#include <cstdio>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode* createList(int n)
{
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

int main()
{
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF){
        ListNode *head = createList(n);
        ListNode *fast = head, *slow = head;
        if(k == 0){
            printf("NULL\n");
            continue;
        }

        while(k-- && fast){
            fast = fast->next;
        }
        if(k > 0){
            printf("NULL\n");
            continue;
        }

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        printf("%d\n", slow->val);
    }
}
