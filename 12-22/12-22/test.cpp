#include <iostream>;
using namespace std;


//中序遍历
void Inorder(TreeNode* root, vector<TreeNode*>& V)
{
	if (root)
	{
		Inorder(root->left,v);
		v.push_back(root);
		Inorder(root->right,v);
	}
}

//1 将二叉搜索树转为双向链表
TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (nullptr == pRootOfTree)
		reutrn nullptr;


	vector<TreeNode*> v;
	Inorder(pRootOfTree, v);

	if (v.size() == 1)
		return v[0];

	for (size_t i = 1; i < size() - 1; ++i)
	{
		v[i]->left = v[i - 1];
		v[i]->right = v[i + 1];
		v[v.size() - 1]->left = v[v.size() - 2];
		v[v.size() - 1]->right = nullptr;

		return v[0];
	}
}


// 2 
void Convert(TreeNode* root, TreeNode*& prev)
{
	if (nullptr == root)
		return;
	Convert(root->left, prev);
	root->left = prev;
	if (prev)
		prev->right = root;

	prev = root;
	Convert(root->right, prev);

	return head;
}




TreeNode* Convert(TreeNode* pRootOfTree)
{
	if (nullptr == pRootOfTree)
		return nullptr;
	//找链表的首节点
	TreeNode* head = pRootOfTree;
	while (head->left)
		head = head->left;
	TreeNode* prev = nullptr;
	Convert(pRootOfTree, prev);
}