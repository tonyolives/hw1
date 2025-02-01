/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

#include <iostream>
#include "split.h"

// Function to create a linked list from an array
Node* createList(int arr[], int size) {
    if (size == 0) return nullptr; // Handle empty list case

    Node* head = new Node(arr[0], nullptr);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        tail->next = new Node(arr[i], nullptr);
        tail = tail->next;
    }

    return head;
}

// Function to print a linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->value << " -> ";
        head = head->next;
    }
    std::cout << "nullptr\n";
}

// Function to free allocated memory
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(int argc, char* argv[])
{
    // Define input array
    int values[] = {1, 2, 5, 6, 7, 8, 11, 14, 16, 19, 25, 27};
    int size = sizeof(values) / sizeof(values[0]);

    // Create linked list
    Node* inputList = createList(values, size);

    // Initialize output lists
    Node* odds = nullptr;
    Node* evens = nullptr;

    // Call the split function
    split(inputList, odds, evens);

    // Print results
    std::cout << "Odds: ";
    printList(odds);

    std::cout << "Evens: ";
    printList(evens);

    // Free allocated memory
    deleteList(odds);
    deleteList(evens);

    return 0;
}
