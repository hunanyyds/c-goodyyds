#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include<time.h>
#include<stdlib.h>
char tie(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; i++)
		{
			if (board[i][j] != ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i< row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	printf("+---+---+---+\n");
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf("| %c | %c | %c |\n", board[i][0],board[i][1],board[i][2]);
		printf("+---+---+---+\n");
	}
}
void piayermove(char board[ROW][COL], int row, int col)
{
	while (1)
	{
		int i = 0;
		int j = 0;
		printf("玩家下棋,(行 空格 列)>:");
		scanf("%d %d", &i, &j);
		if (i >= 1&& i <=ROW  && j >= 1 && j <= COL)
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
		     }
	
			else
			{
				printf("该棋盘也被占用！");
				continue;
			}
		}
		else
		{
			printf("非法输入！\n");
			continue;
		}
	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");
	int i = 0;
	int j = 0;
	while (1)
	{
		i = rand() % ROW;
		j = rand() % COL;
		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
		else
		{
			continue;
		}

	}
}
char lswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2]==board[i][1] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	for (j = 0; j < 3; j++)
	{
		if (board[0][j] == board[1][j] && board[0][j] == board[2][j] && board[0][j] != ' ')
		{
			return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != ' ')
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[2][0] == board[1][1] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (tie(board, ROW, COL) == 1)//返回1表示平局
	{
		return 'Q';
	}
	return 'C';
}