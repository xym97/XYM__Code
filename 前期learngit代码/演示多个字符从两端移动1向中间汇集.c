#include<stdio.h>
#include<windows.h>
int main()
{   
	int i;
	char arr1[] = "##############";
    char arr2[] = "Welcome to bit";
	int left = 0;
	int right = strlen(arr1)-1;
	while(left <= right)
	{
     //Sleep<1000>
	  arr1[left] = arr2[left];
      arr1[right] = arr2[right];
	  printf("%s\n",arr1);
	  right--;
	  left++;
	  
	}
	
	return 0;

}