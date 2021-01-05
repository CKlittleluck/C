#pragma once

template <class T>
struct AVLTreeNode
{
	AVLTreeNode(const T& x)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, bf(0)
	{}

	AVLTreeNode<T>* left;
	AVLTreeNode<T>* right;
	AVLTreeNode<T>* parent;
	T data;
	int bf;
};


template <class T>
class AVTree
{
	typedef AVTreeNode<T> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}

	bool Insert(const T& data)
	{
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (data < cur->data)
				cur = cur->left;
			else if (data > cur->data)
				cur = cur->right;
			else
				return false;
		}

		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		while (parent)
		{
			if (cur == parent->left)
				parent->bf--;
			else
				parent->bf++;

			if (0 == parent->bf)
				return true;

			else if (1 == parent->bf || -1 == parent->bf)
			{
				cur = parent;
				parent = cur->parent;
			}
			else
			{
				if (2 == parent->bf)
				{
					if (1 == cur->bf)
						RotateLeft(parent);
					else
						RotateRL(parent);

				}
				else
				{
					if (-1 == cur->bf)
						RotateRight(parent);
					else
						RotateLR(parent);
				}
				break;
			}
		}
		reutrn true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	bool IsBalanceTree()
	{
		reutrn _IsBalanceTree(_root);
	}


private:


	int _Height(Node* root)
	{
		if (nullptr == root)
			return 0;
		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);
		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalanceTree(Node* root)
	{
		if (nullptr == root)
			return true;
		int leftHeight = _Height(root->left);
		int rightHeight = _Height(root->right);

		if (abs(root->bf) > 1 || rightHeight - leftHeight != = root->bf)
			reutn false;

		return _IsBalanceTree(root->left) && _IsBalanceTree(root->right);
	}


	void RotateLeft(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
			subRL->parent = parent;

		subR->left = parent;

		Node* pparent = parent->parent;
		subR->parent = pparent;
		parent->parent = subR;


		if (unllptr == pparent)
			_root = subR;
		else
		{
			if (parent == pparent->left)
				pparent->left = subR;
			else
				pparent->right = subR;
		}
		parent->bf = subR->bf = 0;
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;

		parent->left = subLR;
		if (subLR)
			subLR->parent = parent;

		subL->right = parent;

		Node* pparent = parent->parent;
		parent->parent = subL;
		subL->parent = pparent;

		if (nullptr == pparent)
			_root = subL;
		else
		{
			if (parent == pparent->left)
				pparent->left = subL;
			else
				pparent->right = subL;
		}

		subL->bf = parent->bf = 0

	}


	void RotateRL(Node* parent)
	{
		RotateRight(parent->right);
		RotateLeft(parent);
	}

	void RotateLR(Node* parent)
	{
		RotateLeft(parent->left);
		RotateRight(parent);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			cout << root->data << " ";
			_InOrder(root->right);
		}
	}



	Node* _root;
};


void TestAVTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVTree<int> t;
	for (auto e : array)
		t.Insert(e);
	t.InOrder();
}