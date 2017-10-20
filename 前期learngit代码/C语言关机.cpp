#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char input[10];
	system("shutdown -s -t 10");
flag:
	printf("输入：不关机。不然就关机\n");
	scanf("%s",input);
	if(strcmp(input,"不关机")==0)
	{
		system("shutdown -a");
	}
	else
	{
		goto flag;
	}
	return 0;

}
