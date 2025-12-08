/*
    Programmer: Ryan Posey
    Assignment: L16C
    Purpose: Practice linked lists
    Due date: 12/7/2025
*/
#include <iostream>

using namespace std;

struct nodeType {
    int data;
    nodeType* next;
};

void insertOrdered(nodeType*& head, nodeType*& tail, int value, int& numNodes) {
    // Create new node
    nodeType* newNode = new nodeType;
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty or new node should be the first node
    if (head == NULL || head->data >= value) {
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            tail = newNode; // If list was empty, set tail to new node
        }
    } else {
        // Traverse to find the correct position
        nodeType* current = head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;

        // Update tail if necessary
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }
    numNodes++;
}

void buildOrderedList(nodeType*& head, nodeType*& tail, int& numNodes, int sentinel) {
    int nodeValue;

    // get user input
    cout << "Type a value to add to the linked list in order (type " << sentinel << " to quit): ";
    cin >> nodeValue;
    cout << endl;

    // populate linked list
    while (nodeValue != sentinel) {
        insertOrdered(head, tail, nodeValue, numNodes);

        // get input again
        cout << "Type a value to add to the linked list in order (type " << sentinel << " to quit): ";
        cin >> nodeValue;
        cout << endl;
    }
}

void buildList(nodeType*& head, nodeType*& tail, int& numNodes, int sentinel) {
    // temp node
    nodeType* newNode = nullptr;

    int nodeValue;

    // get user input
    cout << "Type a value to add to the linked list (type " << sentinel << " to quit): ";
    cin >> nodeValue;
	 cout << endl;

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
        cout << "Type a value to add to the linked list (type " << sentinel << " to quit): ";
        cin >> nodeValue;
		  cout << endl;
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

bool editValue(nodeType* head, int oldValue, int newValue) {
    nodeType* targetNode = search(head, oldValue);

    if (targetNode != NULL) {
        targetNode->data = newValue;
        return true; // Edit successful
    }

    return false; // Value not found
}

bool deleteValue(nodeType*& head, nodeType*& tail, int key, int& numNodes) {
    nodeType* current = head;
    nodeType* previous = NULL;

    while (current != NULL) {
        if (current->data == key) {
            // Node found
            if (previous == NULL) {
                // Deleting head
                head = current->next;
                if (head == NULL) {
                    tail = NULL; // List is now empty
                }
            } else {
                previous->next = current->next;
                if (current == tail) {
                    tail = previous; // Update tail if needed
                }
            }
            delete current;
            numNodes--; // Decrement node count
            return true; // Deletion successful
        }
        previous = current;
        current = current->next; // Move to next node
    }

    return false; // Value not found
}

int main() {
    // init head & tail
    nodeType *head = NULL;
    nodeType *tail = NULL;
    int numNodes = 0;

    buildOrderedList(head, tail, numNodes, -999);

    cout << "Ordered list (" << numNodes << " nodes):" << endl;
    printList(head);

    destroyNodeList(head, tail, numNodes);
    return 0;

}
