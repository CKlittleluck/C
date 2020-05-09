#define _CRT_SECURE_NO_WARNINGS  1
#include"contact.h"

void initcontact(contact* pcon)
{
	assert(pcon);
	pcon->sz = 0;
	memset(pcon->data, 0, sizeof(pcon->data));
}
void addcontact(contact* pcon)
{
	assert(pcon);
	printf("���������֣�");
	scanf("%s", pcon->data[pcon->sz].name);
	printf("���������䣺");
	scanf("%d", &(pcon->data[pcon->sz].age));
	printf("�������Ա�");
	scanf("%s", pcon->data[pcon->sz].sex);
	printf("������绰��");
	scanf("%s", pcon->data[pcon->sz].tele);
	printf("�������ַ��");
	scanf("%s", pcon->data[pcon->sz].addr);
	pcon->sz++;
	printf("���ӳɹ�\n");
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
		printf("��ͨѶ¼���޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ����������");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ������Ŀ����\n");
		return;
	}
	for (i = pos; i < pcon->sz; i++)
	{
		pcon->data[i] = pcon->data[i + 1];
	}
	pcon->sz--;
	printf("ɾ���ɹ�\n");
}

void findcontact(contact* pcon)
{
	int i = 0;
	char name[NAME_MAX] = { 0 };
	int pos = 0;
	assert(pcon);
	if (pcon->sz == 0)
	{
		printf("��ͨѶ¼���޷�ɾ��\n");
		return;
	}
	printf("������Ҫɾ����������");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("Ҫɾ������Ŀ����\n");
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
		printf("��ͨѶ¼���޷��޸�\n");
		return;
	}
	printf("������Ҫ�޸ĵ�������");
	scanf("%s", name);
	pos = findbyname(pcon, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ���Ŀ����\n");
		return;
	}
	printf("������Ҫ�޸ĵ���Ϣ��1-������2-���䣬3-�Ա� 4-�绰�� 5-��ַ��");
	int msg;
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("������Ҫ�µ�������");
		scanf("%s", pcon->data[pos].name);
		break;
	case 2:
		printf("������Ҫ�µ����䣺");
		scanf("%s", pcon->data[pos].age);
		break;
	case 3:
		printf("������Ҫ�µ��Ա�");
		scanf("%s", pcon->data[pos].sex);
		break;
	case 4:
		printf("������Ҫ�µĵ绰��");
		scanf("%s", pcon->data[pos].tele);
		break;
	case 5:
		printf("������Ҫ�µĵ�ַ��");
		scanf("%s", pcon->data[pos].addr);
		break;
	default:
		printf("���������޸�ʧ��\n");
		return;
	}
	printf("�޸ĳɹ�\n");
}

void showcontact(const contact* pcon)
{
	int i = 0;
	assert(pcon);
	printf("%15s\t%5s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (i = 0; i < pcon->sz; i++)
	{
		printf("%15s\t%5d\t%5s\t%12s\t%20s\n",pcon->data[i].name,
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