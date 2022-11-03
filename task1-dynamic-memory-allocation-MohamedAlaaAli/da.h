#ifndef __DA_H__
#define __DA_H__
template<class T>
class My_DA{
    private:
        int size = 0;
        int capacity = 1;
        T* data = nullptr;

    public:
        // constructor that initializes the data
        My_DA();

        // Constructor that takes an array and its size ,so it is added directly to data
        My_DA(T[], int size);

        //destructor
        ~My_DA();

        // return the element at given index
        T get(int index);

        // function that add new element to the end of the vector
        void push(T element);

        // remove the last element, return the removed element
        T pop();

        // function that inserts an element at a given index
        void insert(int index, T element);

        // remove the element at a given index, return the removed element
        T remove(int index);

        // print the whole array
        void print();

        // clear the whole array
        void clear();

        // given an element, return the first index of the given element if found, return -1 if not found
        int find(T element);

        // return the size of the array i.e. the number of filled slots
        int get_size();

        // return the reserved memory for the array
        int get_capacity();

        void adjust_capacity();

        void expand();

        void shrink();

        bool needExpanding();
        bool needShrink();


};




#endif