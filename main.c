/*
 * main.c
 *
 *  Created on: 24 Apr 2025
 *      Author: Zuzanna Dąbrowska
 *      Number: 24721209
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "max.h"

void max_testcase(void){
	int size = 5;
	double *arr = malloc(size*sizeof(double));

	//Adding a test to check if maxim functions works
	//for empty arrays
	CU_ASSERT_EQUAL(maxim(arr,0), 0);

	arr[0]=1;

	//Adding a test to check if maxim functions works
	//for arrays with only one element
	CU_ASSERT_EQUAL(maxim(arr,1),1);

	for(int i=0;i<size;i++) arr[i]=i+1;

	//adding a new test to the Msuite suite to test the maxim func
	CU_ASSERT_EQUAL(maxim(arr,size), 5.0);

	for(int i=0;i<size;i++) arr[i]=-i-1;

	//Adding a test to check if maxim functions works
	//for arrays with negative values;
	CU_ASSERT_EQUAL(maxim(arr,size), -1.0);

	for(int i=0;i<size;i++) arr[i]=1;

	//Adding a test to check if maxim functions works
	//for arrays where all values are the same
	CU_ASSERT_EQUAL(maxim(arr,size), 1.0);

	for(int i=0;i<size;i++) arr[i]=0;

	//Adding a test to check if maxim functions works
	//for arrays with only zeroes
	CU_ASSERT_EQUAL(maxim(arr,size), 0.0);

	for(int i=0;i<size;i++){
		if(i%2==0) arr[i]=2;
		else arr[i]=i+1;
	}

	//Adding a two tests to check if maxim functions work
	//for arrays where some values are the same
	CU_ASSERT_EQUAL(maxim(arr,size),4.0);
	CU_ASSERT_EQUAL(maxim(arr,size),4);

	//The following are two tests that were meant to fail
	CU_ASSERT_EQUAL(maxim(arr,size),0.0);
	CU_ASSERT_EQUAL(maxim(arr,size),-4);
}

void average_testcase(void){

		int size = 5;
		double *arra = malloc(size*sizeof(double));

		//Adding a test to check if average functions works
		//for empty arrays
		CU_ASSERT_EQUAL(average(arra,0),0);

		arra[0]=1;

		//Adding a test to check if average functions works
		//for arrays with only one element
		CU_ASSERT_EQUAL(average(arra,1),1);

		for(int i=0;i<size;i++) arra[i]=i+1;

		//adding a new test to the Asuite suite to test the average func
		CU_ASSERT_EQUAL(average(arra,size),3.0);

		for(int i=0;i<size;i++) arra[i]=-i-1;

		//Adding a test to check if average functions works
		//for arrays with negative values;
		CU_ASSERT_EQUAL(average(arra,size),-3.0);

		for(int i=0;i<size;i++) arra[i]=1;

		//Adding a test to check if average functions works
		//for arrays where all values are the same
		CU_ASSERT_EQUAL(average(arra,size),1.0);

		for(int i=0;i<size;i++) arra[i]=0;

		//Adding a test to check if average functions works
		//for arrays with only zeroes
		CU_ASSERT_EQUAL(average(arra,size),0.0);

		for(int i=0;i<size;i++){
			if(i%2==0) arra[i]=2;
			else arra[i]=i+1;
		}

		//Adding a test to check if average functions works
		//for arrays where some values are the same
		CU_ASSERT_EQUAL(average(arra,size),2.4);

		//Two tests that are designed to fail
		CU_ASSERT_EQUAL(average(arra,size),2);
		CU_ASSERT_EQUAL(average(arra,size),-2.4);
}

void runAllTests(){
	//initializing the test registry to contain the Msuite and the Asuite
	CU_initialize_registry();

	//suite which will contain tests for the maxim function from max.c
	CU_pSuite Msuite = CU_add_suite("max_suite", 0, 0);

	//suite which will contain tests for the average function from max.c
	CU_pSuite Asuite = CU_add_suite("average_suite", 0, 0);

	//adding a new test to the Msuite suite to test the maxim func
	CU_add_test(Msuite, "max_test", max_testcase);
	//adding a new test to the Asuite suite to test the average func
	CU_add_test(Asuite, "average_test",average_testcase);

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

	//cleaning up and releasing memory used by the framework to avoid a memory leak
	CU_cleanup_registry();
}

int main() {
    runAllTests();

    return 0;
}


