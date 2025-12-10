#include "LinkedList.h"

/**
 * Creates a new Node with the given data
 * Dynamically allocates memory for both the node and its data
 */
struct Node* createNode(char* data) {
    // Allocate memory for new Node struct
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if malloc succeeded
    if (newNode == NULL) {
        return NULL;
    }
    
    // Allocate memory for character array to store data
    // +1 for null terminator
    newNode->data = (char*)malloc((strlen(data) + 1) * sizeof(char));
    
    // Check if malloc succeeded
    if (newNode->data == NULL) {
        free(newNode);
        return NULL;
    }
    
    // Copy the data into the newly allocated memory
    strcpy(newNode->data, data);
    
    // Initialize next pointer to NULL (single node has no next)
    newNode->next = NULL;
    
    return newNode;
}

/**
 * Inserts a node at the end of the linked list
 */
void insertAtEnd(struct Node** head, struct Node* newNode) {
    // Check if head parameter itself is NULL
    if (head == NULL) {
        return;
    }
    
    // If the list is empty (head points to NULL)
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    // Append newNode to the end
    current->next = newNode;
}

/**
 * Creates a linked list from a file
 * Reads file line by line and creates nodes for each line
 */
struct Node* createList(FILE* inf) {
    // Check if file pointer is valid
    if (inf == NULL) {
        return NULL;
    }
    
    // Initialize head of list
    struct Node* head = NULL;
    
    // Buffer to store each line from file
    char fileLine[MAX_LINE_SIZE];
    
    // Read file line by line
    while (fgets(fileLine, MAX_LINE_SIZE, inf) != NULL) {
        // Remove trailing newline character
        fileLine[strcspn(fileLine, "\n")] = 0;
        
        // Create new node with the line data
        struct Node* newNode = createNode(fileLine);
        
        // Check if node creation succeeded
        if (newNode != NULL) {
            // Insert node at end of list
            insertAtEnd(&head, newNode);
        }
    }
    
    return head;
}

/**
 * Removes a node at the specified index from the list
 * Returns pointer to removed node
 */
struct Node* removeNode(struct Node** head, int index) {
    // Check edge cases
    if (head == NULL || *head == NULL || index < 0) {
        return NULL;
    }
    
    struct Node* nodeToRemove;
    
    // Special case: removing head node (index 0)
    if (index == 0) {
        nodeToRemove = *head;
        *head = (*head)->next;
        nodeToRemove->next = NULL; // Disconnect from list
        return nodeToRemove;
    }
    
    // Traverse to node before the one to remove
    struct Node* current = *head;
    int currentIndex = 0;
    
    // Stop at node before target (or end of list)
    while (current->next != NULL && currentIndex < index - 1) {
        current = current->next;
        currentIndex++;
    }
    
    // Check if index is out of bounds
    if (current->next == NULL) {
        return NULL;
    }
    
    // Remove the node
    nodeToRemove = current->next;
    current->next = nodeToRemove->next;
    nodeToRemove->next = NULL; // Disconnect from list
    
    return nodeToRemove;
}

/**
 * Traverses the list and prints each node's data
 */
void traverse(struct Node* head) {
    struct Node* current = head;
    
    // Traverse through entire list
    while (current != NULL) {
        // Print data field of current node
        printf("%s\n", current->data);
        
        // Move to next node
        current = current->next;
    }
}

/**
 * Frees memory for a single node
 * Must free both the data and the node itself
 */
void freeNode(struct Node* aNode) {
    // Check if node pointer is valid
    if (aNode == NULL) {
        return;
    }
    
    // Free the dynamically allocated data
    if (aNode->data != NULL) {
        free(aNode->data);
    }
    
    // Free the node itself
    free(aNode);
}

/**
 * Frees memory for entire linked list
 * Traverses list and frees each node
 */
void freeList(struct Node** head) {
    // Check if head parameter itself is NULL
    if (head == NULL) {
        return;
    }
    
    struct Node* current = *head;
    struct Node* next;
    
    // Traverse and free each node
    while (current != NULL) {
        next = current->next;  // Save next node before freeing current
        freeNode(current);      // Free current node
        current = next;         // Move to next node
    }
    
    // Set head to NULL
    *head = NULL;
}
