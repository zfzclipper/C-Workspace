#include<iostream>
using namespace std;

class Node
{
public:
	Node(void) : data(0), ptr_next(nullptr) {}
	Node(int d, Node* pNxt = nullptr) : data(d), ptr_next(pNxt) { cout << "Construct Node" << endl; }
	~Node() { cout << "Destruct Node!" << endl; }

	int 	data;
	Node*	ptr_next;
};

class List
{
public:
	List(void) : ptr_head(nullptr), ptr_tail(nullptr) { cout << "Default Constructor" << endl; }
	List(Node* pHead, Node* pTail) : ptr_head(pHead), ptr_tail(pTail) {}
	~List() {}

	int size();

	int front();
	void push_front(const int& value);
	void pop_front();

	int back();
	void push_back(const int& value);
	void pop_back();

	void remove(const int& value);

	friend ostream& operator<<(ostream& os, const List& list);

private:
	Node*	ptr_head;
	Node*	ptr_tail;
};

int List::size()
{
	int list_size = 0;
	Node* ptr = ptr_head;

	while(ptr)
	{
		list_size++;
		ptr = ptr->ptr_next;
	}

	return list_size;
}

int List::front()
{
	if (ptr_head->ptr_next == nullptr) { exit(-1); }

	return ptr_head->data;
}

void List::push_front(const int& value)
{
	if (ptr_head == nullptr)
	{
		ptr_head = new Node(value, nullptr);
		ptr_tail = ptr_head;
		return;
	}

	ptr_head = new Node(value, ptr_head);
}

void List::pop_front(void)
{
	if (ptr_head == ptr_tail)
	{
		ptr_tail = nullptr;
	}

	Node* front = ptr_head;
	ptr_head = ptr_head->ptr_next;

	delete front;
}

ostream& operator<<(ostream& os, const List& list)
{
	Node* ptr = list.ptr_head;
	while(ptr)
	{
		cout << ptr->data << ", ";
		ptr = ptr->ptr_next;
	}

	return os;
}

void List::remove(const int& value)
{
	if(!ptr_head) return;

	Node* pre_ptr = new Node(0, ptr_head);
	Node* cur_ptr = ptr_head;

	while(cur_ptr)
	{
		if(cur_ptr->data == value)
		{
			Node* temp_ptr = cur_ptr;

			pre_ptr->ptr_next = cur_ptr->ptr_next;
			cur_ptr = pre_ptr->ptr_next;

			delete temp_ptr;
		}
		else
		{
			cur_ptr = cur_ptr->ptr_next;
			pre_ptr = pre_ptr->ptr_next;
		}
	}
}

int main()
{
	List mylist;
	for (int i = 0; i < 10; i++)
	{
		mylist.push_front(2*i+1);
	}
	
	cout << mylist << endl;

	while(mylist.size())
	{
		mylist.pop_front();
	}
}
