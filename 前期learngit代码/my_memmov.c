#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void* my_memmov(void* dst,void* src,int count)
{
	char*_dst = (char*)dst;
	char*_src = (char*)src;
   	char* ret = src;
	assert(dst);
	assert(src);
	if(_dst>_src && _src+count>_dst){
		char* _dst_end = _dst+count-1;
		char* _src_end = _src+count-1;
		while(count--){
			*_dst_end-- = *_src_end--;
		}
      return ret;
	}
	else{
		while(count--){
		    *_dst++ = *_src++;
		}
		return ret;
	}
 
}
int main()
{
	char src[21] = "abcdefghi";
	//char dst[21] = src+5;
	int len = strlen(src);
    int ret = my_memmov(src+3,src,len+1) ; 
	printf("%s",ret);
	system("pause");
	return 0;
}

