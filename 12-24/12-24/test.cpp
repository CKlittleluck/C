#include <iostream>
using namespace std;

//¶þ²æÊ÷´´½¨×Ö·û´®
class Solution
{
public:
	void _tree2str(TreeNode* root, string& strRet)
	{
		if (nullptr == root)
			return;

		char sz[32] = { 0 };
		sprintf(sz, "%d", root->value);
		strRet += sz;

		if (nullptr == root->left)
		{
			if (nullptr == root->right)
				return;
			else
				strRet += "()";
		}

		else
		{
			strRet += "(";
			_tree2str(root->left, strRet);
			strRet += ")";
		}

		if (nullptr == root->right)
		{
			return;
		}

		else
		{
			strRet += "(";
			_tree2str(root->right, strRet);
			strRet += ")";
		}
	}
};