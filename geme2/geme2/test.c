#define _CRT_SECURE_NO_WARNINGS 1
#include"geme.h"
void mene()
{
	printf("*************************\n");
	printf("****1.play   0.exit******\n");
	printf("*************************\n");

}
void geme()
{
	srand((unsigned int)time(NULL));
	//1.���ú��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//2.�Ų���׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ������
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//��ӡ����
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//������
	stemine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//ɨ��
	findmine(mine,show, ROW, COL);


}
void test()
{
	do
	{
		int i = 0;
		mene();
		printf("������>:");
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			geme();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�Ƿ����룬����������\n");
			break;
		}


	} while (1);
	
	
}
int main()
{
	test();

	return 0;
}