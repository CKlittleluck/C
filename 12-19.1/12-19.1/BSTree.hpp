template <classT classV>
struct BSTNode
{
	BSTNode const K& k = K(), const V&v = V()
	: left(nullptr)
	, right(nullptr)
	, key(k)
	, value(v)
	{}

	BSTNode <K, V> *left;
	BSTNode <K, V> *right;
	K key;
	V value;
};

template<class K, class V>
class BsTree
{
	typedef BSTree<K, V> Node;
public:
	BSTree()
		:root(nullptr)
	{}

	Node* Find(const K& key)
	{
		Node* cur = root;
		while (cur)
		{
			if (key == cur->key)
				return cur;
			else if (key < cur->key)
				cur = cur->left;
			else
				cur = cur->right;
		}
		return nullptr;
	}


	bool Insert(const K& key, const V& value)
	{
		if (nullptr == root)
		{
			root = new Node(key, value);
			return true;
		}

		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key == cur->key)
				return false;
			else if (key < cur->key)
				cur = cur->left;
			else
				cur = cur->right;
		}

		cur = new Node(key, value);
		if (key < parent->key)
			parent->left = cur;
		else
			parent->right = cur;
		return true;
	}

private:
	Node* root;
};

void TestBSTree()
{
	string s[] = { "11111", "22222", "33333", "22222" };
	BSTree<string, size_t> t;
	BSTNode<string, size_t>* ret = nullptr;
	for (auto e : s)
	{
		if (ret = t.Find(e))
			ret->value++;
		else
			t.Insert(e, 1);
	}
}