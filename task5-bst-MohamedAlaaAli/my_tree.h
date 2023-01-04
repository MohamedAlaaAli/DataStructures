#ifndef MY_TREE_H
#define MY_TREE_H
#include "iostream"
#include <vector>
#include "algorithm"
#include "stack"
#include "queue"
#include "cmath"
using namespace std;


template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;


    // Add the constructors you want
};

template <class T>
class MyTree{

    private:
    // Add all private fields you want
    Node<T> *root;
    int size;

    int heightCalc(Node<T>* rt)
    {
        if(rt == NULL)
            return -1;
        int leftH = heightCalc(rt->left);
        int rightH = heightCalc(rt->right);
        return max(rightH, leftH)+1;

    }

    void clearHelper( Node<T>* &rt)
    {
        if(rt!= NULL)
        {
            clearHelper(rt->left);
            clearHelper(rt->right);

        }
        delete rt;
    }


    Node<T>* FindMin(Node<T> *rt)
    {
        if (rt == NULL)
            return NULL;
        else if(rt->left == NULL)
            return rt;
        else
            return FindMin(rt->left);
    }

    Node<T>* FindMax(Node<T>* rt)
    {
        if(rt == NULL)
            return NULL;
        else if( rt->right == NULL)
            return rt;
        else
            return FindMax(rt->right);
    }

    // private function for post traversal recursively, takes node pointer
    void postOrderRecursive(Node<T>* current ,vector<T> &result)
    {
        if(!current)
            return;
        postOrderRecursive(current->left, result);
        postOrderRecursive(current->right, result);
        result.push_back(current->data);
    }

    //private function for in order traversal recursively, takes node pointer
    void inOrderRec(Node<T>* current, vector<T> &result)
    {
        if(!current)
            return;
        inOrderRec(current->left, result);
        result.push_back(current->data);
        inOrderRec(current->right, result);
    }

    //private function for in preorder traversal recursively, takes node pointer
    void preOrdRec(Node<T>* current, vector<T> &result)
    {
        if(!current)
            return;
        result.push_back(current->data);
        preOrdRec(current->left, result);
        preOrdRec(current->right,result);

    }

    //private recursive function for pushing elements of vector to the tree
    Node<T>* pushInVec(vector<T> v, int start, int end)
    {
        if(start>end)
            return NULL;
        int mid = (start+end)/2;
        if((start+end)%2!=0)
            mid +=1;
        Node<T>* current = createNewNode(v[mid]);
        current->left = pushInVec(v, start, mid-1);
        current->right = pushInVec(v, mid+1, end);
        return current;
    }
    // creates new nodes instead of the constructor
    Node<T>* createNewNode(T val)
    {
        Node<T>* node=new Node<T>;
        node-> data=val;
        node->right=node->left=NULL;
        return node;
    }

    // insert given the root and the item to be inserted, returns a node pointer to the whole tree after modification
    Node<T>* insertionHelper(Node<T> *rt , T item)
    {
        // if bst is empty make this node the root node
        if(rt == NULL)
        {
            Node<T>* newNode = new Node<T>;
            newNode->data = item;
            rt = newNode;
        }
        else if(item<rt->data)
            rt->left = insertionHelper(rt->left, item);
        else
            rt->right = insertionHelper(rt->right, item);

        return rt;
    }

    Node<T>* deletionHelper(Node<T>* rt, T item)
    {
        if(rt == NULL) // tree is empty
            return NULL;
        else if(item<rt->data) // item is in the left subtree
            rt->left = deletionHelper(rt->left, item);
        else if(item>rt->data) // item is in the right subtree
            rt->right = deletionHelper(rt->right, item);
        else // l item hia l node l na 3ndha 7alin
        {
            if (rt->left==NULL && rt->right==NULL) // leaf node
                rt = NULL;
            else if( rt->left!=NULL && rt->right==NULL)//has one child on left side
            {
                rt->data = rt->left->data;
                delete rt->left;
                rt->left = NULL;
            }
            else if( rt->left==NULL && rt->right!=NULL)//has one child on right side
            {
                rt->data = rt->right->data;
                delete rt->right;
                rt->right = NULL;
            }
            else // node has 2 children
            {
                Node<T> *max = FindMax(rt->left);
                rt->data = max->data;
                rt->left = deletionHelper(rt->left, max->data);

            }
        }
        return rt;
    }


