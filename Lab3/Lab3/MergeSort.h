#pragma once
#include <thread>
#include "Str.h"

class MergeSort {
protected:

	void Merge(Str *a, int low, int high, int mid)
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
	void SortMerge(Str* a, int low, int high) {
		int mid;
		if (low < high) {
			mid = (low + high) / 2;
			SortMerge(a, low, mid);
			SortMerge(a, mid + 1, high);
			Merge(a, low, high, mid);
		}
	}
	Str* arr;
	int size;

	void Copy(Str* arr, int size){
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
public:
	MergeSort()
	{
		this->arr = nullptr;
		this->size = 0;
	}
	MergeSort(Str* arr, int size)
	{
		Copy(arr, size); 
	}
	MergeSort(const MergeSort& obj) :MergeSort(obj.arr, obj.size)
	{
	}

	void Set(Str* arr, int size)
	{
		if (this->size > 0)
		{
			delete[] this->arr;
			this->size = 0;
		}
		Copy(arr, size);
	}

	void Print() {
		for (int i = 0; i < this->size; i++) {
			std::cout << this->arr[i].GetStr() << "\n";
		}
		std::cout << "\n";
	}

	void Sort(){
		SortMerge(this->arr, 0, this->size - 1);
	}
};

class MergeSortMult : public MergeSort {
private:

	void MergeSortMulti(Str* a, int size, int th){
		int low = 0, high = size - 1;
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

		MergeSort::SortMerge(a, low, high);
		//if (low < high)
		//{
		//	mid = (low + high) / 2;
		//	Sort(a, low, mid);
		//	Sort(a, mid + 1, high);
		//	Merge(a, low, high, mid);
		//	low;
		//}
	};

public: 
	MergeSortMult() : MergeSort::MergeSort() {};
	MergeSortMult(Str* arr, int size) { Copy(arr, size); };
	MergeSortMult(const MergeSortMult& obj) : MergeSortMult(obj.arr, obj.size) {};


	void Sort() {
		std::thread t1([&]() {
			this->MergeSortMulti(this->arr, this->size, 1);
			});
		std::thread t2([&]() {
			this->MergeSortMulti(this->arr, this->size, 2);
			});
		std::thread t3([&]() {
			this->MergeSortMulti(this->arr, this->size, 3);
			});
		std::thread t4([&]() {
			this->MergeSortMulti(this->arr, this->size, 4);
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
};


