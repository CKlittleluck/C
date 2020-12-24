#include <iostream>
#include <vector>
using namespace std;

//中序后序还原二叉树
class Solution
{
public:
	TreeNode* RebuildTree(vector<int>& inorder, vector<int>& postorder, int left, int right, int& index)
	{
		if (index < 0)
			return nullptr;
		TreeNode* root = new TreeNode(postorder[index]);

	}

	size_t mid = left;
	while (mid < right)
	{
		if (postorder[index] == inorder[mid])
			break;
		++mid;
	}

	if (mid + 1 < right)
	{
		root->right = RebulidTree(inorder, postorder, mid + 1, right, --index);

	}

	if (left < mid)
		root->left = RebulidTree(inorder, postorder, left, mid, --index);
	return root;

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		int index = postorder.size()-1;
		return RebuildTree(inorder, preorder, 0, inorder.size(), index);
	}
};