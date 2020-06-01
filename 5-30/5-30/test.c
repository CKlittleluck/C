#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include "test.h"
//���������ָ����ֵ���зָ����С��x�Ľ�����ڴ��ڵ���x�Ľ��֮ǰ
ListNode* partition(ListNode* phead, int x)
{
	if (NULL == phead)
	{
		return NULL;
	}
	ListNode lesshead;
	ListNode greathead;
	ListNode* lesstail = &lesshead;
	ListNode* greattail = &greathead;
	ListNode* cur = phead;

	while (cur)
	{
		phead = cur->next;
		if (cur->val < x)
		{
			lesstail->next = cur;
			lesstail = cur;
		}
		else
		{
			greattail->next = cur;
			greattail = cur;
		}
		cur = phead;
	}
	greattail->next = NULL;
	lesstail->next = greathead.next;
	return lesshead.next;
}