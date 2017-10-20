#include<stdio.h>
#include<string.h>
char* str_reverse(char* str1)
{
	
	/*char* q = NULL;*/
	char arr[20];
	int count;
	int i = 0;
	count = strlen(str1);
	printf("%d",count);
	while(*++str1){;}
	printf("%d,%c",strlen(str1),str1[-2]);
	str1--;
	
	printf("%c\n",*str1);
	for(i=0;i<count;i++)
	{
		arr[i] = *str1--;
	}

	
	return arr;


}





int main()
{
    char* str1 = "hello_bit";
	char* str2;
	printf("Origin string:%s\n",str1);
	str2 = str_reverse(str1);
	printf("After reversed string is:%s",str2);
   	return 0;
}
