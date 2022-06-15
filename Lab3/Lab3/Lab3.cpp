#include <iostream>
#include <thread>
#include <ctime>

#include "MergeSort.h"
#include "Timer.h"
int main(){
	srand(time(0));
	unsigned int size = 128413;
	Str* arr1 = new Str[size];
	ArrGen(arr1, size);
	Str* arr2 = new Str[size];
	CopyArray(arr1, arr2, size);

	MergeSort obj1(arr1,size);
	MergeSortMult obj2(arr2,size);

		Timer tm1;
		obj1.Sort();
		tm1.TimerStop();
		Timer tm2;
		obj2.Sort();
		tm2.TimerStop();

	return 0;
}

