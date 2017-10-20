//#define _CRT_SECURE_NO_WARNINGS.
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//   char str[15] = "ABCDEFG";
//   
//   char* leftspin_str(char* str);
//   char* str2 = NULL;
//   printf("before spin %s\n",str);
//   str2 = leftspin_str(str);
//   
//   printf("After spin :%s",str2);
//   return 0;
//}
// char* leftspin_str(char* str)
// {
//	 char* p = str+strlen(str)-1;
//	 char* q = p;
//	
//	 int a = 0;
//	 printf("%p",q);
//	 printf("%p\n",str);
//	 printf("%p",p);
//	 printf("Pliease Enter How Much Character:\n");
//	 scanf("%d",&a);
//	 str--;
//	 while(a--)
//	 {
//	 *p++ = *str++;
//	 
//	 }
//	 
//	 *p = '\0';
//	 printf("p: %s\n",q);
//	 return p;
// }

#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#include <string.h> 
#include<stdlib.h>
void reserve(char *left,char*right)  
{  
    while (left <= right)  
    {  
        char tmp = *left;  
        *left = *right;  
        *right = tmp;  
        left++;  
        right--;  
    }  
}  
int main()  
{  
    char arr[10] = "ABCDEFG";
    int n = 0;  
    char *ps = arr;  
    char *pe = arr+strlen(arr)-1;  
	printf("Before string is:%s\n",arr);
    
    scanf("%d", &n);  
    reserve(ps, ps + n -1);  
    reserve(ps + n, pe);  
    reserve(ps, pe);  
    printf("After string is%s\n", arr);  
    system("pause");  
    return 0;  
}  

