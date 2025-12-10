#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Creates a new Node with the given data
 * @param data - character array to store in the node
 * @return pointer to newly created Node
 */
struct Node* createNode(char* data);

/**
 * Inserts a node at the end of the linked list
 * @param head - pointer to pointer to head of list
 * @param newNode - node to insert at end
 */
void insertAtEnd(struct Node** head, struct Node* newNode);

/**
 * Creates a linked list from a file
 * @param inf - pointer to opened file
 * @return pointer to head of newly created list
 */
struct Node* createList(FILE* inf);

/**
 * Removes a node at the specified index
 * @param head - pointer to pointer to head of list
 * @param index - index of node to remove
 * @return pointer to removed node, or NULL if invalid
 */
struct Node* removeNode(struct Node** head, int index);

/**
 * Traverses the list and prints each node's data
 * @param head - pointer to head of list
 */
void traverse(struct Node* head);

/**
 * Frees memory for a single node
 * @param aNode - pointer to node to free
 */
void freeNode(struct Node* aNode);

/**
 * Frees memory for entire linked list
 * @param head - pointer to pointer to head of list
 */
void freeList(struct Node** head);

#endif
