#define _CRT_SECURE_NO_WARNINGS  1
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"

// ��ʼ������ 
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

// ��β����� 
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

// ��ͷ������ 
void QueuePop(Queue* q)
{
	if (q == NULL)
	{
		return;
	}
	if (q->front == NULL)
	{
		printf("�ն���\n");
		return;
	}
	QNode* to_delete = q->front;
	q->front = to_delete->next;
	QueueDestroy(to_delete);
	return;
}


// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	if (NULL == q || q->front->next == NULL)
	{
		return false;
	}

	return q->front->next->data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	QNode* queNode = NULL;
	int len = 0;
	if (QueueEmpty(q))
	{
		printf("��ʽ����Ϊ��");
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

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{

	if (q->front == q->rear)
		return 1;
	else
		return 0;
}


// ���ٶ��� 
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
