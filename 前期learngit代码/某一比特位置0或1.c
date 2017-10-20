#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#pragma warning (disable:4996)

void bit_set(unsigned char *p_data,unsigned char pos,int flag)
{
    assert(p_data);
	if(pos >= 1 && pos <= 8){
		if(1 == flag){
            *p_data |= (1 << (pos - 1));		
		}
		else{
		    *p_data &= (~(1 << (pos - 1)));
		}
		
	}
	else
		printf("positon error\n");
}

int main()
{
	unsigned char a = 0;
	unsigned char position = 0;
	int flag = 0;
	printf("Please Enter A Digit,Position,1 or 0£º\n");
	scanf("%d %d %d",&a,&position,&flag);
    bit_set(&a,position,flag);
	printf("%u",a);
	system("pause");
	return 0;
}