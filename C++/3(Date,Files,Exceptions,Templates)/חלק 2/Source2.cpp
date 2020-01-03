#include"Date.h"



template<class T>
void print(T* array, int size);//to print an array

template <class T>
void SelectionSort(T* a, int size);//to sort an array

template <class T>
void Swap(T& a, T& b);//to swap two variables value

int main()
{
	Date arr_date[] = { Date(2,2,2000),Date(1,2,2000),Date(3,2,2000) };
		SelectionSort(arr_date, 3);
	print(arr_date, 3);

	int arr_int[] = { 6,5,3,9,-1,8,0 };
	SelectionSort(arr_int, 7);
	print(arr_int, 7);


	system("pause");
	return 0;
}

template <class T>
void Swap(T& a, T& b)//to swap two variables value
{
	//the restriction is operator = 
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<class T>
void print(T * array, int size)//to print an array
{
	//the restriction is operator cout
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << endl;
	}
}
template <class T>
void SelectionSort(T* a, int size)//to sort an array
{
	//the restriction is operator = , operator >
	int i, j;
	for (j = 1; j <= size; ++j)
	{
		for (i = 0; i <= size - 2; ++i)
		{
			if (a[i] > a[i + 1])
				Swap(a[i], a[i + 1]);
		}
	}

}

