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
		while ()
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
				//
			}
		}
		reutrn true;
	}
private:
	Node* _root;
};