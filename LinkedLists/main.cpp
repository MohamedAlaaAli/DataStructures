#include <iostream>
using namespace std;


class Node{
public:
    int data;
    Node* next;
    // default constructor
    Node(){
        data = 0;
        next = nullptr;
    }
};


class LinkedList{
private:
    Node* head;

public:
    // default constructor
    LinkedList(){
        head = nullptr;
    }

    bool isEmpty(){
        return (head == nullptr);
    }

    void insertFirst(int newElement){
        Node *newNode = new Node();
        newNode->data = newElement;
        if( isEmpty() ){
            newNode->next= nullptr;
        }

        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void print(bool count=0){
        int cnt = 0;
        Node* temp = head;
        while(temp->next!= nullptr){
            cnt++;
            cout << temp->data <<" ";
            temp->next;
        }
        if(count)
            cout<<endl<<" count is "<< cnt;
    }

    bool isFound(int element){
        Node* temp = head;
        while(temp->next!= nullptr){
            if(temp->data==element)
                return true;
        }
        return false;
    }

    void insertBefore(int existingElement, int newElement){
        if (isEmpty()){
            insertFirst(newElement);
        }
        if(isFound(newElement)){
            Node* newNode = new Node();
            newNode->data = newElement;
            Node* temp = head;
            while(temp!= nullptr && temp->next->data!= existingElement){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        } else
            cout<<"element not found \n";
    }

    void append(int newElement){
        if (isEmpty())
            insertFirst(newElement);

        else{
            Node* temp = head;
            while(temp!= nullptr){
                temp = temp->next;
            }
            Node* newNode = new Node();
            newNode->data = newElement;
            newNode->next = nullptr;
        }
    }

    void deleteItem(int item){
        if(isEmpty())
            cout<<"is empty";
        Node* delPtr = head;
        if(head->data == item){
            head = head->next;
            delete delPtr;
        } else{
            Node* prev = nullptr;
            delPtr = head;
            while(delPtr->data!=item){
                prev = delPtr;
                delPtr = delPtr->next;
            }
            prev->next = delPtr->next;
            delete delPtr;
        }
    }


};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
