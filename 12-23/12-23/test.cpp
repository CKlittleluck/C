#include <iostream>
#include <vector>
using namespace std;

//前序中序还原二叉树
class Solution
{
public:
	TreeNode* RebuildTree(vector<int>& preorder, vector<int>& inorder, int left, int right, size_t index)
	{
		if (lndex >= preorder.size())
		{
			return nullptr;
		}
		TreeNode* root = new TreeNode(preorder[index]);


		size_t mid = left;
		while (mid < right)
		{
			if (preorder[index] == inorder[mid])
				break;

			++mid;
		}
		if (left < mid)
		{
			root->left = RebuildTree(preorder, inorder, left, mid, ++index);
		}
		if (mid + 1 < right)
		{
			root->right = RebuildTree(preorder, inorder, mid + 1, right, ++index);
		}
		return root;
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		size_t index = 0;
		return RebuildTree(preorder, inorder, 0, inorder.size(), index);
	}
};