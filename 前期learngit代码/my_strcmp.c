#include<stdio.h>
#include<string.h>
#define assert
//int main()
//{   
//	char dest[12];
//	char src[] = "hello_bit";
//	int i = 0;
//	void my_strcmp(char* dest ,const char* src);
//	my_strcmp(dest,src);
//	printf("dest被cmp成了：%s",dest);
//	return 0;
//}
//
//  void my_strcmp(char* dest ,const char* src)
// {
//    assert(dest!=NULL);
//	assert(src!= NULL);
//	/*while(*src!='\0')
//	{
//       *dest = *src;
//	   dest++;
//	   src++;
//	}*/
//	while(*dest++ = *src++)
//	{
//         ;
//	}
//	//*dest = '\0';
// }
 int main()
{   
	char dest[12];
	char src[] = "hello_bit";
	int i = 0;
	int n = 5;
	void my_strncmp(char* dest ,const char* src,int n);
	my_strncmp(dest,src,n);
	printf("dest被cmp成了：%s",dest);
	return 0;
}

  void my_strncmp(char* dest ,const char* src,int n)
 {
    assert(dest!=NULL);
	assert(src!= NULL);
	/*while(*src!='\0'&&n--)
	{
       *dest = *src;
	   dest++;
	   src++;
	}*/
	while((*dest++ = *src++)&&--n)
	{
         ;
	}
	*dest = '\0';
 }