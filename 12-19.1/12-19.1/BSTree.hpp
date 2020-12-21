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
class Bs