#include<iostream>
#include<list>
#include<vector>

using namespace std;

const int N = 18;

void partition(vector<int>&, vector<int>&, int&, vector<int>&);
void concatenate(vector<int>&, vector<int>&, int&, vector<int>&);

void partition(list<int>&, list<int>&, int&, list<int>&);
void concatenate(list<int>&, list<int>&, int&, list<int>&);

void inplaceQuickSort(vector<int>& myArray) {
	size_t N = myArray.size();

	if (N <= 1) return;
}


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

	quickSort(myArray);

	cout << "Sorted array: ";
	for (size_t i = 0; i < myArray.size(); i++) {
		if (i == myArray.size() - 1) {
			cout << myArray[i] << endl;
			break;
		}
		cout << myArray[i] << ", ";
	}
}
