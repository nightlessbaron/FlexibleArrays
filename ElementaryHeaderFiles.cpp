#include "Array.h"
using namespace std;
//using namespace std;
int main()
{
	int n; 
	cout << "Enter the size of the array that you want" << endl;
	cin >> n;
	Array a1(n);
	a1.generateRandomSequence(); 
	//a1.setArray();
	//a1.displayArray();
	//a1.bubbleSort();
	double s = a1.computeTime();
	//a1.QuickSort(0, a1.length() - 1);
	a1.displayArray();
	cout << endl << "Total time required : ";
	cout << s << endl;
	return(0);
}