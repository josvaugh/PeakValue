/*
	Joseph Vaughn CS484 Div&Conq
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
	PeakValue and PeakIndex:
	Using Binary Search as recommended, this will return the Value
	of the array. First we have to find out what is the value of
	the middle element to see if it can be the peak value,
	which is the best case scenario.
	If the middle of the array is not the peak value, then
	check both neighbors. If one is bigger than the other, then
	that means the peak value must be on that side, 
	LHS and RHS respectively. 

*/
int PeakValue(vector<int> array, int low, int high, int n)
{
	int mid = (low + high) / 2;
	
	if ((mid == 0 || array[mid - 1] <= array[mid]) && (mid == n - 1 || array[mid + 1] <= array[mid])){
		return array[mid];
	}

	else if (mid > 0 && array[mid - 1] > array[mid])
		return PeakValue(array, low, (mid - 1), n);
 
	else return PeakValue(array, (mid + 1), high, n);
}

int PeakIndex(vector<int> array, int low, int high, int n)
{
	int mid = (low + high) / 2;

	if ((mid == 0 || array[mid - 1] <= array[mid]) && (mid == n - 1 || array[mid + 1] <= array[mid])) {
		return mid;
	}

	else if (mid > 0 && array[mid - 1] > array[mid])
		return PeakIndex(array, low, (mid - 1), n);

	else return PeakIndex(array, (mid + 1), high, n);
}

/*
	findValue and findIndex:
	Since C++ functions cannot produce 2 outputs, we have to use
	two separate functions to give said output. This will make it
	easier to use recursion as well for PeakValue and PeakIndex. 
*/
int findValue(vector<int> array, int n)
{
	return PeakValue(array, 0, n - 1, n);
}

int findIndex(vector<int> array, int n)
{
	return PeakIndex(array, 0, n - 1, n);
}

int main() {

	//Create a dynamic array to save the values
	vector<int> numbers;

	
	ifstream in("peak.txt", ios::in); //Create the input file stream

	int number;  

	while (in >> number) {
		
		numbers.push_back(number); //Put the number into the end of the array
	}

	in.close();

	/*
	DEBUGGING: Display numbers
	cout << "Numbers:\n";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << '\n';
	}
	*/
	
	//find length of the dynamic array for functions
	int n = sizeof(numbers)/2;

	printf("The peak value is %d\n", findValue(numbers, n));
	printf("The peak index is %d\n", findIndex(numbers, n));

	cin.get(); //pause program until enter is pressed. 
	return 0;
}