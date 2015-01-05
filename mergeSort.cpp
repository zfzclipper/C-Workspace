#include<iostream>
#include<list>

using namespace std;

const int N = 16;

void merge(list<int>&, const list<int>&, const list<int>&);

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

int main() {
	list<int> mylist;

	for (int i = 0; i < N; i++) {
		if (i%2 == 0) {
			mylist.push_back(3*i+2);
		}
		else {
			mylist.push_front(2*i-1);
		}
	}

	mergeSort(mylist);

	for (auto it = mylist.begin(); it != mylist.end(); it++) {
		if (it == --mylist.end()) {
			cout << *it << endl;
			break;
		}
		cout << *it << ", ";
	}
}
