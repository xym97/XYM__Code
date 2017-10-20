#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char c[25] = "we are happy";
    int space_num = 2;

	int pos = strlen(c);
    int new_pos = pos + (2 * space_num);
	
     while(pos >= 0)
    {
        if(c[pos] == ' ')
        {
            c[new_pos--] = '0';
            c[new_pos--] = '2';
            c[new_pos--] = '%';
            pos--;
        }
        else
        {
            c[new_pos--] = c[pos--];
        }
    }
    printf("%s\n", c);
    return 0;
}