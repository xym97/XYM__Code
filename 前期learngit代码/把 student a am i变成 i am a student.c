//
//#include<stdio.h>
//#include<string.h>
//void fun(char* a,char* b)
//{
//    int i,j,k=0;
//    for(i=strlen(a)-1;i>strlen("student");i--)
//    {
//        if(a[i]==' ')
//        {
//            for(j=i+1;a[j]&&a[j]!=' ';j++)
//            {
//                b[k++] = a[j];
//            }
//            b[k++] = ' ';
//        }
//    }
//    for(i=0;a[i]!=' ';i++)
//        b[k++] = a[i];
//    b[k] = '\0';
//}
//int main()
//{
//    char a[20]="student a am i",b[20];
//    fun(a,b);
//    printf("%s",b);
//	return 0;
//}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
void reverse(char* left,char* right)
{

    char tmp = 0;
	assert(left);
	assert(right);
	while(left<=right){
	   tmp = *left;
	   *left = *right;
	   *right = tmp;
	   left++;right--;
	}
}
char* Shift_arr(char* ps,char* pe,int _len)
{
   char* pos = ps;
   char* poss = ps;
   for(;ps<=poss+_len-1;ps++)
   {
	   if(*ps==' ' || *ps=='\0'){
        reverse(pos,ps-1);
		pos = ps+1;
	   }
   }
   reverse(poss,pe);
   return poss;
}
int main()
{
    char arr[] = "student a am i";
    char* pend = arr + strlen(arr)-1;
	int len = strlen(arr);
	char* ret = NULL;
	//char* Shift_arr(char* ps,char* pe,int _len);
	ret = Shift_arr(arr,pend,len);
	printf("After Shift:%s",ret);
	system("pause");
	return 0;
}





















