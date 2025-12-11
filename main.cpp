/*
    Programmer: Ryan Posey
    Assignment: L16
    Purpose: Practice linked lists
    Due date: 12/10/2025
*/
#include <iostream>
#include "personType.h"
#include "studentType.h"
#include "professorType.h"

using namespace std;

struct personNode {
    personType* data;
    personNode* next;
};

void insertOrdered(personNode*& head, personNode*& tail, personType* value, int& numNodes) {
    // Create new node
    personNode* newNode = new personNode;
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty or new node should be the first node
    // Use operator< overload by dereferencing pointers
    if (head == NULL || *value < *head->data) {
        newNode->next = head;
        head = newNode;
        if (tail == NULL) {
            tail = newNode; // If list was empty, set tail to new node
        }
    } else {
        // Traverse to find the correct position using operator<
        personNode* current = head;
        while (current->next != NULL && *current->next->data < *value) {
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

/* 
void buildOrderedList(personNode*& head, personNode*& tail, int& numNodes, int sentinel) {
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
*/
/* 
void buildList(personNode*& head, personNode*& tail, int& numNodes, int sentinel) {
    // temp node
    personNode* newNode = nullptr;

    int nodeValue;

    // get user input
    cout << "Type a value to add to the linked list (type " << sentinel << " to quit): ";
    cin >> nodeValue;
	 cout << endl;

    // populate linked list
    while (nodeValue != sentinel) {
        // init new node
        newNode = new personNode;

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
    */

void destroyNodeList(personNode*& head, personNode*& tail, int& numNodes) {
    // Traverse linked list
    personNode* current = head;

    while (current != NULL) {
        personNode* previous = current;
        current = current->next;
        delete previous->data; // Delete personType data
        delete previous; // Delete node
        numNodes--; // Decrement node count
    }

    head = NULL;
    tail = NULL;
}

void printList(personNode* head) {
    // Traverse linked list using overloaded operator<<
    const personNode* current = head;
    while (current != NULL) {
        cout << *(current->data) << endl;  // Dereference and use operator<<
        current = current->next; // Move to next node
    }
}

/* personNode* search(personNode* head, int key) {
    personNode* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current; // Found the value
        }
        current = current->next; // Move to next node
    }

    return NULL; // Value not found
} */

/* bool editValue(personNode* head, int oldValue, int newValue) {
    personNode* targetNode = search(head, oldValue);

    if (targetNode != NULL) {
        targetNode->data = newValue;
        return true; // Edit successful
    }

    return false; // Value not found
} */

/* bool deleteValue(personNode*& head, personNode*& tail, int key, int& numNodes) {
    personNode* current = head;
    personNode* previous = NULL;

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
            delete current->data; // Delete personType data 
            delete current;
            numNodes--; // Decrement node count
            return true; // Deletion successful
        }
        previous = current;
        current = current->next; // Move to next node
    }

    return false; // Value not found
} */

int main() {
    // init head & tail
    personNode *head = NULL;
    personNode *tail = NULL;
    int numNodes = 0;

    professorType* professor1 = new professorType("Alan", "Turing", "1 Computation Way", 72.0,
                           "1912-06-23", 'M', 41,
                           "E123", "CS", "PhD");
    professorType* professor2 = new professorType("Ada", "Lovelace", "2 Computation Way", 65.0,
                           "1815-12-10", 'F', 36,
                           "E124", "CS", "MSc");
    studentType* student1 = new studentType("Grace", "Hopper", 3.8, "CS", "S123");
    studentType* student2 = new studentType("Donald", "Knuth", 3.9, "CS", "S124");
    studentType* student3 = new studentType("Joe", "Mama", 3.95, "CS", "S125");
    
    insertOrdered(head, tail, professor1, numNodes);
    insertOrdered(head, tail, professor2, numNodes);
    insertOrdered(head, tail, student1, numNodes);
    insertOrdered(head, tail, student2, numNodes);
    insertOrdered(head, tail, student3, numNodes);

    cout << "Ordered list (" << numNodes << " nodes):" << endl;
    printList(head);

    destroyNodeList(head, tail, numNodes);
    return 0;

}
