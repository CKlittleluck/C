#pragma once

enum Color{RED, BLACK};

template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& x = T(), Color c = RED)
	:lefti9

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
				cur = cur->left;
			else
				return false;
		}

		cur = new Node(data);
		if (data < parent->data)
			parent->left = cur;
		else
			parent->right = cur;
		cur->parent = parent;


		if (RED == parent)
		{

		}

		head->left = LeftMost();
		head->right = RightMost();
		return true;
	}

	Node*& GetRoot()
	{
		return head->parent;
	}

private:
	Node* LeftMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;
		while (cur->left)
			cur = cur->left;
		return cur;
	}

	Node* RightMost()
	{
		Node* cur = GetRoot();
		if (nullptr == cur)
			return head;
		while (cur->right)
			cur = cur->right;
		return cur;
	}

private:
	Node* head;
};