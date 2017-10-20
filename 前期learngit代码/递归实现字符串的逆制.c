#include<stdio.h>
#include<string.h>
#include<assert.h>
//char* reverse(char* start,/*char* end,*/int len)
//{
//	static i = 0;
//	static j = 0;
//	j = len-1;
//	assert(start);
//	//assert(end);
//  start[i] ^= start[j];
//	start[j] ^= start[i];
//	start[i] ^= start[j];
//	printf("%s\n",start);
//	//printf("%s\n",end);
//	printf("\n");
//	i++;
//	j--;
//	if(i<j)
//	return reverse(start,len);
//	
//} 
void reverse(char* start,char* end)
{
	assert(start);
	assert(end);
	*start^=*end;
	*end^=*start;
	*start^=*end;
	start++;
	end--;
	if(start<end)
    return reverse(start,end);
}
int main()
{
	char arr[] = "abcdefghijk";
	char *ps = arr;
	char *pe = arr + strlen(arr) - 1;
	reverse(ps,pe);
    printf("逆制后的结果：%s",arr);
	return 0;
}