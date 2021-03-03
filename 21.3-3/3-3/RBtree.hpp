#pragma once
#include <iostream>
using namespace std;

enum Color{RED, BLACK};


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
	: left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, data(x)
	, color(c)
	{
	}
	RBTreeNode<T>* left;
	RBTreeNode<T>* right;
	RBTreeNode<T>* parent;
	T data;
	Color color;
};

template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;

public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}

	bool Insert(const T& data)
	{
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			return true;
		}

		Node* cur = root;
		Node* parent = head;
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
		//插入新节点
		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;
		while (parent != head && RED == parent)
		{
			Node* grandFather = parent->parent;
			if (parent == grandFather->left)
			{
				Node* uncle = granfFather->right;
				if (uncle && uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}
				else
				{
					if (cur == parent->right)
					{
						RotateLeft(parent);
						swap(parent, cur);
					}
					parent->color = BLACK;
					grandFather->color = RED;
					RotateRight(grandFatner);
				}
			}

			else
			{
				Node* uncle = granfFather->left;
				if (uncle && uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandFather->color = RED;
					cur = grandFather;
					parent = cur->parent;
				}

				else
				{
					if (cur == parent->left)
					{
						RotateLeft(parent);
						swap(parent, cur);
					}
					parent->color = BLACK;
					grandFather->color = RED;
					RotateLeft(grandFatner);
				}
			}
		}
		root->color = BLACK;
		head->left = leftMost();
		head->right = RightMost();
		return true;
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

	void InOrder()
	{
		_InOrder(head->parent);
		cout << endl;
	}

private:
	Node* leftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->left)
			cur = cur->left;
		return cur;
	}

	Node* rightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;

		while (cur->right)
			cur = cur->right;
		return cur;
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
		parent->parent = subR;
		subR->parent = pparent;

		if (pparent == head)
		{
			head->parent = subR;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subR;
			}
			else
			{
				pparent->right = subR;
			}
		}

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
		if (pparent == head)
		{
			head->parent = subL;
		}
		else
		{
			if (parent == pparent->left)
			{
				pparent->left = subL;
			}
			else
			{
				pparent->right = subL;
			}
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->left);
			count << root->data << " ";
			_InOrder(root->right);
		}
	}

	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->left);
			_Destroy(root->right);
			delete root;
			root = nullptr;
		}
	}

private:
	Node* head;
};


void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}