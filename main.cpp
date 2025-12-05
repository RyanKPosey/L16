/*
    Programmer: Ryan Posey
    Assignment: L16B
    Purpose: Practice linked lists
    Due date: 12/2/2025
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
    nodeType* head = NULL;
    nodeType* tail = NULL;
    int searchValue;

    int numNodes = 0;
    buildList(head, tail, numNodes, -999);
    printList(head);

    cout << "Enter a value to search for: ";
    cin >> searchValue;
    cout << endl;
    nodeType* foundNode = search(head, searchValue);

    if (foundNode != NULL) {
        cout << "Value " << searchValue << " found in the list." << endl;
    } else {
        cout << "Value " << searchValue << " not found in the list." << endl;
    }

    int newValue;
    cout << "Enter a value to edit: ";
    cin >> searchValue;
    cout << endl;
    cout << "Enter the new value: ";
    cin >> newValue;
    cout << endl;

    if (editValue(head, searchValue, newValue)) {
        cout << "Value " << searchValue << " edited to " << newValue << "." << endl;
    } else {
        cout << "Value " << searchValue << " not found for editing." << endl;
    }

    cout << "Enter a value to delete: ";
    cin >> searchValue;
    cout << endl;

    if (deleteValue(head, tail, searchValue, numNodes)) {
        cout << "Value " << searchValue << " deleted from the list." << endl;
    } else {
        cout << "Value " << searchValue << " not found for deletion." << endl;
    }

    cout << "Final list contents after edit and deletion:" << endl;
    printList(head);

    destroyNodeList(head, tail, numNodes);

    return 0;
}
