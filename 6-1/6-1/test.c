#define _CRT_SECURE_NO_WARNINGS  1

//返回链表中环的入口点
#include<stdio.h>
#include<stdbool.h>
#include"test.h"
ListNode* hasCycle(ListNode* head)
{
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
		{
			return fast;
		}
	}
	return NULL;
}

ListNode* detectCycle(struct ListNode* head)
{
	ListNode* PH = head;
	ListNode* PM = hasCycle(head);
	if (PM == NULL)
	{
		return false;
	}
	while (PH != PM)
	{
		PH = PH->next;
		PM = PM->next;
	}
	return PM;
}