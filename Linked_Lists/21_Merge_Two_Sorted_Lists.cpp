#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0); //Create a temp head
		ListNode *builder = head; 

		while(l1 != NULL || l2 != NULL)
		{
			if(l1 != NULL && l2 != NULL)
			{
				if(l1->val < l2->val)
				{
					builder->next = l1;
					l1 = l1->next;
				}
				else
				{
					builder->next = l2;
					l2 = l2->next;
				}
			}
			else if(l1 != NULL)
			{
				builder->next = l1;
				l1 = l1->next;
			}
			else
			{
				builder->next = l2;
				l2 = l2->next;	
			}

			builder = builder->next;
		}        

		return head->next;
    }
};

int main (void)
{
	return 0;
}
