#define _CRT_SECURE_NO_WARNINGS  1
#include"test.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

typedef char STDataType;

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->array = (STDataType*)malloc(sizeof(STDataType*)* 10);
	if (NULL == ps->array)
	{
		assert(0);
		return;
	}
	ps->capacity = 10;
	ps->size = 0;
}


// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//CheckCapacity(ps);
	ps->array[ps->size++] = data;
}




// ��ջ 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}


// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}




// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}




// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}




// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}






bool isValid(char* s)
{
	Stack sa;
	StackInit(&sa);
	int len = strlen(s);
	bool ret = true;
	for (int i = 0; i < len; ++i)
	{
		if ('(' == s[i] || '[' == s[i] || '{' == s[i])
			StackPush(&sa, s[i]);
		else
		{
			if (StackEmpty(&sa))
			{
				ret = false;
				break;
			}


			char ch = StackTop(&sa);
			if ((ch == '(' && ')' == s[i]) || (ch == '[' && ']' == s[i]) || (ch == '{' && '}' == s[i]))
			{
				StackPop(&sa);
				continue;
			}
			else
			{
				ret = false;
				break;
			}
		}
	}


	if (!StackEmpty(&sa))
		ret = false;
	StackDestroy(&sa);
	return ret;
}