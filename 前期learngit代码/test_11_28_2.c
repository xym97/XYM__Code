#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int mydiv(int a, int b)
{
	if(b == 0){
		printf("your proc is diving zero!!\n");
		return -1;
	}
	return a / b;
}

int quit(int a, int b)
{
	printf("Bye~~\n");
	exit(0);
}

int help(int a, int b)
{
	printf("Usage: use option [0, 1, 2, 3, 4, 5]\n");
	return 0;
}

int main()
{
//	int (*p[6])(int,int) = {help, add, sub, mul, mydiv, quit};
	int (*p[6])(int,int);
	int (*(*q)[6])(int, int);
	q = &p;
	printf("%p, %p\n", q, q+1);
	p[0]=&help;
	while(1){
	    printf("########################################\n");
	    printf("### 1. add ################# 2. sub ####\n");
	    printf("### 3. mul ################# 4. div ####\n");
	    printf("### 5. quit ################ 0. help ###\n");
	    printf("########################################\n");

	    int s = 0;
	    printf("Please Select<0~5>: ");
	    scanf("%d", &s);
	    if( s < 0 || s > 5 ){
	    	s = 5;
	    }

        int x, y;
	    if( s != 0 && s != 5 ){
        	printf("Please Enter Your data<x, y>: ");
        	scanf("%d%d", &x, &y);
	    }
	    printf("result> %d\n", p[s](x, y));
	}
	return 0;
}
