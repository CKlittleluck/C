#pragma once

template <class T>
struct BSTNode
{
	BSTNode(const T& val = T())
	: left(nullptr)
	, right(nullptr)
	,data(val)
	{}

	BSTNode<T>* left;
	BSTNode<T>* right;
	T data;
};

template <class T>
class BSTree
{
	typedef BSTNode<T> Node;

public:
	BSTree()
		:root(nullptr)
	{}

	~BSTree()
	{
		_Destroy(root);
	}

	bool Insert(const T& data)
	{
		if (nullptr == root)
		{
			root = new Node(data);
			return true;
		}

		Node* cur = root;
		Node* parent = nullptr;

		while (cur)
		{
			parent = cur;
			if (data == cur->data)
				return false;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;

		return true;
	}

	Node* Find(const T& data)
	{
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data)
				reutrn cur;
			else if (data < cur->data)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}

	void Inorder()
	{
		_Inorder(root);
	}

	//删除
	bool Erase(const T& data)
	{
		if (nullptr == root)
		{
			return false;
		}
		Node* parent = nullptr;
		Node* cur = root;
		while (cur)
		{
			if (data == cur->data)
				break;
			else if (data < cur->data)
			{
				parent = cur;
				cur = cur->data;
			}
			else
			{
				parent = cur;
				cur = cur->right;
			}
		}

		//删除节点
		if (nullptr == cur)
		{
			return 
		}
		if (nullptr == cur->left)
		{
			if (nullptr == parent)
			{
				root = cur->right;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->right;
				else
					parent->right = cur->right;
			}
		}
		else if (nullptr == cur->right)
		{
			if (nullptr == parent)
			{
				root = cur->left;
			}
			else
			{
				if (cur == parent->left)
					parent->left = cur->left;
				else
					parent->right = cur->left;
			}
		}

		else
		{
			//左右孩子都存在
			Node* del = cur->right;
			parent = cur;
			while (del->left)
			{
				parent = del;
				del = del->left;
			}

		cur->data = del->data;
		if (del == parent->data)
			parent->left = del->right;
		else
			parent->right = del->right;
		cur = del;
		}
		delete cur;
		return true;
	}
	


private:
//中序遍历
void _Inorder(Node* pRoot)
{
	if (pRoot)
	{
		_Inorder(pRoot->left);
		cout << pRoot->data << " ";
		_Inorder(pRoot->right);
	}
}

void _Destroy(Node*& pRoot)
{
	if (pRoot)
	{
		_Destroy(pRoot->left);
		_Destroy(pRoot->right);
		delete pRoot;
		pRoot = nullptr;
	}
}

private:
	Node* root;
};

void TestBSTree()
{
	int a[] = { 5, 0, 3, 6, 4, 1, 9, 8, 7 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.Inorder();
}