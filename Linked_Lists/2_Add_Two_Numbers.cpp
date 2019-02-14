#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *head = new ListNode(0);
		ListNode *builder = head;
		
		do
		{
			int digit = builder->val;
			
			if (l1 != NULL)
			{
				digit += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL)
			{
				digit += l2->val;
				l2 = l2->next;
			}

			builder->val = digit % 10;

			if (!(l1 == NULL && l2 == NULL && digit/10 == 0))
			{
				builder->next = new ListNode(digit / 10);
				builder = builder->next;
			}
		} while (l1 != NULL || l2 != NULL);

		return head;
    }
};

int main(void)
{
	ListNode head1(2);
	ListNode t1(4);
	ListNode t2(3);
	head1.next = &t1; t1.next = &t2;

	ListNode head2(5);
	ListNode t3(6);
	ListNode t4(4);
	head2.next = &t3; t3.next = &t4;

	Solution sol;
	ListNode* result = sol.addTwoNumbers(&head1, &head2);

	for (ListNode* itr = result; itr != NULL; itr = itr->next)
	{
		std::cout << itr->val << std::endl;
	}
}