#pragma once
#define MAXSIZE 100
#include<time.h>
#include<iostream>
#include<cstdlib>
class Array
{
private:
	int* a; int n; static int count; clock_t t;
public:
	Array(int);
	~Array();
	void setArray();
	void bubbleSort();
	void displayArray();
	void QuickSort(int, int);
	void swap(int*, int*);
	int partition(int, int);
	int length();
	double computeTime();
	void generateRandomSequence();
	//void autoSetDescendingArray(int);
	//static int noOfArrays();
};
//int Array::count = 0;