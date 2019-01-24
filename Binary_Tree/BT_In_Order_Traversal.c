
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
