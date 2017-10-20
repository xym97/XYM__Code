#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<assert.h>
int main()
{
	/*char* src = "xzuidiao";
	char dst[20] = "0";*/
	int src[] = {1,2,3,4,5,6};
	int dst[20] = {0};
	//int len = strlen(src);
	int charnum = sizeof(src);
	int i = 0;
	char* ret = NULL;
	void* my_memcpy(void* src,const void* dst,int charnum);
	ret = my_memcpy(src,dst,charnum);
	/*printf("DST is %s",ret);*/
	for(i=0;i<6;i++)
		printf("%d",dst[i]);
	system("pause");
	return 0;
}
void* my_memcpy(const void* src,void* dst,int charnum)
{
	void* ret = dst;
	assert(src);
	assert(dst);
//#ifndef DEGUG
//	if(NULL==dst||NULL==src){
//		return dst;
//	}
//#endif
	while(charnum--){
        *(char*)dst = *(char*)src;
		src = (char*)src + 1;
		dst = (char*)dst + 1;
	}
    return ret;
}
