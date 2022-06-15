#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab3/MergeSort.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(StrTestClass)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Str elem1("test_label");
			Assert::IsTrue("test_label" == elem1.GetStr());
			Assert::IsTrue(10 == elem1.GetLength());
			Str elem2;
			Assert::IsTrue("" == elem2.GetStr());
			Assert::IsTrue(0 == elem2.GetLength());
		}
		TEST_METHOD(TestOperatorEqual)
		{
			Str elem1("test_label");
			Str elem2 = elem1;
			Assert::IsTrue(elem2.GetStr() == elem1.GetStr());
			Assert::IsTrue(elem2.GetLength() == elem1.GetLength());
		}
		TEST_METHOD(TestSetter)
		{
			Str elem1;
			elem1.SetValue("test_label");
			Assert::IsTrue("test_label" == elem1.GetStr());
		}
	};
	TEST_CLASS(MergeSortTestClass)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			int size = 12345;
			Str* arr = new Str[size];
			ArrGen(arr, size);

			MergeSort obj1;
			MergeSortMult obj2;
			Assert::IsTrue(AreEqual(obj1.GetArr(), nullptr));
			Assert::IsTrue(obj1.GetSize() == 0);
			Assert::IsTrue(AreEqual(obj2.GetArr(), nullptr));
			Assert::IsTrue(obj2.GetSize() == 0);

			MergeSort obj11(arr, size);
			MergeSortMult obj22(arr, size);
			Assert::IsTrue(AreEqual(obj11.GetArr(), arr));
			Assert::IsTrue(obj11.GetSize() == size);
			Assert::IsTrue(AreEqual(obj22.GetArr(), arr));
			Assert::IsTrue(obj22.GetSize() == size);


			MergeSort obj111 = obj11;
			MergeSortMult obj222 = obj22;
			Assert::IsTrue(AreEqual(obj111.GetArr(), obj11.GetArr()));
			Assert::IsTrue(obj111.GetSize() == obj11.GetSize());
			Assert::IsTrue(AreEqual(obj222.GetArr(), obj22.GetArr()));
			Assert::IsTrue(obj222.GetSize() == obj22.GetSize());

		}
		TEST_METHOD(TestSetter) 
		{
			int size = 12345;
			Str* arr = new Str[size];
			ArrGen(arr, size);

			MergeSort obj1;
			MergeSortMult obj2;

			obj1.Set(arr, size);
			obj2.Set(arr, size);

			Assert::IsTrue(AreEqual(obj1.GetArr(), arr));
			Assert::IsTrue(obj1.GetSize() == size);
			Assert::IsTrue(AreEqual(obj2.GetArr(), arr));
			Assert::IsTrue(obj2.GetSize() == size);
		}
		TEST_METHOD(TestSorting) 
		{
			const int size = 7;
			Str arr1[size];
			arr1[0] = { "TQXVGNHX" };
			arr1[1] = { "FQPVFUBL" };
			arr1[2] = { "APLTZ" };
			arr1[3] = { "PES" };
			arr1[4] = { "OSOLRCO" };
			arr1[5] = { "ZPYLU" };
			arr1[6] = { "ZFBG" };
			
			Str arr2[size];

			CopyArray(arr1, arr2,size);
				
			MergeSort obj1(arr1, size);
			MergeSortMult obj2(arr2, size);
				
			Str result[size]{ "TQXVGNHX","FQPVFUBL","OSOLRCO","ZPYLU","APLTZ","ZFBG","PES" };

			obj1.Sort();
			obj2.Sort();

			Assert::IsTrue(AreEqual(obj1.GetArr(), obj2.GetArr()));
			Assert::IsTrue(AreEqual(obj1.GetArr(), result));
			Assert::IsTrue(AreEqual(result, obj2.GetArr()));
		}
	};

