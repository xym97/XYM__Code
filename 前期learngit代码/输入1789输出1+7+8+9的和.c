#include<stdio.h>
#include<windows.h>
int fun(int a,int ret)
{
	int value = 0;
   	ret+=(a%10);
	value = a/10;
       if(value!=0)
       return fun(value,ret);
  	   else
	   return ret;
}
int main()
{ 
    int a = 1789;
	int ret = 0;
	int b = 0;
	ret = fun(a,b);
	printf("%d",ret);
	system("pause");
	return 0;
}