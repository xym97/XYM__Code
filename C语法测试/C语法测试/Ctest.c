#include<stdio.h>
#include<stdlib.h>

int main()
{

	const int a = 3;
	int x = 9;
    int* p = &a;
	p = NULL;
	*p = x;
	printf("%d", a);
	system("pause");
	//int arr[a] = { 1, 2, 3 };
	return 0;
}
