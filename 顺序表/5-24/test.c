#define _CRT_SECURE_NO_WARNINGS  1

#include"SeqList.h"
int main()
{
	SeqList ps;
	SeqListInit(&ps, 10);
	SeqListPushBack(&ps, 1);
	SeqListPushBack(&ps, 2);
	SeqListPushBack(&ps, 3);
	SeqListPushBack(&ps, 4);
	SeqListPushBack(&ps, 5);
	SeqListPrint(&ps);
	SeqListInsert(&ps, 3, 22);
	SeqListPrint(&ps);
}