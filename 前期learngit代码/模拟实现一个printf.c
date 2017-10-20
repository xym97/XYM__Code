#include<stdio.h>
//#include<stdlib.h>
//#include<stdarg.h>
#include<windows.h>
#include<assert.h>
static void MyPutInt(int _int)
{
	int a = _int/10;
	if(a!=0){
	    MyPutInt(a);
	}
	putchar(_int%10 + '0');
}
//static void MyPutInt(int a)
//{
//	int prev = a / 10;
//	if ( prev != 0 ){
//		MyPutInt(prev);
//	}
//	putchar(a % 10 + '0');
//}
int my_printf(const char* format,...)
{
    const char *start = format;
	va_list arg_list;
	va_start(arg_list,format);
	assert(format);
	while(*start != '\0'){
		if(*start == '%'){
			start++;
			switch (*start){
			   case 'd':
				   {
				       int _int = va_arg(arg_list,int);
					   MyPutInt(_int);
				   }
				        break;
			   case 'c':
				   {
					   char _char = va_arg(arg_list,char);
					   putchar(_char);
				   }
				        break;
			   case 's':
				   {
				       char* _string = va_arg(arg_list,char*);
					   while(*_string)
					   { 
                           putchar(*_string++);
					   }
				   }
				       break;
			   case 'f':
				   {
					   double _double = va_arg(arg_list,double);
				   }
			   default :
				   {
				   }
				       break;
			}
		}
		else
		{
			putchar(*start);
		}
	    start++;
	}
	va_end(arg_list);
	return 0;
}

int main()
{
	int a = 100;
    char* msg = "aaaaaaaaa";
	char* c = 'm';
	my_printf("hello_bit :%d,hello_world:%s,hello_worldbit: %c",a,msg,c);
	system("pause");
    return 0;
}