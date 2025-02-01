/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  // first, base case (if no more nodes available)
  if (in == nullptr) {
    return;
  }

  // need to keep track of next node before modifying in
  Node* nextNode = in->next;

  // remove node
  in->next = nullptr;

  // if in value even
  if (in->value % 2 == 0) {
    in->next = evens; // insert in front
    evens = in; // move evens pointer
  }

  // if in value odd
  else {
    in->next = odds; // insert in front
    odds = in; // move odds pointer
  }

  in = nextNode;

  // call recursive function
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */

// {1, 2, 5, 6, 7, 8, 11, 14, 16, 19, 25, 27}

// {1, 5, 7, 11, 19, 25, 27}
// {2, 6, 8, 14, 16}
