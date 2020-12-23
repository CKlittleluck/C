#include <iostream>
#include <queue>

using namespace std;

//层序遍历
void LevelOrder()
{
	if (nullptr == root)
		return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* cur = q.front();
		cout << cur->key << "-->" << cur->value << endl;
		if (cur->left)
			q.push(cur->left);
		if (cur->right)
			q.push(cur->right);

		q.pop();
	}
	cout << endl;
}

void TestBSTree()
{
	BSTree<int int> tt;
	int a[] = { 5, 3, 5, 1, 7, 2, 8, 0, 6 };
	for (auto e : a)
		tt.Insert(e, e);
	tt.LevelOrder();
}

//前序遍历非递归
class Solution
{
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> v;
		if (nullptr == root)
			return v;
		stack<TreeNode*> s;
		TreeNode* cur = root;
		s.push(root);
		while (!s.empty())
		{
			cur = s.top();
			s.pop();
			while (cur)
			{
				v.push_back(cur->val);
				if (cur->right)
					s.push(cur->right);
				cur = cur->left;
			}
		}
		return v;
	}
};


//中序遍历非递归
class Solution
{
public:
	vector<int> inorderTraversal(TreeNode* root)
	{
		vector <int> vRet;
		if (nullptr == root)
			return vRet;
		stack<TreeNode*> s;
		TreeNode* cur = root;

		while (cur || !s.empty())
		{
			while (cur)
			{
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			vRet.push_back(cur->val);
			s.pop();
			cur = cur->right;
		}
		return vRet;
	}
};

//后序遍历非递归
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		// 空树直接返回
		vector<int> vRet;
		if (nullptr == root)
			return vRet;

		TreeNode* pCur = root;
		TreeNode* pPrev = nullptr;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			// 找以pCur为根的二叉树最左侧的节点，并将所经路径中的节点入栈
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}

			TreeNode* pTop = s.top();

			// pTop左子树已经访问
			// 如果pTop的右子树是空，或者右子树已经访问过了，就可以访问pTop
			if (nullptr == pTop->right || pPrev == pTop->right)
			{
				vRet.push_back(pTop->val);
				s.pop();

				// 将刚刚访问过的节点标记起来
				pPrev = pTop;
			}
			else
			{
				// 如果右子树没有访问，将右子树当成一棵新的二叉树访问
				pCur = pTop->right;
			}
		}

		return vRet;
	}
};


class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int> vRet;
		if (nullptr == root)
			return vRet;
		TreeNode* pCur = root;
		TreeNode* pPrev = nullptr;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}
			TreeNode* pTop = s.top();

			if (nullptr == pTop->right || pPrev == pTop->right)
			{
				vRet.push_back(pTop->val);
				s.pop();
				pPrev = pTop;
			}
			else
			{
				pCur = pTop->right;
			}
		}
		return vRet;
	}
};
