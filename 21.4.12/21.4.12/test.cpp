class PeekingIterator : public Iterator {
private:
	int _val;
	bool _next;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		_next = Iterator::hasNext();
		if (_next) _val = Iterator::next();
	}

	int peek() {
		return _val;
	}

	int next() {
		int cur = _val;
		_next = Iterator::hasNext();
		if (_next) _val = Iterator::next();
		return cur;
	}

	bool hasNext() const {
		return _next;
	}
};