    public:
        //initialize the tree
        MyTree()
        {
            root = NULL;
            size = 0;
        }

        // create using a given vector
        MyTree(vector<T> elements)
        {
            root = NULL;
            sort(elements.begin(), elements.end());
            root = pushInVec(elements, 0, elements.size()-1);
            size = elements.size();

        }

        // inserting a given value
        void insert(T key)
        {
            size++;
            root  = insertionHelper(root, key);
        }

        // inserting a given node
        void insert(const Node<T> node)
        {
            insert(node->data);
        }

        //search the tree
        const Node<T>* search(T key)
        {
            if(root == NULL)
                return NULL;
            auto current = root;
            while(current){
                if(current->data == key)
                    return current;
                if(key > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
            //reached the end and not found
            return NULL;
        }
        
        const Node<T>* delete_node(T key)
        {
            size--;
            deletionHelper(root, key);

        }

        const Node<T>* delete_node(const Node<T> node)
        {

            delete_node(node->data);
        }

        // checks whether the vector returned from the inorder traversal is ascending sorted
        bool isBST()
        {
            vector<T> traversed = inorder_rec();
            bool result = true;
            for(int i = 0; i < traversed.size()-1; i++)
            {
                if(traversed[i] > traversed[i+1])
                {
                    result = false;
                    break;
                }
            }
            return result;
        }
        //inorder traversal
        vector<T> inorder_rec()
        {
            vector<T> result ;
            inOrderRec(root,result);
            return result;
        }
        // preorder traversal
        vector<T> preorder_rec()
        {
            vector<T> result ;
            preOrdRec(root, result);
            return result;
        }
        //post order traversal
        vector<T> postorder_rec()
        {
            vector<T> result ;
            postOrderRecursive(root, result);
            return result;

        }
        
        vector<T> inorder_it()
        {
            auto current = root;
            stack<Node<T> *> st;
            vector<T> result;
            while(true)
            {
                if(current!=NULL)
                {
                    st.push(current);
                    current = current->left;
                }
                else
                {
                    if(st.empty()) break;

                    result.push_back(st.top()->data);
                    current = st.top()->right;
                    st.pop();

                }
            }
            return result;
        }
        
        vector<T> preorder_it()
        {
            vector<T> result;
            stack<Node<T>*> st;
            st.push(root);
            while (!st.empty())
            {
                Node<T>* current= st.top();
                st.pop();
                result.push_back(current->data);
                if(current->right != NULL)
                    st.push(current->right);
                if(current->left != NULL)
                    st.push(current->left);
            }
            return result;

        }
        
        vector<T> postorder_it()
        {
            vector<T> result;
            stack<Node<T> *> st;
            auto current = root;
            while(true)
            {
                if(current!=NULL)
                {
                    st.push(current);
                    current = current->left;
                }
                else
                {
                    if(st.empty()) break;
                    current = st.top()->right;
                    if(current==NULL)
                    {
                        Node<T> *last = NULL;
                        while(!st.empty() && st.top()->right == last)
                        {
                            last = st.top();
                            st.pop();
                            result.push_back(last->data);
                        }
                    }
                }
            }
            return result;
        }

        vector<T> breadth_traversal()
        {
            vector<T> result;
            queue<Node<T>*> q;
            q.push(root);
            auto current = root;
            while(!q.empty())
            {
                current = q.front();
                q.pop();
                result.push_back(current->data);
                if(current->left!=NULL)
                    q.push(current->left);
                if(current->right!=NULL)
                    q.push(current->right);
            }
            return result;
        }

        int get_size()
        {
        //returns number of nodes
            return this->size;
        }

        int get_height()
        {
        //calculates the height given the number of nodes using the following formula
            return heightCalc(root);
        }

        void clear()
        {
            clearHelper(root);
            root = NULL;
            size=0;
        }

        ~MyTree()
        {
            clearHelper(root);
            size=0;
        }
};

#endif
