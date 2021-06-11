class PeekingIterator : public Iterator {
public:
	int nextval;
	bool has = false;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
		// Initialize any member here.
		// **DO NOT** save a copy of nums and manipulate it directly.
		// You should only use the Iterator interface methods.
		if (Iterator::hasNext()) {
			has = true;
			nextval = Iterator::next();
		}

	}

	// Returns the next element in the iteration without advancing the iterator.
	int peek() {
		return nextval;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
		int x = nextval;
		if (Iterator::hasNext()) {
			has = true;
			nextval = Iterator::next();
		}
		else
			has = false;
		return x;
	}

	bool hasNext() const {
		return has || Iterator::hasNext();
	}
};
