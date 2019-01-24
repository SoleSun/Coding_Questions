#include <iostream>
#include <vector>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : 
    	val(x), left(left), right(right) {}
 };

class Solution 
{
public: 
	
	Solution(){};

	int distToNode(TreeNode *root, TreeNode *target, int depth)
	{
		if (root == NULL)
		{
			return -1; 
		}
		if(root == target) 
		{
			return depth;
		}

		int left  = distToNode(root->left, target, depth+1);
		int right = distToNode(root->right, target, depth+1);

		return left != -1 ? left : right; 
	}

	// Find all the children of the root a distance K away 
	void findKDistChildren(TreeNode *root,
		                   int K, int depth, std::vector<int> *storage)
	{
		if (root == NULL)
		{
			return;
		}

		// Return the ID of the child node
		if (depth == K)
		{
			storage->push_back(root->val);
			return;
		}

		// Visit the left node children
		findKDistChildren(root->left, K, depth+1, storage);
		// Visit the right node children
		findKDistChildren(root->right, K, depth+1, storage);
	}

	void findKDistCousins(TreeNode *root, TreeNode* target,
						  int K, int distance, std::vector<int> *storage)
	{
		if(root == NULL || root == target)
		{
			return;
		}

		if (K == distance)
		{
			storage->push_back(root->val);
		}

		// Determine if the target node exists in the left or right node
		// and retrieve the distance from the root node to target
		int left = distToNode(root->left, target, 1);
		int right = distToNode(root->right, target, 1);

		// Traversing in the direction of the target means that the distance is
		// subtracted by one; and plus one for away
		if (left == -1 && right == -1)
		{
			findKDistCousins(root->left,  target, K, distance+1, storage);
			findKDistCousins(root->right, target, K, distance+1, storage);	
		}
		else if (left != -1)
		{
			findKDistCousins(root->left,  target, K, distance-1, storage);
			findKDistCousins(root->right, target, K, distance+1, storage);
		}
		else
		{
			findKDistCousins(root->left,  target, K, distance+1, storage);
			findKDistCousins(root->right, target, K, distance-1, storage);
		}
	}

	std::vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
	{
		std::vector<int> nodes; 

		if (root != NULL)
		{
			// Find all the descendant nodes
			findKDistChildren(target, K, 0, &nodes);

			// Now find all the node that are cousin to the target node
			// First find the level the target exists on
			int depthToTargetFromRoot = distToNode(root, target, 0);
			// The target didn't even exist inside the tree or the root 
			// was the target and all the nodes have been found through the 
			// children
			if (depthToTargetFromRoot > 0)
			{
				findKDistCousins(root, target, K, depthToTargetFromRoot, &nodes);
			}
		}

		return nodes;
	}
};

int main(void)
{
	TreeNode seven(7);
	TreeNode four(4);
	TreeNode two(2, &seven, &four);
	TreeNode six(6);
	TreeNode five(5, &six, &two);
	TreeNode zero(0);
	TreeNode eight(8);
	TreeNode one(1, &zero, &eight);
	TreeNode three(3, &five, &one);

	Solution sol;
	std::vector<int> result = sol.distanceK(&three, &five, 2);

	for(unsigned int i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl;
	
	zero.left  = NULL; zero.right  = &one;
	one.left   = NULL; one.right   = &two;
	two.left   = NULL; two.right   = &three;
	three.left = NULL; three.right = NULL;

	result = sol.distanceK(&zero, &one, 2);

	for(unsigned int i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl;

	zero.left  = &one; zero.right  = NULL;
	one.left   = &three; one.right   = &two;
	two.left   = NULL; two.right   = NULL;
	three.left = NULL; three.right = NULL;

	result = sol.distanceK(&zero, &two, 1);

	for(unsigned int i = 0; i < result.size(); i++)
		std::cout << result[i] << std::endl;
	return 0;
}
