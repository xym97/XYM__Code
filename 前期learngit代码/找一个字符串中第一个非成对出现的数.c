////#include<stdio.h>
////#include<windows.h>
////int main()
////{
////	char *p = "arijisradjdyyxmmc";
////    
////    system("pause");
////	return 0;
////}
//#include <stdio.h>  
//#include <string.h>  
//  
//int main()  
//{  
//    char ch[100];  
//    int arr[100];  
//    int i,j,len;  
//    while(scanf("%s",ch)!=EOF){  
//        len=strlen(ch);  
//        for(i=0;i<len;i++){  
//            arr[i]=1;  
//        }  
//        for(i=0;i<len;i++){  
//            for(j=i+1;j<len;j++){  
//                if(ch[i]==ch[j]){  
//                    arr[i]=0;  
//                    arr[j]=0;  
//                }  
//            }  
//        }  
//        for(i=0;i<len;i++){  
//            if(arr[i]){  
//                break;  
//            }  
//        }  
//        if(i>=len){  
//            printf(".\n");  
//        }else{  
//            printf("%c\n",ch[i]);  
//        }  
//    }  
//    return 0;  
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
unsigned int FindFirstOnly(const char* p)
{
	int count[256] = {0};
	char *start = p;
	memset(count,0,256*sizeof(int));
	while(*start!='\0'){
       count[(int)*start]++;
	   start++;
	}
	start = p;
	while(*start != 0){
		if(1==count[(int)*start]){
		return *start;
	}
     start++;
	}
	return 0;
}

int main()
{
    char* masg = "asgxsgaxiioopplnwgtfcglnft";
	int ret = FindFirstOnly(masg);
	if(ret!=0)
    printf("%c",(char)ret);
	else
	printf("No Number");
	system("pause");
	return 0;
}