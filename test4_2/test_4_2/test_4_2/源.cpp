#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int chek_syc(void)
{
	int a = 1;
	char* p = (char*)&a;//ǿ������ת��Ϊchar*,ʹָ��p����һ���ַ�
	return *p;//����1��ʾС��,����0��ʾ���
}
int main()
{
	
	if (chek_syc() == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}