#pragma once 

typedef int QDataType;
// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

// ��ʼ������ 
int QueueInit(Queue* q);
// ��β����� 
int QueuePush(Queue* q, QDataType data);
// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ��� 
void QueueDestroy(Queue* q);