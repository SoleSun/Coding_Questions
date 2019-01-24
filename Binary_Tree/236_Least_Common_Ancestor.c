struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {

    //Account for the two base cases
    if (root == NULL)
    {
    	return NULL;
    }

    if (root->val == p->val || root->val == q->val)
    {
    	return root;
    }

    struct TreeNode *left_lca  = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *right_lca = lowestCommonAncestor(root->right, p, q);
    //perform pre-order traversal
    if (left_lca != NULL && right_lca != NULL)
    {
	return root;
    }

    return left_lca != NULL ? left_lca : right_lca;
}
