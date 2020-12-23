#include <iostream>
#include <queue>

using namespace std;

//�������
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

//ǰ������ǵݹ�
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


//��������ǵݹ�
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

//��������ǵݹ�
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		// ����ֱ�ӷ���
		vector<int> vRet;
		if (nullptr == root)
			return vRet;

		TreeNode* pCur = root;
		TreeNode* pPrev = nullptr;
		stack<TreeNode*> s;
		while (pCur || !s.empty())
		{
			// ����pCurΪ���Ķ����������Ľڵ㣬��������·���еĽڵ���ջ
			while (pCur)
			{
				s.push(pCur);
				pCur = pCur->left;
			}

			TreeNode* pTop = s.top();

			// pTop�������Ѿ�����
			// ���pTop���������ǿգ������������Ѿ����ʹ��ˣ��Ϳ��Է���pTop
			if (nullptr == pTop->right || pPrev == pTop->right)
			{
				vRet.push_back(pTop->val);
				s.pop();

				// ���ոշ��ʹ��Ľڵ�������
				pPrev = pTop;
			}
			else
			{
				// ���������û�з��ʣ�������������һ���µĶ���������
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
