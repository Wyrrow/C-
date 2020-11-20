#include <iostream>
#include <string>

using namespace std;

class Node {
public:
	int value;
	Node* next;
	Node() :
	value(0), next(nullptr)
	{}
	
	Node(int v) :
		value(v), next(nullptr)
	{}
	Node(const Node* other) {
		value = other->value;
		next = other->next;
	}

	Node(int v, Node* n) :
		value(v), next(n)
	   {}


};

class Queue {

public:
	int count;
	Node* head;
	Node* tail;

	Queue() :
		head (nullptr),	tail ( nullptr), count(0)
	{}

	Queue(int v) :
		tail(head), count(1) 
	{
		head = new Node(v);
	}
		
	
	
	void add(int v) {
		Node* tmp = new Node(v);

		if (head == nullptr) {
			head = tmp;
			tail = head;
			count = 1;
		}
		else {
			tail->next = tmp;
			tail = tail->next;
			count++;
		}
	}

	int calculateNorm() {
		Node* tmp = new Node();
		int sum = 0;
		tmp = head;
		for (int i = 0; i < count; i++) {
			sum += abs(tmp->value);
			tmp = tmp->next;
		}
		return sum / count;
	}

	Queue operator+(Queue &other) {
		int minimumL, maximumL;

		if (this->count < other.count) {
			minimumL = this->count;
			maximumL = other.count;
		}
		else {
			minimumL = other.count;
			maximumL = this->count;
		}

		Queue outQue;

		outQue = this;
		Node* tmpItem = other.head;

		for (int i = 0; i < other.count; i++) {
			outQue.add(tmpItem->value);
			tmpItem = tmpItem->next;
		}


		return outQue;

	}

	Queue* operator=(Queue* other) {
		if (this->head == other->head) {
			return this;
		}
		Queue* tmp = new Queue();
		Node* tmpItem = new Node();
		tmpItem = other->head;
		for (int i = 0; i < other->count; i++) {
			tmp->add(tmpItem->value);
			tmpItem = tmpItem->next;
		}

		return tmp;
	}

	friend istream& operator >>(istream& in, Queue& q) {
		cout << "\nEnter the value to push in tail: \n";
		int tempValue;
		in >> tempValue;
		q.add(tempValue);
		return in;
	}

	friend ostream& operator <<(ostream& os, Queue& q) {
		int choice = 2;
		cout << "Enter 1 or 2 to 'Pop' or 'cout' functions: ";
		cin >> choice;

		if (choice == 1) {
			os << "Head of queue: " << q.head->value << endl;
			q.head = q.head->next;
		}
		else if (choice == 2) {
			Node* tmp = q.head;
			os << "\n";
			if (tmp == nullptr) {
				os << "List is empty!\n";
			}
			else {
				while (tmp != nullptr) {
					os << tmp->value << " ";
					tmp = tmp->next;
				}
			}
		}
		return os;
	}

	friend bool operator ==(Queue& q1, Queue& q2) {
		if ((q1.head == q2.head) && (q1.count == q2.count)) {
			cout << "\nTwo queues are equal!\n";
			return true;
		}

		if (q1.count != q2.count) {
			cout << "\nQueues are NOT equal!\n";
			return false;
		}

		Node* tmp1, tmp2;
		tmp1 = q1.head;
		tmp2 = q2.head;

		for (int i = 0; i < q1.count; i++) {
			if (tmp1->value != tmp2.value) {
				cout << "Queues are NOT equal!\n";
				return false;
			}
		}

		cout << "\nTwo queues are equal!\n";
		return true;

	}

	friend bool operator !=(Queue& q1, Queue q2) {
		if (q1.count != q2.count) {
			cout << "\nTwo Queues are NOT equal!\n";
			return true;
		}


		Node* tmp1, tmp2;
		tmp1 = q1.head;
		tmp2 = q2.head;

		for (int i = 0; i < q1.count; i++) {
			if (tmp1->value != tmp2.value) {
				cout << "\nTwo Queues are NOT equal!\n";
				return true;
			}
		}

		cout << "\nTwo Queueq are equal!\n";
		return false;
	}

	friend bool operator >(Queue& q1, Queue& q2) {
		return q1.calculateNorm() > q2.calculateNorm();
	}

	friend bool operator <(Queue& q1, Queue& q2) {
		return q1.calculateNorm() < q2.calculateNorm();
	}


};


int main() {

	Queue q1;
	cout << "This is Queue 1 --------------\n";
	q1.add(15);
	q1.add(26);
	q1.add(33);
	cout << q1<< endl;

	Queue q2; 
	int k;
	cout << "Create Queue 2--------------\n";
	cout << "Enter number of elements : \n";
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> q2;
	}
	cout << q2 << endl ;
	

	Queue q3;
	q3= q1 + q2 ;
	cout << "This is Queue 3 --------------\n";
	cout << q3 << endl;

	cout << (q1 == q2) << endl;
	cout << (q1 != q2) << endl;
	cout << (q3 == q3) << endl;

	cout << q2;
	cout << q2;

	
	return 0;
}
