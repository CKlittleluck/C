#define _CRT_SECURE_NO_WARNINGS  1
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"

// 初始化队列 
int QueueInit(Queue** q)
{
	if (NULL == q)
	{
		return false;
	}
	Queue *q = ((Queue*)malloc(sizeof(Queue));
	if (NULL == *q)
	{
		return false;
	}
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if (NULL == P)
	{
		return false;
	}
	p->next = NULL;

	(*q)->front = p;
	(*q)->rear = p;
	return true;
}

// 队尾入队列 
int QueuePush(Queue* q, QDataType data)
{
	if (NULL == q)
	{
		return false;
	}
	QNode* p = (QNode*)malloc(sizeof(QNode));
	if (NULL == p)
	{
		return false;
	}
	p->data = data;
	p->next = NULL;

	q->rear->next = p;
	q->rear = p;
	return true;
}

// 队头出队列 
void QueuePop(Queue* q)
{
	if (q == NULL)
	{
		return;
	}
	if (q->front == NULL)
	{
		printf("空队列\n");
		return;
	}
	QNode* to_delete = q->front;
	q->front = to_delete->next;
	QueueDestroy(to_delete);
	return;
}


// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	if (NULL == q || q->front->next == NULL)
	{
		return false;
	}

	return q->front->next->data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	QNode* queNode = NULL;
	int len = 0;
	if (QueueEmpty(q))
	{
		printf("链式队列为空");
		return len;
	}
	queNode = q->front->next;
	while (queNode != NULL)
	{
		len++;
		queNode = queNode->next;
	}
	return len;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{

	if (q->front == q->rear)
		return 1;
	else
		return 0;
}


// 销毁队列 
void QueueDestroy(Queue** q)
{
	if (NULL == q || *q == NULL)
	{
		return false;
	}
	QNode *p = (*q)->front->next;
	while (p)
	{
		(*q)->front->next = p->next;
		free(p);
		p = (*q)->front->next;
	}
	(*q)->rear = (*q)->front;
	free((*q)->rear);
	free(*q);
	return true;
}
