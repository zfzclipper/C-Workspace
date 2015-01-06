#include<iostream>
#include<list>
#include<vector>

using namespace std;

const int N = 18;

void merge(list<int>&, const list<int>&, const list<int>&);
void merge(vector<int>&, const vector<int>&, const vector<int>&);

#if 1
void mergeSort(vector<int>& myArray) {
	int N = myArray.size();
	if (N <= 1) return;

	vector<int> subArray0, subArray1;
	int half = N/2;
	
	for (int i = 0; i < half; i++) {
		subArray0.push_back(myArray[i]);
	}

	for (int i = half; i < N; i++) {
		subArray1.push_back(myArray[i]);
	}

	mergeSort(subArray0);
	mergeSort(subArray1);
	merge(myArray, subArray0, subArray1);
}
#endif

void merge(vector<int>& myArray, const vector<int>& subArray0, const vector<int>& subArray1) {
	size_t i, j, k;
	
	i = j = k = 0;

	while ((i < subArray0.size()) && (j < subArray1.size())) {
		if (subArray0[i] < subArray1[j]) {
			myArray[k++] = subArray0[i++];
		}
		else {
			myArray[k++] = subArray1[j++];
		}
	}

	while (i < subArray0.size()) {
		myArray[k++] = subArray0[i++];
	}
	
	while (j < subArray1.size()) {
		myArray[k++] = subArray1[j++];
	}
}

void mergeSort(list<int>& mylist) {
	int N = mylist.size();
	if (N <= 1) return;

	list<int> sublist0, sublist1;
	int half = N/2;
	int count = 0;
	
	for (auto it = mylist.begin(); it != mylist.end(); count++, it++) {
		if (count < half) {
			sublist0.push_back(*it);
		}
		else {
			sublist1.push_back(*it);
		}
	}

	mergeSort(sublist0);
	mergeSort(sublist1);
	merge(mylist, sublist0, sublist1);
}

void merge(list<int>& mylist, const list<int>& sublist0, const list<int>& sublist1) {

	auto it0 = sublist0.begin();
	auto it1 = sublist1.begin();

	while (it0 != sublist0.end() && it1 != sublist1.end()) {
		if (*it0 < *it1) {
			mylist.pop_front();
			mylist.push_back(*it0++);
		}
		else {
			mylist.pop_front();
			mylist.push_back(*it1++);
		}
	}

	while (it0 != sublist0.end()) {
		mylist.pop_front();
		mylist.push_back(*it0++);
	}

	while (it1 != sublist1.end()) {
		mylist.pop_front();
		mylist.push_back(*it1++);
	}

}	

#if 0
void merge(list<int>& mylist, const list<int>& sublist0, const list<int>& sublist1) {
	list<int> sortedList;

	auto it0 = sublist0.begin();
	auto it1 = sublist1.begin();

	while (it0 != sublist0.end() && it1 != sublist1.end()) {
		if (*it0 < *it1) {
			sortedList.push_back(*it0++);
		}
		else {
			sortedList.push_back(*it1++);
		}
	}

	while (it0 != sublist0.end()) {
		sortedList.push_back(*it0++);
	}

	while (it1 != sublist1.end()) {
		sortedList.push_back(*it1++);
	}

	for (auto& e : sortedList) {
		mylist.pop_front();
		mylist.push_back(std::move(e));
	}
}	
#endif

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

	mergeSort(mylist);

	cout << "Sorted list: ";	
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		if (it == --mylist.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it << ", ";
	}

	mergeSort(myArray);

	cout << "Sorted array: ";
	for (size_t i = 0; i < myArray.size(); i++) {
		if (i == myArray.size() - 1) {
			cout << myArray[i] << endl;
			break;
		}
		cout << myArray[i] << ", ";
	}
}
