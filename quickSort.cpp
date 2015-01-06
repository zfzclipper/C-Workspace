#include<iostream>
#include<list>
#include<vector>

using namespace std;

const int N = 18;

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

	//mergeSort(mylist);

	cout << "Sorted list: ";	
	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		if (it == --mylist.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it << ", ";
	}

	//mergeSort(myArray);

	cout << "Sorted array: ";
	for (size_t i = 0; i < myArray.size(); i++) {
		if (i == myArray.size() - 1) {
			cout << myArray[i] << endl;
			break;
		}
		cout << myArray[i] << ", ";
	}
}
