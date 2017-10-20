#include <stdio.h>
#include <windows.h>

void *main_ret = NULL;

void bug()
{
	int flag = 0;
	int*p = &flag;
	p += 4;
	printf("haha, I am a little bug!!\n");
	Sleep(5000);
	*p = main_ret;
	printf("begin return to main from bug!\n"); 
	Sleep(5000);
}

int fun(int x, int y)
{
	int c = 0xcccccccc;
	int *p = &x;
	printf("I am fun function!\n");
	p--;
	main_ret = *p;
	*p = (int)bug;
	//p++;
	//printf("before: %x\n", y);
	//*p = 0xdddddddd;
	//printf("after : %x\n", y);

	return c;
}

int main()
{
	int a = 0xaaaaaaaa;
	int b = 0xbbbbbbbb;
	int ret = fun(a, b);
	//Æ½ºâÕ»Ö¡½á¹¹ push->1, pop->2
	_asm{
		sub esp, 4
	}
	printf("you should running here!\n");
	system("pause");
	return 0;
}

//#include<stdio.h>
//#include<windows.h>
//int fun(int x,int y)
//{
//	int *p = &x;
//	p++;
//	printf("Before b value :%x\n",*p);
//    *p = 0xcccccccc;
//	return *p;
//}
//int main()
//{
//	int a = 0xaaaaaaaa;
//	int b = 0xbbbbbbbb;
//	int ret = fun(a,b);
//	printf("After b value :%x",ret);
//	system("pause");
//	return 0;
//}