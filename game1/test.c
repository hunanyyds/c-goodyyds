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
	initboard(board, ROW, COL);//初始化board数组的内容
	displayboard(board,ROW,COL);//打印出三子棋的棋盘
	while (1)
	{
		//玩家下棋
		piayermove(board, ROW, COL);
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("你赢了，恭喜！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("你连电脑都玩不过，真垃圾！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		else
		{
		
		}

		displayboard(board, ROW, COL);
		//判断输赢
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("你赢了，恭喜！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("你连电脑都玩不过，真垃圾！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
			break;
		}
		else
		{
			
		}


        //电脑下棋
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = lswin(board, ROW, COL);
		if (ret == '*')
		{
			printf("你赢了，恭喜！\n");
			break;
		}
		else if (ret == '#')
		{
			printf("你连电脑都玩不过，真垃圾！\n");
			break;
		}
		else if (ret == 'Q')
		{
			printf("平局\n");
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
		printf("请输入>:");
		scanf("%d", &input);
		switch (input)
		{
		   case 1:
			   game();
			break;

		   case 0:

			printf("退出游戏\n");
			break;

		   default:
			   printf("非法输入，请重新输入！\n");
			   break;
		}
	} while (input);

}


int main()
{
	test();

	return 0;
}