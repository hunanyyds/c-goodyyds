#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int chek_syc(void)
{
	int a = 1;
	char* p = (char*)&a;//强制类型转换为char*,使指针p访问一个字符
	return *p;//返回1表示小端,返回0表示大端
}
int main()
{
	
	if (chek_syc() == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}