vector<int> temp;
void dfs(int cur, int n) {
	// ��֦��temp ���ȼ������� [cur, n] �ĳ���С�� k�������ܹ��������Ϊ k �� temp
	if (temp.size() + (n - cur + 1) < k) {
		return;
	}
	// ��¼�Ϸ��Ĵ�
	if (temp.size() == k) {
		ans.push_back(temp);
		return;
	}
	// cur == n + 1 ��ʱ������ݹ�
	if (cur == n + 1) {
		return;
	}
	// ����ѡ��ǰλ��
	temp.push_back(cur);
	dfs(cur + 1, n, k);
	temp.pop_back();
	// ���ǲ�ѡ��ǰλ��
	dfs(cur + 1, n, k);
}
