#define _CRT_SECURE_NO_WARNINGS  1
#include"contact.h"
void initcontact(contact* pcon)
{
	pcon->data = (Peoinfo *)malloc(DEFAULT_SZ*sizeof(Peoinfo));
	if (pcon->data == NULL)
	{
		return;
	}
	pcon->sz = 0;
	pcon->capacity = DEFAULT_SZ;
}
void checkcapacity(contact* pcon)
{
	if (pcon->sz == pcon->capacity)
	{
		Peoinfo* ptr = realloc(pcon->data, (pcon->capacity * 2)*sizeof(Peoinfo));
		if (ptr != NULL)
		{
			pcon->data = ptr;
			pcon->capacity *= 2;
			printf("增容成功\n");
		}
		else
		{
			printf("增容失败\n");
		}
	}
}

void addcontact(contact* pcon)
{
	checkcapacity(pcon);
	assert(pcon);
	printf("请输入名字:>");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &(pcon->data[pcon->sz].age));
	printf("请输入性别:>");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pcon->data[pcon->sz].addr);
	
	pcon->sz++;
	printf("增加成功\n");
}

static int findbyname(contact* pcon, char name[])
{
	int i = 0;
	assert(pcon);
	for (i = 0; i < pcon->sz; i++)
	{
		if (0 == strcmp(pcon->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void delcontact(contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);
	if (pcon->sz == 0)
	{
		printf("空通讯录，无法删除\n");
		return;
	}
	printf("请输入要删除的姓名：");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("要删除的条目不在\n");
		return;
	}
	for (i = pos; i < pcon->sz; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->sz--;
	printf("删除成功\n");
}

void findcontact(contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);
	if (pcon->sz == 0)
	{
		printf("空通讯录，无法删除\n");
		return;
	}
	printf("请输入要删除的姓名：");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("要删除的条目不在\n");
		return;
	}
	printf("%15s\t%5d\t%5s\t%12s\t%20s\n",
		pcon->data[pos].name,
		pcon->data[pos].age,
		pcon->data[pos].sex,
		pcon->data[pos].tele,
		pcon->data[pos].addr);
}

void modifycontact(contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);
	if (pcon->sz == 0)
	{
		printf("空通讯录，无法修改\n");
		return;
	}
	printf("请输入要修改的姓名：");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("要修改的条目不在\n");
		return;
	}
	printf("请输入要修改的信息（1-姓名，2-年龄，3-性别， 4-电话， 5-地址）");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入要新的姓名：");
		scanf("%s", pcon->data[pos].name);
		break;
	case 2:
		printf("请输入要新的年龄：");
		scanf("%s", pcon->data[pos].age);
		break;
	case 3:
		printf("请输入要新的性别：");
		scanf("%s", pcon->data[pos].sex);
		break;
	case 4:
		printf("请输入要新的电话：");
		scanf("%s", pcon->data[pos].tele);
		break;
	case 5:
		printf("请输入要新的地址：");
		scanf("%s", pcon->data[pos].addr);
		break;
	default:
		printf("输入有误，修改失败\n");
		return;
	}
	printf("修改成功\n");
}

void showcontact(const contact* pcon)
{
	int i = 0;
	assert(pcon);
	printf("%15s\t%5s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%15s\t%5d\t%5s\t%12s\t%20s\n", pcon->data[i].name,
			pcon->data[i].age,
			pcon->data[i].sex,
			pcon->data[i].tele,
			pcon->data[i].addr);
	}
}


void clearcontact(contact* pcon)
{
	initcontact(pcon);
}

void sortcontact(contact* pcon)
{
	int i, j;
	Peoinfo tmp;
	for (i = 0; i < pcon->sz - 1; i++)
	{
		for (j = 0; j < pcon->sz - 1 - i; j++)
		{
			if (0 < strcmp(pcon->data[j].name, pcon->data[j + 1].name))
			{
				tmp = pcon->data[j];
				pcon->data[j] = pcon->data[j + 1];
				pcon->data[j + 1] = tmp;
			}
		}
	}
}


void destroycontact(contact* pcon)
{
	free(pcon->data);
	pcon->data = NULL;
	pcon->capacity = 0;
	pcon->sz = 0;
}