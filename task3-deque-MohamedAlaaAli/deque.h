#ifndef __Deque_H__
#define __Deque_H__

#include <iostream>
#include <vector>
#include "node.h"

using namespace std;

template<class T>
class My_Deque {
private:
    int size;
    Node<T> *front;
    Node<T> *rear;

public:
    // constructor
    My_Deque();

    // destructor
    ~My_Deque();

    // return the last element
    T end();

    // return the first element
    T begin();

    // add the element to the end of the deque
    void push_back(T element);

    // add the element to the beginning of the deque
    void push_front(T element);

    // remove the last element, return the removed element
    T pop_back();

    // remove the first element, return the removed element
    T pop_front();

    // convert the deque to vector and return that vector
    vector<T> toVector();

    // print the whole deque from head to tail
    void print();

    // clear the whole array
    void clear();

    // return the deque size
    int get_size();

    // check if the deque is empty
    bool is_empty();

};

#include "deque.cpp"

#endif