//
// Created by amoha on 6/13/2023.
//

#ifndef COMPETITIVE_PROGRAMMING_ARR_STACK_H
#define COMPETITIVE_PROGRAMMING_ARR_STACK_H

#include <bits/stdc++.h>

using namespace std;
#define  el "\n"

template<class T>
class Arr_stack {
    int capacity = 1;
    int *arr = new int[capacity];
    int pointer = -1;
    int size = 0;
public:
    void push(T);

    void expand();

    bool isFull();

    bool isEmpty();
    int Size();
    void pop();

    T front();
};

template<class T>
int Arr_stack<T>::Size() {
    return size;
}

template<class T>
T Arr_stack<T>::front() {
    assert(!isEmpty());
    return arr[pointer];
}

template<class T>
void Arr_stack<T>::pop() {
    assert(!isEmpty());
    pointer--;
    size--;
}

template<class T>
bool Arr_stack<T>::isEmpty() {
    return !this->size;
}

template<class T>
bool Arr_stack<T>::isFull() {
    return (capacity <= (pointer + 1));
}

template<class T>
void Arr_stack<T>::expand() {
    int *temp = new int[capacity << 1];
    for (int i = 0; i < capacity; i++) {
        temp[i] = arr[i];
    }
    arr = temp;
    capacity <<= 1;
}


template<class T>
void Arr_stack<T>::push(T val) {
    if (isFull())
        expand();
    pointer++;
    size++;
    arr[pointer] = val;
}

#endif //COMPETITIVE_PROGRAMMING_ARR_STACK_H
