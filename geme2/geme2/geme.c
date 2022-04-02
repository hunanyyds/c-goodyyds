#define _CRT_SECURE_NO_WARNINGS 1
#include"geme.h"
void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	for (i = 0; i < ROWS; i++)
	{
		int j = 0;
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}
void displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("0 ");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (j = 1; j <= col; j++)
	{
		printf("%d ",j);
		for (i = 1; i <= row; i++)
		{
				printf("%c ", board[i][j]);
		}
		printf("\n");
	}

}
void stemine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 10;//雷的个数
	while (i)
	{
		x = rand() % ROW+1;
		y = rand() % COL+1;
		if (board[x][y] != '1')
		{
			board[x][y] = '1';
			i--;
		}
	}
}
char get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y - 1] +
		mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] +
		mine[x + 1][y] +
		mine[x + 1][y - 1] + 8 * '0';

}
void unfold(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y,int i)//展开函数
{
	char count = get_mine_count(mine, x, y);
	if (count==0)
	{
		show[x][y] = ' ';
		i++;
		if (x >= 1 && x <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x][y - 1] == '*')
		{
			unfold(mine, show, x, y - 1, i);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y-1 >= 1 && y-1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x - 1, y+1, i);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y >= 1 && y <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x - 1, y, i);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x - 1, y + 1, i);
		}
		if (x >= 1 && x <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x, y + 1, i);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x + 1, y + 1, i);
		}
		if (x >= 1 && x <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x, y + 1, i);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x][y] == '*')
		{
			unfold(mine, show, x + 1, y - 1, i);
		}

	}
	else
	{
		show[x][y] = get_mine_count(mine,x,y) + '0';
	}
}



void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0;
	while (1)
	{
		printf("请输入你需要扫雷的坐标， 列 空格 行>:");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("你被雷炸死了\n");
				displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				char count=get_mine_count(mine, x, y);
				show[x][y] = count + '0';
				if (show[x][y]== '0')
				{
					unfold(mine, show, x, y, i);//展开不是雷
					displayboard(show, ROW, COL);
				}
				else
				{
					i++;
					displayboard(show, ROW, COL);

				}
				if (i == 71)
				{
					break;
				}
				
			}
		}
		else
		{
			printf("非法输入");
		}
	}
	if (i == 71)
	{
		printf("你赢了\n");
		displayboard(mine, ROW, COL);
	}
}
