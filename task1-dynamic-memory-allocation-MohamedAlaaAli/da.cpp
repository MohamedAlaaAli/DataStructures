#include <iostream>
#include "da.h"
using namespace std;
#include <cmath>

// implement all the methods in da.h
// feel free to add new helper methods whether private or public
//constructor 1
template<class T>
My_DA<T>::My_DA() {
    data = new T[capacity];
}


// constructor 2 takes an array and adds it
template<class T>
My_DA<T>::My_DA(T *arr, int size) {
    capacity = pow(2, ceil(log2(size)));
    data = new T[capacity];
    for( int i = 0; i<size; i++)
        data[i] = arr[i];
    this->size = size;
}

// Destructor
template <class T>
My_DA<T>::~My_DA()
{
    delete[] data;
}


// gets the element at the given index
template<class T>
T My_DA<T>::get(int index) {
    if( index >=0 && index<size){
        return data[index];
    }
    else{
        return -1;
    }

}

// pushes an element to the end of the array
template<class T>
void My_DA<T>::push(T element) {
    if(needExpanding())
        expand();

    cout<<"here";
    data[size++] = element;

}

template<class T>
T My_DA<T>::pop() {
    if(size==0)
        return -1;
    T last = data[size-1];
    size-=1;
    if(needShrink())
        shrink();
    return last;
}

template<class T>
void My_DA<T>::insert(int index, T element) {
    if (needExpanding())
        expand();
    if( !( index >=0 && index <= size))
        return;
    for ( int i=size-1; i>=0; i--){
        if(i >= index)
            data[i+1] = data[i];
    }
    data[index] = element;
    size++;

}

template<class T>
T My_DA<T>::remove(int index) {
    if (index >= size || index < 0)
        return -1;

    else{
        T removed = data[index];
        for( int i=index; i<size; i++)
            data[i] = data[i+1];

        size--;
        if (needShrink())
            shrink();


        return removed;
    }

}

template<class T>
void My_DA<T>::print() {
    for( int i=0; i<size; i++)
        cout<<data[i];
}

template<class T>
void My_DA<T>::clear() {
    T *newData = new T[1];
    delete[] data;
    size = 0;
    capacity = 1;
    data = newData;
}

template<class T>
int My_DA<T>::find(T element) {
    for(int i=0; i<size; i++)
        if(data[i] == element)
            return i;
    return -1;
}

template<class T>
int My_DA<T>::get_size() {
    return size;
}

template<class T>
int My_DA<T>::get_capacity() {
    return capacity;
}



template<class T>
void My_DA<T>::expand() {
    capacity*=2;
    T *temp = new T[capacity];
    for ( int i = 0; i < size; i++)
        temp[i] = data[i];
    delete[] data;
    data = new T[capacity];
    data = temp;

}

template<class T>
void My_DA<T>::shrink() {
    capacity*=0.5;
    T *temp = new T[capacity];
    for (int i = 0; i< size; i++)
        temp[i] = data[i];
    delete[] data;
    data = new T[capacity];
    data = temp;
}

template<class T>
bool My_DA<T>::needExpanding() {
    return size>=capacity;
}

template<class T>
bool My_DA<T>::needShrink() {
    return size == capacity/4;
}






