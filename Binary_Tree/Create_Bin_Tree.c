#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct __node_t
{
	int id;
	struct __node_t *left;
	struct __node_t *right;
} node_t;

node_t* createNewNode(int id)
{
	node_t * temp = (node_t *)malloc(sizeof(node_t));
	temp->id = id;
	temp->left = temp->right = NULL;
	return temp;
}

// Assume that there are no duplicate nodes
void insertBSTNode(int id, node_t *head)
{
	if(id > head->id)
	{
		if (head->right == NULL)
		{
			head->right = createNewNode(id);
		}
		else
		{
			insertBSTNode(id, head->right);
		}
	}
	else if(id < head->id)
	{
		if (head->left == NULL)
		{
			head->left = createNewNode(id);
		}
		else
		{
			insertBSTNode(id, head->left);
		}
	}
	else{ (void)0; }
}

node_t *createBSTWrapper(int arr[], int num_of_elements)
{
	if (num_of_elements > 0)
	{
		node_t *head = createNewNode(arr[0]);

		for (int i = 1; i < num_of_elements; i++)
		{
			insertBSTNode(arr[i], head);
		}

		return head;
	}
	else
	{
		return NULL;
	}
}


void inOrderTraversal(node_t *head, bool inOrder)
{
	if(head == NULL)
	{
		return;
	}

	if(head->left != NULL)
	{
		inOrder &= head->left->id <= head->id;
		inOrderTraversal(head->left, inOrder);
	}

	printf("ID %d\n", head->id);

	if(head->right != NULL)
	{
		inOrder &= head->right->id > head->id;
		inOrderTraversal(head->right, inOrder);
	}
}

bool verifyBinaryTreeOrdering(node_t *head)
{
	bool isOrdered = true; 

	inOrderTraversal(head, isOrdered);

	return isOrdered;
}

int main(void)
{
	int arr[7] = {23, 45, 10, 11, 5, 9, 89};

	node_t* head = createBSTWrapper(arr, 7);

	if (verifyBinaryTreeOrdering(head))
	{
		printf("It's good!\n");
	}

	return 0;
}



