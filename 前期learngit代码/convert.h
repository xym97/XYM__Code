#ifndef _CONVERT_H_
#define _CONVERT_H_

#pragma warning(disable:4996)

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

typedef enum STATUS{
	NORMAL_STATUS,
	C_STATUS,
	CPP_STATUS,
	END_STATUS,
}status_t;

extern status_t gStatus;

void convertBegin();
//convertStatusMachine(FILE* in,FILE* out);

#endif