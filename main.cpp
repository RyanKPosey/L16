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

void buildList(nodeType*& head, nodeType*& tail, int& numNodes, int sentinel) {
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

void destroyNodeList(nodeType*& head, nodeType*& tail, int& numNodes) {
    // Traverse linked list
    nodeType* current = head;
    nodeType* previous = NULL;

    while (current != NULL) {
        cout << "Deleting " << current->data << endl;
        previous = current;
        current = current->next; // Get nextNode;
        delete previous; // Delete node
        numNodes--; // Decrement node count
    }

    head = NULL;
    tail = NULL;
}

void printList(nodeType* head) {
    // Traverse linked list
    nodeType* current = head;
    while (current != NULL) {
        cout << current->data << endl;
        current = current->next; // Move to next node
    }
}

nodeType* search(nodeType* head, int key) {
    nodeType* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current; // Found the value
        }
        current = current->next; // Move to next node
    }

    return NULL; // Value not found
}

int main() {
    // init head & tail
    nodeType* head = NULL;
    nodeType* tail = NULL;

    int numNodes = 0;
    buildList(head, tail, numNodes, -999);
    printList(head);
    destroyNodeList(head, tail, numNodes);
}