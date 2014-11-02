#include <iostream>
using namespace std;

template <class T>
class Queue {

    private:
		T * qarray;
		int qsize;
		int count;
		int qfront;
		int qback;
	
	public:	
		Queue (int);
		~Queue() {
		
			delete [] qarray;
		}
		
		bool isEmpty();
		bool isFull();
		void push(T);
		void pop();
		T front();
};

template <class T>
Queue<T>::Queue (int size) {
	
	
	qarray = new T[size];
	qsize = size;
	count = 0;
	qfront = 0;
	qback = 0;
}

template <class T>
bool Queue<T>::isFull () {
	
	if (count == qsize)
		return true;
	else
		return false;
}

template <class T>
bool Queue<T>::isEmpty() {
	
	if (count == 0)
		return true;
	else
		return false;
}

template <class T>
void Queue<T>::push (T x) {

	if (isFull()) {
		
		throw "OVERFLOW!";
	}
	else {
		
		qarray[qback] = x;
		qback = (qback + 1) % qsize;
		count ++;
	}
}

template <class T>
void Queue<T>::pop () {
	
	if (isEmpty())
		throw "UNDERFLOW!";
	else {
		
		qfront = (qfront + 1) % qsize;
		count --;
	}
}

template <class T>
T Queue<T>::front() {
	
	if (isEmpty())
		throw "DONT GOT NOTHIN!";
	else
		return qarray[qfront];
}

int main() {
	int s;
	
	try {
		
		
		cout << "Enter a size for the queue!\n";
		cin >> s;
		Queue<double> q(s);
		for (int i = 0; i < s; i ++)
			q.push(i);
		
		for (int i = 0; i < s; i ++) {
			cout << q.front() << "\n";
			q.pop();
		}
	}
	
	catch (char * error) {
		cout << error << "\n";
	}
	return 0;
}
