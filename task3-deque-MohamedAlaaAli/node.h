#ifndef Node_H
#define Node_H

template<class T>
struct Node {
    T data;
    Node *next;
    Node *prev;
};

#endif
