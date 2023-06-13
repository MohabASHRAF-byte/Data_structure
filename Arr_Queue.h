//
// Created by amoha on 6/13/2023.
//

#ifndef COMPETITIVE_PROGRAMMING_ARR_QUEUE_H
#define COMPETITIVE_PROGRAMMING_ARR_QUEUE_H

#include <bits/stdc++.h>

using namespace std;
#define  el "\n"

template<class T>
class Arr_Queue {
    int begin = 0;
    int end = 5 - 1;
    int size = 0;
    T arr[5];
public:
    T front();

    T back();

    void push(T);

    void pop();

    bool isFull();

    bool isEmpty();
};

template<class T>
T Arr_Queue<T>::front() {
    return arr[begin];
}

template<class T>
T Arr_Queue<T>::back() {
    return arr[end];
}

template<class T>
bool Arr_Queue<T>::isFull() {
    return (this->size == 5);
}

template<class T>
bool Arr_Queue<T>::isEmpty() {
    return !this->size;
}

template<class T>
void Arr_Queue<T>::push(T val) {
    assert(!isFull());
    size++;
    this->end = (end + 1) % 5;
    arr[end] = val;
}

template<class T>
void Arr_Queue<T>::pop() {
    assert(!isEmpty());
    size--;
    this->begin = (begin + 1) % 5;

}


#endif //COMPETITIVE_PROGRAMMING_ARR_QUEUE_H
