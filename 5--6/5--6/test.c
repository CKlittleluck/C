#define _CRT_SECURE_NO_WARNINGS  1
#include"contact.h"
void menu()
{
	printf("***************************************\n");
	printf("******1. add       2. del    **********\n");
	printf("******3. search    4. modify **********\n");
	printf("******5. show      6. clear  **********\n");
	printf("******7. sort      0. exit   **********\n");
}

int main()
{
	int input = 0;
	contact con;
	initcontact(&con);
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addcontact(&con);
			break;
		case del:
			delcontact(&con);
			break;
		case search:
			findcontact(&con);
			break;
		case sort:
			sortcontact(&con);
			break;
		case show:
			showcontact(&con);
			break;
		case clear:
			clearcontact(&con);
			break;
		case Exit:
			printf("退出程序\n");
			return 0;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);
	return 0;
}