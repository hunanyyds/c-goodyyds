#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"game.h"
void menu()
{
	printf("**********************\n");
	printf("***1.play   0.exit****\n");
	printf("**********************\n");

}
void game()
{
	char ret = ' ';
	char board[ROW][COL] = { 0 };
	srand((unsigned int)time(NULL));
	initboard(board, ROW, COL);//��ʼ��board���������
	displayboard(board,ROW,COL);//��ӡ�������������
	while (1)
	{
		//�������
		piayermove(board, ROW, COL);
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("��Ӯ�ˣ���ϲ��\n");
			break;
		}
		else if (ret == '#')
		{
			printf("�������Զ��治������������\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		else
		{
		
		}

		displayboard(board, ROW, COL);
		//�ж���Ӯ
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("��Ӯ�ˣ���ϲ��\n");
			break;
		}
		else if (ret == '#')
		{
			printf("�������Զ��治������������\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		else
		{
			
		}


        //��������
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("��Ӯ�ˣ���ϲ��\n");
			break;
		}
		else if (ret == '#')
		{
			printf("�������Զ��治������������\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("ƽ��\n");
			break;
		}
		else
		{
			
		}
	
	}

}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("������>:");
		scanf("%d", &input);
		switch (input)
		{
		   case 1:
			   game();
			break;

		   case 0:

			printf("�˳���Ϸ\n");
			break;

		   default:
			   printf("�Ƿ����룬���������룡\n");
			   break;
		}
	} while (input);

}


int main()
{
	test();

	return 0;
}