//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<malloc.h>

	enum ShapeType {CIRCLE, SQUARE};  
	  
	//虚函数表里的两个函数，calculate也是意思一下，无意义  
	typedef void (*show)();  
	typedef double (*calculate)(int arg);  
	  
	//虚函数表结构体  
	typedef struct _VirtualFun  
	{  
	    show      showShape;   
	    calculate calArea;  
	} VirtualFun,*pVirtualFun;  
	  
	//基类，Shape  
	typedef struct _Shape  
	{  
	    ShapeType type;  
	    VirtualFun *pfun;  
	}Shape,*ShapePointer;  
	  
	//派生类，Circle  
	typedef struct _Circle  
	{  
	    Shape itsType;  
	    int r;  
	}Circle;  
	  
	//派生类，Square  
    typedef struct _Square  
	{  
	    Shape itsType;  
	    int d;  
	}Square;  
	  
	//重写的虚函数  
	void showCircle()  
	{  
	    printf("I'm circle/n");  
	}  
	  
	//重写的虚函数  
	void showSquare()  
	{  
	    printf("I'm square/n");  
	}  
	  
	//circle初始化  
	Circle circle ={  
	    CIRCLE,  
	    (pVirtualFun)malloc(sizeof(VirtualFun)),  
	    0  
	};  
	  
	//square初始化  
	Square square ={  
	    SQUARE,  
	    (pVirtualFun)malloc(sizeof(VirtualFun)),  
	    0  
	};  
	  
	  
	//测验多态，只需要传递基类指针ShapePointer。  
	void virtualShow(ShapePointer sp)  
	{  
	    sp->pfun->showShape();  
	}  
	  
	void main()  
	{  
	    //虚函数初始化  
	    circle.itsType.pfun->showShape = showCircle;  
	    square.itsType.pfun->showShape = showSquare;  
	      
	    //用基类指针指向派生类  
	    ShapePointer spc = (ShapePointer)&circle;  
	    ShapePointer sps = (ShapePointer)&square;  
	      
	    //传递基类指针，体现多态。  
	    virtualShow(spc);  
	    virtualShow(sps);  
	    getchar();  
	} 
