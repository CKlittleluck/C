class Solution {
public:
	int hIndex(vector<int>& citations) {
		int n = citations.size();
		if (n == 0){
			return 0;
		}

		int h = n;
		sort(citations.begin(), citations.end());
		for (int i = 0; i<citations.size(); i++){
			if (citations[i] < h){
				h -= 1;
			}
		}
		return h;
	}
};

