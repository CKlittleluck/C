class Solution {
public:
	/**
	*  ����λ�϶�����������ż��λ�϶���ż��
	*  ���룺����arr�����ȴ���2
	*  len��arr�ĳ���
	*  ��arr����������λ�϶�����������ż��λ�϶���ż��
	*/
	void oddInOddEvenInEven(vector<int>& arr, int len) {
		int i = 0;
		int j = 1;

		while (i < len && j < len)
		{
			while (arr[i] % 2 == 0)
			{
				i += 2;
			}

			while (arr[j] % 2 != 0)
			{
				j += 2;
			}
			swap(arr[i], arr[j]);
		}
	}
};