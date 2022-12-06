#ifndef __Deque_C__
#define __Deque_C__

#include "deque.h"

// Constructor
template<class T>
My_Deque<T>::My_Deque() {
    front = rear = NULL;
    size = 0;
}

// Destructor
template<class T>
My_Deque<T>::~My_Deque() {
    clear();
}

// add from end
template<class T>
void My_Deque<T>::push_back(T element) {
    Node<T>* newNode = new Node<T>();
    newNode->data = element;
    // deque is empty
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        //insert node at the end
        newNode->next = NULL;
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    // Increase the size of the deque
    size++;
}

// add front
template<class T>
void My_Deque<T>::push_front(T element) {
    // Create a new node for the new element
    Node<T> *new_node = new Node<T>();
    new_node->data = element;
    // deque is empty
    if (front == NULL) {
        front = rear = new_node;
    } else {
       //add to the frond
        new_node->next = front;
        new_node->prev = NULL;
        front->prev = new_node;
        front = new_node;
    }
    // Increase the size of the deque
    size++;
}

// Remove an element from the end of the deque
template<class T>
T My_Deque<T>::pop_back() {
    // check if it is empty
    if (is_empty())
        return -1;

    // Save the last element in a temporary node
    Node<T> *temp = rear;
    // Make the last element the one before the current last element
    rear = rear->prev;
    // one element only
    if (rear == NULL)
        front = NULL;
    else
        rear->next = NULL;
    size--;
    T removed = temp->data;
    delete temp;
    return removed;
}

// Remove an element from the start of the deque
template<class T>
T My_Deque<T>::pop_front() {
    // check if it is empty
    if (is_empty())
        return -1;
    // Save the first element in a temporary node
    Node<T> *temp = front;
    // Make the first element the one after the current first element
    front = front->next;
    // only one element
    if (front == NULL)
        rear = NULL;
    else
        front->prev = NULL;

    size--;
    T removed = temp->data;
    delete temp;
    return removed;
}

// Get the value of the first element
template<class T>
T My_Deque<T>::begin() {
    // check if it is empty
    if (is_empty())
        return -1;

    return front->data;
}

// Get the value of the last element
template<class T>
T My_Deque<T>::end() {
    // check if it is empty
    if (is_empty())
        return -1;

    return rear->data;
}

// Get the size of the deque
template<class T>
int My_Deque<T>::get_size() {
    return size;
}

// Print the whole deque
template<class T>
void My_Deque<T>::print() {
    //iterator
    Node<T> *temp = front;
    while (temp) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
    delete temp;
}

// Convert the deque into a vector
template<class T>
vector<T> My_Deque<T>::toVector() {
    // Initialize an empty vector
    vector<T> deque_vector;

    // Make a temporary node that is equal to the first element
    Node<T> *temp = front;

    // Each loop, the value of the temporary node will be added to the vector
    // and the temporary node will be equal to the next node
    while (temp) {
        deque_vector.push_back(temp->data);
        temp = temp->next;
    }

    delete temp;
    return deque_vector;
}

// Clear the deque
template<class T>
void My_Deque<T>::clear() {
    // The last element will be null
    rear = NULL;
    while (front) {
        Node<T> *temp = front;
        front = front->next;
        delete temp;
    }

    size = 0;
}
// check if it is empty
template<class T>
bool My_Deque<T>::is_empty() {
    return size == 0;
}

#endif