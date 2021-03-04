#pragma once
#include <iostream>
using namespace std;

enum Color{ RED, BLACK };

//给红黑树增加迭代器
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> self;
	RBTreeIterator(Node* node = nullptr)
		:pNode(node)
	{}

	T& operator*()
	{
		return pNode->data;
	}

	T* operator->()
	{
		// reutrn &(pNode->data);
		return & (operator* ());
	}

	self& operator++()
	{
		Increament();
		return *this;
	}

	self operator++(int)
	{
		self temp(*this);
		Increament();
		return *this;
	}

	self& operator--()
	{
		Decreament();
		return *this;
	}

	self operator--(int)
	{
		self temp(*this);
		Decreament();
		return *this;
	}

	bool operator==(const self& s)const
	{
		return pNode == s.pNode;
	}

	bool operator!=(const self& s)const
	{
		return pNode != s.pNode;
	}

private:
	void Increament()
	{
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
			{
				pNode = pNode->left;
			}
		}
		else
		{
			Node* parent = pNode->parent;
			while (parent->right == pNode)
			{
				pNode = parent;
				parent = pNode->parent;
			}
			if (pNode->right != parent)
				pNode = parent;
		}
	}


	void Decreament()
	{

		if (pNode->parent->parent == pNode && RED == pNode->color)
		{
			pNode = pNode->right;
		}
		else if (pNode->left)
		{
			pNode = pNode->right;
			while (pNode->right)
			{
				pNode = pNode->right;
			}
		}
		else
		{
			Node* parent = pNode->parent;
			while (parent->left == pNode)
			{
				pNode = parent;
				parent = pNode->parent;
			}
			pNode = parent;
		}
	}



	Node* pNode;
};




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

template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
	{
		head = new Node();
		head->left = head;
		head->right = head;
		_size = 0;
	}

	~RBTree()
	{
		_Destroy(head->parent);
	}
	////////////////////////
	///////iterator////////

	iterator begin()
	{
		return iterator(head->left);
	}

	iterator end()
	{
		return iterator(head);
	}

	//////////////////////
	/////////capacity////

	bool empty() const
	{
		return nullptr == head->parent;
	}

	size_t size() const
	{
		return _size;
	}


	pair<iterator, bool> Insert(const T& data)
	{
		Node*& root = GetRoot();
		if (nullptr == root)
		{
			root = new Node(data, BLACK);
			head->left = root;
			head->right = root;
			root->parent = head;
			_size = 1;
			return make_pair(iterator(root), true);
		}

		Node* cur = root;
		Node* parent = head;
		KOFV kofv;
		while (cur)
		{
			parent = cur;
			if (kofv(data) < kofv(cur->data))
				cur = cur->left;
			else if (kofv(data) > kofv(cur->data))
				cur = cur->right;
			else
				return make_pair(iterator(cur), false);
		}
		//插入新节点
		cur = new Node(data);
		Node* pNewNode = cur;
		if (kofv(data) < kofv(parent->data))
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
		_size++;
		return make_pair(iterator(pNewNode), true);
	}

	Node*& GetRoot()
	{
		return head->parent;
	}


	void swap(RBTree<T> & t)
	{
		std::swap(head, t.head);
	}

	void clear()
	{
		_Destroy(head->parent);
		_size = 0;

		head->left = head;
		head->right = head;
	}

	iterator find(const T&data)const
	{
		KOFV kofv
		Node* cur = GetRoot();
		while (cur)
		{
			if (kofv(data) == kofv(cur->data))
				return iterator(cur);
			else if (kofv(data) < kofv(cur->data))
			{
				cur = cur->left;
			}
			else
			{
				cur = cur->right;
			}
		}
		return end();
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
			_size = 0;
		}
	}

private:
	Node* head;
	size_t _size;
};


void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> t;


	RBTree<int>::iterator it = t.begin();
	while (it != t.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
}