#include <iostream>
using namespace std;


class Solution 
{
public:
	int myAtoi(string s) 
{
		int i = 0;
		long long sum = 0;
		bool flag = false, symbol = true;//flagΪ��ȡ��־��Ϊ��ʱ��ȡ����.symbolΪsum�ķ��ţ���true����false
		while (i < s.length()){//�ж��Ƿ񳬳�����
			if (!flag && s[i] != ' ') //���û�п�ʼ��ȡ�Ҳ��ǿո�
			if (s[i] == '+' || s[i] == '-' || s[i] >= '0' && s[i] <= '9'){//�Ϳ��Կ�ʼ������
				flag = true;//�ñ�־Ϊ��
				if (s[i] == '-') symbol = false, i++;//����Ƿ�������治�ö��ˣ�ֱ����
				else if (s[i] == '+') i++;//symbolĬ��true���������ø�ֵ
			}
			else return 0;//��һ���ǿ��ַ��Ƿ�������0
			if (flag && !(s[i] >= '0' && s[i] <= '9')) if (!symbol) return -sum; else return sum;//�����ȡ�Ĺ����������Ƿ��ַ�������ݷ��ŷ��ص�ǰֵ
			if (flag) sum = sum * 10 + s[i] - '0';//��ô���������ǺϷ��ģ�ֱ�Ӽ�
			if (sum > INT_MAX && symbol) return INT_MAX;//��**��**���������ֵ���������ֵ
			else if (sum > INT_MAX && !symbol) return INT_MIN;//��**��**�����ڵ���ʹ�÷���λ������������������ʾ�ģ������������ޣ����ظ������ޡ�
			i++;//������
		}
		if (!symbol) return -sum;//����ٸ��ݷ��ŷ���ֵ
		else return sum;
	}
};

