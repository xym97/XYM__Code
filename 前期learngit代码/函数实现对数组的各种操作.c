//init
//empty
//reverse
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void Init(int *,int len);
void Empty(int *,int len);
void Reverse(int * arr,int len);


int main()
{
	int len,n ,i;
	int arr[10];
	len = sizeof(arr)/sizeof(arr[0]);
 while(1)
{
printf("«Î ‰»Î£∫\n");
scanf("%d",&n);
switch(n)
  {
case 1:Init(arr,len);break;
case 2:Reverse(arr,len);break;
case 3:Empty(arr,len);break;
default:printf("error");
	
   }
for(i=0;i<len;i++)
	printf("%d ",arr[i]);
	
}
return 0;
}
	
	
	//   Init(arr,len);
	////Empty(arr,len);
	//Reverse(arr,len);
 //   for(i=0;i<len;i++)
	//{
	//printf("%d",arr[i]);
	//}



void Init(int* arr,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
     arr[i] = i;

	}
	
}

void Empty(int* arr,int len)
{
   int i;
   for(i=0;i<len;i++)
   {
     arr[i] = 0; 

   }

}

void Reverse(int *arr,int len)
{ 
  int i;
  int arr2[10];
  for(i=0;i<len;i++)
  {

   arr2[i] = arr[i];
  }
  for(i=0;i<len;i++)
  {
   arr[i] = arr2[len-i-1];
  }
  
}