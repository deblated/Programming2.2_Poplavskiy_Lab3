#include <iostream>
#include <thread>
#include <ctime>

#include "MergeSort.h"
#include "Timer.h"

int main(){
	srand(time(0));
	unsigned int size = 149710;
	//size 149710
	//Duration: 20.5391 seconds --> original version
	//Duration : 14.6916 seconds --> multithreading version
	//size 14971
	//Duration: 1.59834 seconds --> original version
	//Duration : 0.960953 seconds --> multithreading version
	//size 70893
	//Duration: 8.5033 seconds --> original version
	//Duration : 5.98572 seconds --> multithreading version
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

