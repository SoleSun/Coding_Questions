#include <iostream>
#include <vector>
#include <queue>

struct ListNode 
{
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct ListNodeComparison
{
	bool reverse;
public:
	ListNodeComparison(const bool& revparam=false){ reverse = revparam; }
	bool operator () ( const ListNode a, const ListNode b ) const 
    {
        return reverse ? a.val < b.val : a.val > b.val;
    }
};

typedef std::priority_queue<ListNode, std::vector<ListNode>, ListNodeComparison> 
        	minHeap;

class Solution
{
public:
	ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		ListNode temp(0xFFFFFFFF); 
		ListNode* head = &temp;
		ListNode* builder = head;

		if (!lists.empty())
		{ 
	        // Construct the priority queue
	        minHeap queueStorage;
	        for (ListNode* ln : lists)
	        {	
	        	for (ListNode * itr = ln; itr != NULL; itr = itr->next)
	        		if (itr != NULL) queueStorage.push(*itr);
	        }

	       	while (!queueStorage.empty())
	        {
	        	builder->next = new ListNode(queueStorage.top().val);
	        	builder = builder->next;
	        	queueStorage.pop();
	        }
	    }

        return head->next;
    }
};

int main(void)
{
	ListNode  head1(1);
	ListNode  five(5);
	ListNode  six(6);
	ListNode  head2(1);
	ListNode  three(3);
	ListNode  four(4);
	ListNode  head3(2);
	ListNode  six2(6);

	head1.next = &five;
	five.next = &six;

	head2.next = &three;
	three.next = &four;

	head3.next = &six2;

	std::vector<ListNode*> construct = {&head1, &head2, &head3};

	Solution sol; 
	ListNode* result = sol.mergeKLists(construct);

	for (ListNode* itr = result; itr != NULL; itr = itr->next)
		std::cout << itr->val << std::endl;

	std::vector<ListNode*> construct2;
	result = sol.mergeKLists(construct2);

	if (result != NULL)
	{
		for (ListNode* itr = result; itr != NULL; itr = itr->next)
			std::cout << itr->val << std::endl;
	}
	return 0;
}