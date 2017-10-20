#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>




//int main()
//{
//	char* str1 = "hello_bit";
//	char* str2 = "ll";                                   //include src and behind
//	char* my_strstr(char* dest,char* src);               //oi  _bit
//	char* ret = my_strstr(str1, str2);                   //o   ello_bit
//	printf("mystrstr result is:%s",ret);                 //o_  o_bit
//	system("pause");
//	return 0;
//}
//
//char* my_strstr(char* dest,char* src)
//{   
//    
//	char* s1 = dest;
//	char* s2 = src;
//	assert(dest);assert(src);
//    while(*s1)
//	//while(*dest)
//   {
//	s1 = dest;
//	s2 = src;
//	while((*s1!='\0')&&(*s2!='\0'))
//	 // while((*dest!='\0')&&(*src!='\0'))
//	{
//        
//		if(*s1++ == *s2++)
//		//if(*dest++ == *src++)
//		{
//			;
//		}
//		else
//		{
//			dest++;
//			break;
//		}
//	}
//	if(*s2=='\0')
//	//if(*src=='\0')
//	{
//		return dest;
//		//return s1
//	}
//	
//  }
//	return NULL;
//}

//char* my_strstr(char* dest,char* src)
//{   
//    
//	//char* s1 = dest;
//	//char* s2 = src;
//	assert(dest);assert(src);
//    //while(*s1)
//	while(*dest)
//   {
//	//s1 = dest;
//	//s2 = src;
//	//while((*s1!='\0')&&(*s2!='\0'))                // not include src only behind
//    while((*dest!='\0')&&(*src!='\0'))
//	{
//        
//		//if(*s1++ == *s2++)
//		if(*dest++ == *src++)
//		{
//			;
//		}
//		else
//		{
//			dest++;
//			break;
//		}
//	}
//	//if(*s2=='\0')
//	if(*src=='\0')
//	{
//		return dest;
//		//return s1
//	}
//	
//  }
//	return NULL;
//}
char* my_strstr(const char* dststr,const char* substr)
{
     const char* dst_start = dststr;
	 const char* sub_start = substr;
	 const char* dst_end = dst_start + strlen(dststr) - strlen(substr);
	 assert(dststr);assert(substr);
	 if(strlen(dst_start)<strlen(sub_start)){
           return NULL;
	 }
	 while(dst_start <= dst_end){
		 char* pos = dst_start;
		 while(*sub_start!='\0'&& *dst_start==*sub_start){
              dst_start++;
			  sub_start++;
		 }
		 if(*sub_start == '\0'){
			 return pos;
		 }
		 else{
		   dst_start = pos + 1;
		   sub_start = substr;
		 }
	 }
	 return NULL;
}

int main()
{
	printf("%s\n",my_strstr("abdcfhello984","hello"));
	system("pause");
	return 0;
}


