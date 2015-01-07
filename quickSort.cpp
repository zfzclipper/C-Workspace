#include<iostream>
#include<list>
#include<vector>

using namespace std;

const int N = 18;

//#define INPLACE_SINGLE_DIR

/* In-place Quick Sort (Array-based single direction) */

#ifdef INPLACE_SINGLE_DIR
void quickSortKernel(vector<int>&, int, int);
int partition(vector<int>&, int&, int&);

void inplaceQuickSort(vector<int>& myArray) {
	cout << "Inplace Quick Sort (Array-based single direction)" << endl;

	int begin = 0;
	int end = myArray.size();

	quickSortKernel(myArray, begin, end);
}

void quickSortKernel(vector<int>& myArray, int b, int e) {	
	if (e-b <= 1) return;

	int pivot = partition(myArray, b, e);
	quickSortKernel(myArray, b, pivot);
	quickSortKernel(myArray, pivot+1, e);
}

int partition(vector<int>& myArray, int& begin, int& end) {
	int pivotValue = myArray[end-1];

	int i = begin - 1;
	for (int j = begin; j < end; j++) {
		if (myArray[j] <= pivotValue) {
			i++;
			std::swap(myArray[i], myArray[j]);
		}
	}

	return i;	//i is pivot index
}
#else

/* In-place Quick Sort (Array-based double direction) */

void quickSortKernel(vector<int>&, int, int);
int partition(vector<int>&, int&, int&);

void inplaceQuickSort(vector<int>& myArray) {
	cout << "Inplace Quick Sort (Array-based double direction)" << endl;

	int begin = 0;
	int end = myArray.size();

	quickSortKernel(myArray, begin, end);
}

void quickSortKernel(vector<int>& myArray, int b, int e) {	
	if (e-b <= 1) return;

	int pivot = partition(myArray, b, e);
	quickSortKernel(myArray, b, pivot);
	quickSortKernel(myArray, pivot+1, e);
}

int partition(vector<int>& myArray, int& begin, int& end) {
	int pivotValue = myArray[end-1];

	int i = begin;
	int j = end - 2;

	while (i <= j) {
		while ((i <= j) && (myArray[i] <= pivotValue)) {
			i++;
		}

		while ((i <= j) && (myArray[j] > pivotValue)) {
			j--;
		}

		if (i < j) {
			std::swap(myArray[i], myArray[j]);
		}
	}

	std::swap(myArray[i], myArray[end-1]);

	return i;	//i is pivot index
}
#endif


/* Non-inplace Quick Sort (Array-based) */

void partition(vector<int>&, vector<int>&, int&, vector<int>&);
void concatenate(vector<int>&, vector<int>&, int&, vector<int>&);

void quickSort(vector<int>& myArray) {
	if (myArray.size() <= 1) return;	//Base Case

	vector<int> lessArray, greaterArray;
	int pivot;

	partition(myArray, lessArray, pivot, greaterArray);
	quickSort(lessArray);
	quickSort(greaterArray);
	concatenate(myArray, lessArray, pivot, greaterArray);
}

void partition(vector<int>& myArray, vector<int>& lessArray, int& pivot, vector<int>& greaterArray) {
	pivot = myArray.back();
	myArray.pop_back();

	while (!myArray.empty()) {
		int temp = myArray.back();

		if (temp < pivot) {
			lessArray.push_back(temp);
		}
		else {
			greaterArray.push_back(temp);
		}

		myArray.pop_back();
	}
}

void concatenate(vector<int>& myArray, vector<int>& lessArray, int& pivot, vector<int>& greaterArray) {
	if (!myArray.empty()) {
		myArray.clear();
	}

	myArray = lessArray;
	myArray.push_back(pivot);
	for (auto& e : greaterArray) {
		myArray.push_back(e);
	}

}

/* Non-inplace Quick Sort (List-based) */

void partition(list<int>&, list<int>&, int&, list<int>&);
void concatenate(list<int>&, list<int>&, int&, list<int>&);

void quickSort(list<int>& myList) {
	if (myList.size() <= 1) return;

	list<int> lessList, greaterList;
	int pivot;

	partition(myList, lessList, pivot, greaterList);
	quickSort(lessList);
	quickSort(greaterList);
	concatenate(myList, lessList, pivot, greaterList);
}

void partition(list<int>& myList, list<int>& lessList, int& pivot, list<int>& greaterList) {
	pivot = myList.back();
	myList.pop_back();

	while (!myList.empty()) {
		int temp = myList.back();

		if (temp < pivot) {
			lessList.push_back(temp);
		}
		else {
			greaterList.push_back(temp);
		}

		myList.pop_back();
	}
}

void concatenate(list<int>& myList, list<int>& lessList, int& pivot, list<int>& greaterList) {
	if (!myList.empty()) {
		myList.clear();
	}

	myList = lessList;
	myList.push_back(pivot);
	for (auto& e : greaterList) {
		myList.push_back(e);
	}

}

int main() {
	list<int> mylist;
	vector<int> myArray;

	for (int i = 0; i < N; i++) {
		if (i%2 == 0) {
			mylist.push_back(3*i+2);
			myArray.push_back(3*i+2);
		}
		else {
			mylist.push_front(2*i-1);
			myArray.push_back(2*i-1);
		}
	}

	cout << "List to be sorted: ";
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		if (it == --mylist.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it << ", ";
	}

	cout << "Array to be sorted: ";
	for (size_t i = 0; i < myArray.size(); i++) {
		if (i == myArray.size() - 1) {
			cout << myArray[i] << endl;
			break;
		}
		cout << myArray[i] << ", ";
	}

	quickSort(mylist);

	cout << "Sorted list: ";	
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		if (it == --mylist.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it << ", ";
	}

	//quickSort(myArray);
	inplaceQuickSort(myArray);	

	cout << "Sorted array: ";
	for (size_t i = 0; i < myArray.size(); i++) {
		if (i == myArray.size() - 1) {
			cout << myArray[i] << endl;
			break;
		}
		cout << myArray[i] << ", ";
	}
}
