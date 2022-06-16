#pragma once
#include <thread>
#include <iostream>
#include "Str.h"

class MergeSortTestClass;
///Class for merge sorting
class MergeSort {
	friend class MergeSortTestClass;

protected:

	void Copy(Str* arr, int size);
	void Merge(Str* a, int low, int high, int mid);
	void SortMerge(Str* a, int low, int high);
	///Array to sort
	Str* arr;
	///Size of array to sort
	int size;
	Str* GetArr();
	int GetSize();
	friend bool AreEqual(Str* first, Str* second);

public:
	/*!
	\brief Default constructor that creates object with empty array of size 0
	*/
	MergeSort()
	{
		this->arr = nullptr;
		this->size = 0;
	}
	/*!
	\brief Constructor that creates object with particular array of particular size
	\param[in] arr - Array from which we will copy the data to object
	\param[in] size - Size of array in the first param
	*/
	MergeSort(Str* arr, int size)
	{
		Copy(arr, size); 
	}
	/*!
	\brief Copy costructor
	\param[in] obj - Object from which we will copy the data
	*/
	MergeSort(const MergeSort& obj) :MergeSort(obj.arr, obj.size)
	{
	}

	void Set(Str* arr, int size);
	void Print();
	void Sort();
};

/*!
\brief Completes main sorting of strings in descending order
\param[in] a - Array to sort
\param[in] low - Index of begin
\param[in] high - Index of end
\param[in] mid - Index of elem that is between begin and end
*/
void MergeSort::Merge(Str* a, int low, int high, int mid)
{
	int i, j, k;
	Str* temp = new Str[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (a[i].GetLength() > a[j].GetLength())
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else if (a[i].GetLength() == a[j].GetLength())
		{
			int f = 0;
			int counter_for_equal = 0;
			do {
				if (a[i].GetStr()[f] > a[j].GetStr()[f])
				{
					temp[k] = a[i];
					k++;
					i++;
					f = a[i].GetLength();
				}
				else if (a[i].GetStr()[f] < a[j].GetStr()[f]) {
					temp[k] = a[j];
					k++;
					j++;
					f = a[i].GetLength();
				}
				else if (f == a[i].GetLength() - 1 && a[i].GetStr()[f] == a[j].GetStr()[f])
				{
					temp[k] = a[i];
					k++;
					i++;
					f = a[i].GetLength();
				}
				else f++;
			} while (f != a[i].GetLength());
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}

	delete[]temp;
}
/*!
\brief Merge sort function
\param[in] a - Array to sort
\param[in] low - Index of begin
\param[in] high - Index of end
*/
void MergeSort::SortMerge(Str* a, int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		SortMerge(a, low, mid);
		SortMerge(a, mid + 1, high);
		Merge(a, low, high, mid);
	}
}
/*!
\brief Copies array to the object
\param[in] arr - Array to copy
\param[in] size - Size of array to copy
*/
void MergeSort::Copy(Str* arr, int size) {
	if (size <= 0)
	{
		this->arr = nullptr;
		this->size = 0;
		return;
	}
	this->size = size;
	this->arr = new Str[size];
	for (int i = 0; i < size; i++) {
		this->arr[i] = arr[i];
	}
}
/*!
\brief Setter for object
\param[in] arr - Array to copy
\param[in] size - Size of array to copy
*/
void MergeSort::Set(Str* arr, int size)
{
	if (this->size > 0)
	{
		delete[] this->arr;
		this->size = 0;
	}
	Copy(arr, size);
}
/*!
\brief Prints an array
*/
void MergeSort::Print() {
	for (int i = 0; i < this->size; i++) {
		std::cout << this->arr[i].GetStr() << "\n";
	}
	std::cout << "\n";
}
/*!
\brief Sorts an array
*/
void MergeSort::Sort() {
	SortMerge(this->arr, 0, this->size - 1);
}
/*!
\brief Returns an array
*/
Str* MergeSort::GetArr() {
	return arr;
}
/*!
\brief Returns a size
*/
int MergeSort::GetSize() {
	return size;
}
/*!
\brief Returns boolean value of equality of two arrays
*/
bool AreEqual(Str*first, Str* second) {
	int sizef = sizeof(first) / sizeof(Str);
	int sizes = sizeof(second) / sizeof(Str);
	if (sizef != sizes) { return 0; }
	else {
		for (int i = 0; i < sizef; i++) {
			if (first[i].GetStr() != second[i].GetStr()) { return 0; }
		}
		return 1;
	}
}

///Class for merge sorting, using multi-threading
class MergeSortMult : public MergeSort {
private:

	void MergeSortMulti(int th);

public: 

	MergeSortMult() : MergeSort::MergeSort() {};
	MergeSortMult(Str* arr, int size) { Copy(arr, size); };
	MergeSortMult(const MergeSortMult& obj) : MergeSortMult(obj.arr, obj.size) {};

	void Sort();
};

/*!
\brief Divides an array to the 4 parts (because we use 4 threads) and sorts them 
\param[in] th - thread sequence number
*/
void MergeSortMult::MergeSortMulti(int th) {
	int low = 0, high = this->size - 1;
	int mid = (low + high) / 2;
	switch (th) {
	case 1:
		high = mid;
		mid = (low + high) / 2;
		high = mid;
		break;
	case 2:
		high = mid;
		mid = (low + high) / 2;
		low = mid + 1;
		break;
	case 3:
		low = mid + 1;
		mid = (low + high) / 2;
		high = mid;
		break;
	case 4:
		low = mid + 1;
		mid = (low + high) / 2;
		low = mid + 1;
		break;
	}

	MergeSort::SortMerge(this->arr, low, high);
	//if (low < high)
	//{
	//	mid = (low + high) / 2;
	//	Sort(a, low, mid);
	//	Sort(a, mid + 1, high);
	//	Merge(a, low, high, mid);
	//	low;
	//}
};
/*!
\brief Sorts an array
*/
void MergeSortMult::Sort() {
	std::thread t1([&]() {
		this->MergeSortMulti(1);
		});
	std::thread t2([&]() {
		this->MergeSortMulti(2);
		});
	std::thread t3([&]() {
		this->MergeSortMulti(3);
		});
	std::thread t4([&]() {
		this->MergeSortMulti(4);
		});

	t1.join(), t2.join(), t3.join(), t4.join();
	std::thread t5([&]() {
		MergeSort::Merge(this->arr, 0, ((this->size - 1) / 2), ((this->size - 1) / 2) / 2);
		});
	std::thread t6([&]() {
		MergeSort::Merge(this->arr, (((this->size - 1) / 2) + 1), (this->size - 1), ((((this->size - 1) / 2) + 1) + (this->size - 1)) / 2);
		});

	t5.join(), t6.join();

	MergeSort::Merge(this->arr, 0, this->size - 1, (this->size - 1) / 2);
}