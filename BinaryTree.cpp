#include <iostream>
using namespace std;

class Node {
    public:
    int info;
    Node *leftchild;
    Node *rightchild;

    //constructor for node class
    Node () {
        leftchild = nullptr; // Initialize left child to null
        rightchild = nullptr; // Initialize right child to null
    }
};

class BinaryTree {
    public:
    Node *ROOT;

    BinaryTree () {
        ROOT = nullptr; // Initialize ROOT to null
    }

    void search(int element, Node *&parent, Node *&currentNode) 
    {
        // This function searches the currentNode of the specified Node as well as the current Node
        currentNode = ROOT;
        parent = nullptr;
        while ((currentNode != nullptr) && (currentNode->info != element)) 
        {
            parent = currentNode;
            if (element < currentNode->info)
                currentNode = currentNode->leftchild;
            else
                currentNode = currentNode->rightchild;
        }
    }

    void insert() {
        int x;
        cout << "Masukan nilai: ";
        cin >> x;

        // step 1: Allocate memory for the new node
        Node *newNode = new Node();

        // step 2: Assign value to the data field of the new node
        newNode->info = x;

        //step 3: Make the left and right child of the new node point to NULL
        newNode->leftchild = nullptr;
        newNode->rightchild = nullptr;

        // step 4: Locate the node which will be the parent of the new node to be inserted
        Node *parent = nullptr;
        Node *currentNode = nullptr;
        search(x, parent, currentNode );
