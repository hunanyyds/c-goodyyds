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
	//1.布置好雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	initboard(mine, ROWS, COLS, '0');
	initboard(show, ROWS, COLS, '*');
	//打印棋盘
	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);
	//布置雷
	stemine(mine, ROW, COL);
	displayboard(mine, ROW, COL);
	//扫雷
	findmine(mine,show, ROW, COL);


}
void test()
{
	do
	{
		int i = 0;
		mene();
		printf("请输入>:");
		scanf("%d", &i);
		switch(i)
		{
		case 1:
			geme();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("非法输入，请重新输入\n");
			break;
		}


	} while (1);
	
	
}
int main()
{
	test();

	return 0;
}