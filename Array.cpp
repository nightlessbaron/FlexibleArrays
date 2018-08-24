#include "Array.h"
using namespace std;

//void Array::autoSetDescendingArray(int x)
//{
//	for (int i = x; i > 0; i--)
//		a[i] = x;
//}
void Array::generateRandomSequence()
{
	for (int i = 0; i < n; i++) 
	{
		if (i == 0) 
		{
			int random = rand(); 
			a[i] = random;
			continue;
		}
		/* No srand() calls before rand(), so seed = 1*/
		int random = rand();
		srand(i);
		a[i] = random;
	}
}
int Array::length()
{
	return n;
}
void Array::swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
Array::Array(int nn)
{
	a = new int[nn];
	n = nn; 
}
void Array::setArray()
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void Array::bubbleSort()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] < a[j])
			{
				int temp; temp = a[i]; a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}
void Array::displayArray()
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
Array ::~Array()
{
	delete a; //delete n;
}

int Array::partition(int low, int high)
{
		int pivot = a[high];    // pivot
		int i = (low - 1);  // Index of smaller element

		for (int j = low; j <= high - 1; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (a[j] <= pivot)
			{
				i++;    // increment index of smaller element
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i + 1], &a[high]);
		return (i + 1);
}

void Array::QuickSort(int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(low, high);

		// Separately sort elements before
		// partition and after partition
		QuickSort(low, pi - 1);
		QuickSort(pi + 1, high);
	}
}
double Array::computeTime()
{
	cout << "Enter 1 for quicksort and 2 for bubble sort" << endl;
	int choice; cin >> choice;
	switch(choice)
	{
	case 1:
		t = clock();
		QuickSort(0, n - 1);
		t = clock() - t;
		return (double)t/CLOCKS_PER_SEC;
	case 2:
		t = clock();
		bubbleSort();
		t = clock() - t;
		return (double)t/CLOCKS_PER_SEC;
	default:
		return 0.0;
	}
}