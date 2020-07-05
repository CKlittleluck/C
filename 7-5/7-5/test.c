#define _CRT_SECURE_NO_WARNINGS  1
#include"test.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<stdbool.h>

// 支持动态增长的栈
typedef int STDataType;


// 初始化栈 
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


// 入栈 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	//CheckCapacity(ps);
	ps->array[ps->size++] = data;
}




// 出栈 
void StackPop(Stack* ps)
{
	if (StackEmpty(ps))
		return;
	ps->size--;
}


// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(!StackEmpty(ps));
	return ps->array[ps->size - 1];
}




// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->size;
}




// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);
	return ps->size == 0;
}


// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->array);
	ps->capacity = 0;
	ps->size = 0;
}

typedef struct
{
	Stack s1;
	Stack s2;
}MyQueue;

MyQueue* myQueueCreate()
{
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&mq->s1);
	StackInit(&mq->s1);
	return mq;
}

void myQueuePush(MyQueue* obj, int x)
{
	StackPush(&obj->s1, x);
}

int myQueuePeek(MyQueue* obj)
{
	if (StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	return StackTop(&obj->s2);
}

int myQueuePop(MyQueue* obj)
{
	if (StackEmpty(&obj->s2))
	{
		while (!StackEmpty(&obj->s1))
		{
			StackPush(&obj->s2, StackTop(&obj->s1));
			StackPop(&obj->s1);
		}
	}
	int ret = StackPop(&obj->s2);
	StackPop = (&obj->s2);
	return ret;
}

bool myQueuePop(MyQueue* obj)
{
	return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void MyQueueFree(MyQueue* obj)
{
	StackDestroy(&obj->s1);
	StackDestroy(&obj->s2);
	free(obj);
}