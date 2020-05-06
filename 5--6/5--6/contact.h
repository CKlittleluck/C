#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

enum Option
{
	Exit,
	add,
	del,
	search,
	modify,
	show,
	clear,
	sort,
};

#define DEFAULT_SZ 3
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 25

typedef struct Peoinfo
{
	char name[NAME_MAX];
	short age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}Peoinfo;

typedef struct contact
{
	Peoinfo data[MAX];
	int sz;
}contact;

void initcontact(contact* pcon);
void addcontact(contact* pcon);
void delcontact(contact* pcon);
void findcontact(contact* pcon);
void modifycontact(contact* pcon);
void showcontact(const contact* pcon);
void clearcontact(contact* pcon);
void sortcontact(contact* pcon);