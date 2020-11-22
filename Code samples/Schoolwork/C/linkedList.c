#include <stdlib.h>
#include <stdio.h>

/*
 * Linked list type definitions to be used with Assignment 5.
 * Your program *must* work with this header file.
 * Don't waste server space by submitting a copy, since
 * the TAs will have the file already.  
 *
 * CISC 220, Fall 2016
 * M. Lamb
 */

// A single node in a linked list
struct ListNode {
  int data; // the data in this node
  struct ListNode *next; // point to next node, NULL for last node in the list
};

// Refer to a linked list with a pointer to the first node
// LinkedList is a ListNode* (ptr to a ListNode)

typedef struct ListNode *LinkedList;

/* 
 * Parameters: 
 *    1. a linked list (pointer to the first node, or NULL for an empty list)
 *    2. a value to add to the start of the list
 * Returns a pointer to the start of the modified list.
 */
LinkedList addToStart(LinkedList list, int value){
  LinkedList newNode;
  newNode = malloc(sizeof(LinkedList));
  newNode -> data = value;
  newNode -> next = list;
  return newNode;
}

/* 
 * Parameters: 
 *    1. a linked list (pointer to the first node, or NULL for an empty list)
 *    2. a value to add to the end of the list
 * Returns a pointer to the end of the modified list.
 */
LinkedList addToEnd(LinkedList list, int value){
  LinkedList lastNode;
  lastNode = malloc(sizeof(LinkedList));
  lastNode -> data = value;
  lastNode -> next = NULL;

  if(list==NULL){
    return lastNode;
  }
  LinkedList currentNode = list;
  while(currentNode -> next != NULL){
    currentNode = currentNode -> next;
  }
  currentNode -> next = lastNode;
  return list;
}

/* 
 * Parameter: a linked list (pointer to the first node, 
 *     or NULL for an empty list)
 * Deletes the first element of the linked list and 
 * returns a pointer to the modified list (or NULL if
 * the list is now empty).
 */
LinkedList deleteFirst(LinkedList list){
  if(list == NULL){
    return list;
  }
  LinkedList newList;
  newList = list -> next;
  free(list);
  return newList;
}

/* 
 * Parameter: a linked list (pointer to the first node, 
 *     or NULL for an empty list)
 * Deletes the last element of the linked list and 
 * returns a pointer to the modified list (or NULL if
 * the list is now empty).
 */
LinkedList deleteLast(LinkedList list){
  if(list == NULL){
    return NULL;
  }
  LinkedList currentNode = list;
  if(currentNode -> next == NULL){
    free(currentNode);
    return NULL;
  }
  while(currentNode -> next -> next != NULL){
    currentNode = currentNode -> next;
  }
  free(currentNode -> next);
  currentNode -> next = NULL;
  return list;
}

/*
 * Parameter: a linked list of numbers.
 * Prints the list to the standard output in a format like this: [1,2,3,4] --
 * enclosed in square brackets, numbers separated by commas, and no spaces.
 * Follows the list with an end of line character.
 */
void printList(LinkedList list){
  LinkedList currentNode = list;
  if (list == NULL){
    printf("[]");
    return;
  }
  printf("[");
  while(currentNode -> next != NULL){
    printf("%d,", currentNode -> data);
    currentNode = currentNode -> next;
  }
  printf("%d", currentNode -> data);
  printf("]\n");
  return;
}

/*
 * Parameters:
 *   1. a linked list of numbers
 *   2. a value to search for
 * Searches the list and returns 1 if the value occurs
 * at least once in the list and 0 if it does not.
 */
int search(LinkedList list, int value){
  LinkedList currentNode = list;
  while (currentNode != NULL){
    if (currentNode -> data == value){
      return 1;
    }
    currentNode = currentNode -> next;
  }
  return 0;
}
