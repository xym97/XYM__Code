#include<stdio.h>
#include<windows.h>
int power(int a,int b,int mul)
{
	mul*=a;
		b--;
	if(b!=0)
		return power(a,b,mul);
	else
		return mul;
}
int main()
{
	int a = 0;
	int b = 0;
	int mul = 1;
	int ret = 0;
	scanf("%d %d",&a,&b);
	ret = power(a,b,mul);
	printf("%d",ret);
	system("pause");
	return 0;
}