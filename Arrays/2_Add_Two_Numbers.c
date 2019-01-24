#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = (struct ListNode*) calloc(1, sizeof(struct ListNode*)); 
    struct ListNode* ret  = head; 
    
    while (l1 && l2)
    { 
        ret->val += (l1->val + l2->val) % 10; 
        
        /*
          When is there a need to create the next node:
           - the next nodes aren't null
           - there is a leading one 
        */

        if (((l1->val + l2->val) / 10) || l1->next != NULL || l2->next != NULL)
        {
            ret->next      = (struct ListNode*) calloc(1, sizeof(struct ListNode*));
            ret->next->val += (l1->val + l2->val) / 10; 
        }
        
        if (l1->next == NULL ^ l2->next == NULL)
        {
            struct ListNode* leading_one = ret->next;
            int temp = leading_one->val;
            temp += l1->next ? l1->next->val : l2->next->val;

            while(temp / 10)
            {
                leading_one->next = (struct ListNode*) calloc(1, sizeof(struct ListNode*));
                leading_one = leading_one->next;

                leading_one->value += temp / 10;
            } 
            ret->next->val += l1->next ? l1->next->val : l2->next->val; 
        }
        
        ret = ret->next;
        l1  = l1->next;
        l2  = l2->next;        
    }
    return head;
}

int main(void)
{
    printf("Hello World!\n");
    struct ListNode x  = {8, NULL};
    struct ListNode t1 = {0, &x};
    struct ListNode t2 = {1, NULL};

    struct ListNode* result = addTwoNumbers(&t1, &t2);

    while(result != NULL) 
    {
        printf("%d \n", result->val);
        result = result->next;
    }
}