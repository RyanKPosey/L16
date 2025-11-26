/*
    Programmer: Ryan Posey
    Assignment: L16A
    Purpose: Practice linked lists
    Due date: 11/25/2025
*/
#include <iostream>

using namespace std;

struct nodeType {
    int data;
    nodeType* next;
};

void buildList(nodeType*& head, nodeType*& tail, int numNodes, int sentinel) {
    // temp node
    nodeType* newNode = nullptr;

    int nodeValue;

    // get user input
    cout << "Type a value to add to the linked list (type " << sentinel << " to quit)";
    cin >> nodeValue;

    // populate linked list
    while (nodeValue != sentinel) {
        // init new node
        newNode = new nodeType;

        newNode->data = nodeValue;
        newNode->next = NULL;

        // if list is empty set newnode to head
        if (head == NULL) {
            head = newNode;
            tail = newNode;
            numNodes++;
        }

        else { // list has nodes
            tail->next = newNode;
            tail = newNode;
            numNodes++;
        }


        // get input again
        cout << "Type a value to add to the linked list (type " << sentinel << " to quit)";
        cin >> nodeValue;
    }
}