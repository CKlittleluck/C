#define _CRT_SECURE_NO_WARNINGS  1
#include "SeqList.h"

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}
	printf("%\n");
}


void CheckCacpcity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity*sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}

void SeqListPushBack(SeqList* ps, SLDateType x)
{
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, 0);
}


void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	SeqListErase(ps, ps->size - 1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
		return -1;
	}
}

void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);
	CheckCacpcity(ps);
	size_t end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->size);
	size_t start = pos + 1;
	while (start < ps->size)
	{
		ps->a[start - 1] = ps->a[start];
		++start;
	}
	ps->size--;
}