//============================================================================
// Name        : Selection-Sort.cpp
// Author      : nayimsust
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//============================================================================
// Name        : Stack.cpp
// Author      : nayimsust@gmail.com
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>

using namespace std;

template<typename T> class Stack {
public:
	Stack();
	~Stack();

	T data;
	Stack *next;

	void Push(const T &t);
	void Pop();
	bool Empty();
	T &Top();
	int Size();
};

template<typename T> Stack<T>::Stack() {
	next = NULL;
}

template<typename T> Stack<T>::~Stack() {
}

template<typename T> void Stack<T>::Push(const T &ref) {

	if (!this->next) {
		Stack *stack = new Stack;
		stack->data = ref;

		this->next = stack;
	} else {
		Stack *stack = new Stack;
		stack->data = ref;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> void Stack<T>::Pop() {

	if (!this->next)
		return;

	Stack* stack = this->next->next;

	if (!stack) {
		delete (this->next);
		this->next = NULL;
	} else {
		delete (this->next);
		this->next = stack;
	}
}

template<typename T> bool Stack<T>::Empty() {
	return (this->next) ? true : false;
}

template<typename T> T& Stack<T>::Top() {
	return this->next->data;
}

template<typename T> int Stack<T>::Size() {
	size_t t_size = 0;
	Stack *stack = this->next;
	if (!stack)
		return t_size;

	while (stack) {
		stack = stack->next;
		++t_size;
	}

	return t_size;
}

template<typename T> class Stack<T*> {
public:
	Stack();
	~Stack();

	T *data;
	Stack *next;

	void Push(T *t);
	void Pop();
	bool Empty();
	T *Top();
	int Size();
};

template<typename T> Stack<T*>::Stack() {
	data = NULL;
	next = NULL;
}

template<typename T> Stack<T*>::~Stack() {
}

template<typename T> void Stack<T*>::Push(T * const ptr) {

	if (!this->next) {
		Stack *stack = new Stack;
		stack->data = ptr;

		this->next = stack;
	} else {
		Stack *stack = new Stack;
		stack->data = ptr;
		stack->next = this->next;

		this->next = stack;
	}
}

template<typename T> void Stack<T*>::Pop() {

	if (!this->next)
		return;

	Stack* stack = this->next->next;

	if (!stack) {
		delete (this->next);
		this->next = NULL;
	} else {
		delete (this->next);
		this->next = stack;
	}
}

template<typename T> bool Stack<T*>::Empty() {
	return (this->next) ? true : false;
}

template<typename T> T* Stack<T*>::Top() {
	return this->next->data;
}

template<typename T> int Stack<T*>::Size() {
	size_t t_size = 0;
	Stack *stack = this->next;
	if (!stack)
		return t_size;

	while (stack) {
		stack = stack->next;
		++t_size;
	}

	return t_size;
}


class Me{
public:
	int value;
	Me():value(0){
	}

	Me(int i): value(i) {

	}

	~Me(){
	}

	int GetMe() {
		return value;
	}

	int compareTo(Me &rMe) {

		if(this == &rMe)
			return 0;
		if(this->value < rMe.value) return -1;
		if(this->value > rMe.value) return 1;
		return 0;
	}
};

bool Less(Me &m1, Me &m2) {
	return m1.compareTo(m2) < 0;
}

void Exchange(Me array[], int i, int j) {
	Me m3 = array[i];
	array[i] = array[j];
	array[j] = m3;
}

void ShellSort(Me array[], int iLength) {

	// actually shell sort is h-sort jumping h instead of 1 like in insertion sort
	// we in the insertion sort we always traverse the pre indices to and swap to put the item
	// in right position which takes so much cost but if we use h-sort its magically do the sorting with
	// so much less (swaping/ comparing). In insertion sort number of swaping and comparing is same.
	// g-th sort remain g-th sort after h-sort its the main finding and.

	int h = 1;
	while(h < iLength / 3)
		h = 3 * h + 1;

	while(h >= 1) {	// this is h-th loop to iterate through all h values.

		for (int i = h; i < iLength; ++i) { // starting from h because before that is useless to compute

			for (int j = i; j >= h; j -= h) {	// jumping h-step which is faster
				if(Less(array[j], array[j-h]))
					Exchange(array, j, j-h);
				else
					break;
			}
		}
		cout <<  h << "-th sort" << endl;
		h = h/3;
	}
}

int main() {

	int iLength = 10;
	Me me[iLength];

	for(int i = 0; i < iLength; ++i) {
		me[i] = Me(iLength - i);
	}

	for(int i = 0; i < iLength; ++i) {
		cout << me[i].GetMe() << endl;
	}

	ShellSort(me, 10);

	cout << "After Shell Sort" << endl;

	for(int i = 0; i < iLength; ++i) {
		cout << me[i].GetMe() << endl;
	}

	return 0;
}
