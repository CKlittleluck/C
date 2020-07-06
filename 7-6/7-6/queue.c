#define _CRT_SECURE_NO_WARNINGS  1
#include<stdbool.h>
typedef struct 
{
	Queue q1;
	Queue q2;
}MyStack;

MyStack* myStackCreate()
{
	MyStack* ms = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&ms->q1);
	QueueInit(&ms->q2);
	return ms;
}

void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
		QueuePush(&obj->q2, x);
}

int myStackPop(MyStack* obj)
{
	int ret = 0;
	if (!QueueEmpty(&obj->q1))
	{
		while (QueueSize(&obj->q1) > 1)
		{
			myStackPush(&obj->q2, QueueFront(&obj->q1));
			QueuePop(&obj->q1);
		}
		ret = QueueFront(&obj->q1);
		QueuePop(&obj->q1);
	}
	else
	{
		while (QueueSize(&obj->q2) > 1)
		{
			myStackPush(&obj->q1, QueueFront(&obj->q2));
			QueuePop(&obj->q2);
		}
		ret = QueueFront(&obj->q2);
		QueuePop(&obj->q2);
	}
	return ret;
}

int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
		return QueueBack(&obj->q1);
	else
		return QueueBack(&obj->q2);
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}