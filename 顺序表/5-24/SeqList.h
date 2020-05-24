#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

enum Option
{
	Exit,
	PushBack, 
	PushFront, 
	PopBack ,
	PopFront ,
	Find,
    Print ,
};

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);

int SeqListFind(SeqList* ps, SLDateType x);
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
void SeqListErase(SeqList* ps, size_t pos);