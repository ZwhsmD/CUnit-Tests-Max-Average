/*
		 Name        : max.c
		 Author      : Zuzanna Dąbrowska
		 Number      : 24721209

 */

#include "max.h"
#include <stdio.h>

double maxim(double arr[],int size){
	if(size==0) return 0;
	double maxs=arr[0];
	for(int i=1;i<size;i++){
		if(maxs<arr[i]) {
			maxs=arr[i];
		}
	}
	return maxs;
}

double average(double arr[],int size){
	if(size==0) return 0;
	double sum=0.00;
	for(int i=0;i<size;i++){
		sum+=arr[i];
	}
	return sum/size;
}
