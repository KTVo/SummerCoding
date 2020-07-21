#include <iostream>
#include <ctime>
using namespace std;

template <typename T>
bool binarySearch(const T val, const T* arr, const int sz)
{	
	bool isFound = false;
	int cnt = 0;		//Counts for the index to make sure 
	int mid = sz / 2;	//Index that serves as the midpoint (subject to incr if searched value is greater than mid)
	int max = sz - 1;	//Index that serves as the max (subject to decr if searched value is lesser than mid)

	

	while (!isFound && cnt < sz/2)	//while-loop terminates once value is found or half the number of elements have been reached
	{
		if (arr[mid] == val)	
			isFound = true;
		else if (val > arr[mid])	//if searching val is greater than middle
		{
			mid = ((mid+1) + max) / 2;
		}
		else                       //if searching val is less than middle
		{
			max = mid-1;	//decrease the max to one less than the mid 
			mid = (mid + max) / 2;
		}

		cnt++;
	}

	if (isFound)
		cout << endl << "Element " << val << " was found at INDEX " << mid << endl;

	return isFound;
}

template <typename T>
void bubbleSort(T* arr, const int sz)
{
	for(int i = 0; i < sz; i++)
		for (int j = i+1; j < sz; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
}

template <typename T>
void printArr(const T* arr, const int sz)
{
	cout << endl << endl;

	for (int i = 0; i < sz; i++)
	{
		cout << arr[i];

		if (i < sz - 1)
			cout << ", ";

		if ((i+1)%10 == 0 && i != 0)
			cout << endl;


	}

	cout << endl << endl;
}

int main()
{
	srand(time(NULL));

	int sz;
	int val;
	int *arr;

	cout << "\nEnter # to be searched: ";
	cin >> val;
	cout << "\nEnter # of values to randomly generate: ";
	cin >> sz;


	arr = new int[sz];

	for (int i = 0; i < sz; i++)
		*(arr + i) = rand() % 127 + 48;


	cout << "unSorted...";
	printArr(arr, sz);

	bubbleSort(arr, sz);

	cout << "Sorted...";
	printArr(arr, sz);

	cout<<endl<<endl<<binarySearch(val, arr, sz);

	delete[] arr;

	return 0;
}
