#include <stdio.h>
#include <assert.h>
#include <windows.h>

//#pragma warning(disable:4996)
//
//void mut_table(int lines)
//{
//	int i = 1;
//	assert(lines > 0);
//	for (; i <= lines; i++ ){
//		int j = 1;
//		for (; j <= i; j++){
//			printf("%d*%d=%d ", i, j, i*j);
//		}
//		printf("\n");
//	}
//
//	printf("\n");
//}
//
//int main()
//{
//	int lines = 0;
//	printf("Please Enter line: ");
//	scanf("%d", &lines);
//	mut_table(lines);
//	system("pause");
//	return 0;
//}

void my_replace(char *arr, int cap)
{
	int old_len = 0;
	int space_nums = 0;
	char *start = arr;
	assert(arr);
	assert(cap > 0);

	
	while (*start != '\0'){//"we are happy.\0"     ....[]
		if (isspace(*start)){
			space_nums++;
		}
		old_len++, start++;
	}
	int new_len = old_len + space_nums*2+1; 
	//"a a"->a%20a\0
	char* end = arr + new_len-1;
	while (start >= arr){
		if (isspace(*start)){
			*end-- = '0';
			*end-- = '2';
			*end = '%';
		}
		else{
			*end = *start;

		}
		start--, end--;
	}
}

int main()
{
	char arr[64] = "we are happy.";
	my_replace(arr, sizeof(arr)/sizeof(arr[0]));
	printf("%s\n", arr);
	system("pause");
	return 0;
}
void str_switch(char *start, char *end)
{
	assert(start);
	assert(end);

	while (start < end){
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
		start++, end--;
	}
}
//int main()
//{
//	char arr[] = "student a am i";
//	char *p = arr;
//	char *q = p;
//	while (*p != '\0'){
//		if (isspace(*p)){
//			str_switch(q, p-1);
//			q = p + 1;
//		}
//		p++;
//	}
//	str_switch(q, p-1);
//	str_switch(arr, arr+strlen(arr)-1);
//	printf("res : %s\n", arr);
//	system("pause");
//	return 0;
//}
////4 dst <- src
////char *my_strcpy(char *dst, char *src)
////{
////	assert(dst);
////	assert(src);
////	while (*dst++ = *src++);
////	//int i = 0;
////	//int len = strlen(src);
////	//while (i < len ){
////	//	dst[i] = src[i];
////	//	i++;
////	//}
////
////	//dst[i] = '\0';
////}
//
//int my_strlen(char *str)
//{
//	assert(str);
//	//"abcd" -> 1+"bcd"->1+1+"cd".. 1+1+1.+1
//	if (*str == '\0'){
//		return 0;
//	}
//
//	return 1 + my_strlen(str+1);
//
//	//assert(str);
//	//char *end = str;
//	//while ( *end != '\0'){
//	//	end++;
//	//}
//
//	//return end - str;
//	//int count = 0;
//	//while ( *str != '\0'){
//	//	count++;
//	//	str++;
//	//}
//	//return count;
//}
//
//int main()
//{
//	char *msg = "hello bit & world";
//	printf("strlen : %d\n", my_strlen(msg));
//	/*char buf[32];
//	my_strcpy(buf, msg);
//	printf("res: %s\n", buf);*/
//	system("pause");
//	return 0;
//}

//3
//int find_single(int arr[],int len)
//{
//	//assert(NULL != arr);
//	assert(arr);
//	assert(len > 0);
//
//	int res = arr[0];
//	int i = 1;
//	for (; i < len; i++){
//		res ^= arr[i];
//	}
//	return res;
//}
////3
//int main()
//{
//	int arr[] = {1,2,3,4,5,6,7,1111,7,6,5,4,3,2,1, 56,56};
//	
//	int single = find_single(arr, sizeof(arr)/sizeof(arr[0]));
//	printf("I am single:( : %d\n", single);
//	system("pause");
//	return 0;
//}

////2
////void reverse_bits(unsigned int data)
////{
////	int arr[32];
////	int i = 0;
////	for (; i < 32; i++){
////		if (data & 1){//
////			arr[i] = 1;
////		}
////		else{
////			arr[i] = 0;
////		}
////		data >>= 1;
////	}
////	for (i = 0; i < 32; i++){
////		printf("%d ", arr[i]);
////	}
////	printf("\n");
////}
//
//unsigned int reverse_bits(unsigned int x)
//{
//	// 0000001010 i
//	// 0000000000 | 1<<? j = 31
//	int i = 0;
//	int j = 31;
//	unsigned int tmp = 0;
//	for (; i < 32 && j >= 0;i++, j--){
//		if ( x & (1<<i)){
//			tmp |= (1 << j);
//		}
//	}
//	return tmp;
//}
//
//int main()
//{
//	//110100111
//	printf("Please Enter: ");
//
//	unsigned int data = 10;
//	scanf("%u", &data);
//	unsigned int res = reverse_bits(data);
//
//	printf("resust : %u\n", res);
//
//	//show(data);
//	//reverse_bits(data);
//	//show(data);
//	system("pause");
//	return 0;
//}

//1
//int data_diffs(int x, int y)
//{
//	int tmp = x ^ y;
//	int count = 0;
//	while (tmp){
//		count++;
//		tmp &= (tmp - 1);//
//	}
//
//	return count;
//}
//
//int main()
//{
//	printf("Please Enter<a, b>: ");
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int diffs = data_diffs(a, b);
//	printf("diff bits: %d\n", diffs);
//	system("pause");
//	return 0;
//}

//int main()
//{
//	system("pause");
//	return 0;
//}
