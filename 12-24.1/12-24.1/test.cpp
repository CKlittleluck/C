#include <iostream>
using namespace std;

//三叉链表
//最近公共祖先
class Solution
{
public:
	bool GetNothPath(TreeNode* root, TreeNode* p, stack<TreeNode*> & s)
	{
		if (nullptr == root)
			return false;
		s.push(root);
		if (root == p)
			return true;

		bool isIn = false;
		if (isIn = GetNothPath(root->left), p, s)
			return true;
		if (isIn = GetNothPath(root->right), p, s)
			return true;

		s.pop();
		return false;

	}

	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		if (p == root || q == root)
			return root;


		stack <TreeNode*> s1, s2;
		GetNothPath(root, p, s1);
		GetNothPath(root, q, s2);

		int size1 = s1.size();
		int size2 = s2.size();
		while (!s1.empty() && !s2.empty())
		{
			if (size1 > size2)
			{
				s1.pop();
				size1--;
			}

			else if (size2 > size1)
			{
				s2.pop();
				size2--;
			}
			else
			{
				if (s1.top() == s2.top())
					return s1.top();
				else
				{
					s1.pop();
					s2.pop();
					size1--;
					size2--;
				}
			}

		}
		return nullptr;
	}
};

