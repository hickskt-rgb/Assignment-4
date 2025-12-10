#include "LinkedList.h"

int main(){

    //initialize file pointer to NULL 
    FILE *infile = NULL; 
    //Define a character array to store the name of the file to read and write
    char filename[MAX_LINE_SIZE];  
    //Prompt the user to input a filename and continue to prompt the user until they enter a correct one
    while(infile == NULL) {  
        printf("Enter filename: ");  
        scanf("%s",filename);
        //When given a filename, use fopen to create a new file pointer. 
            //If fopen can not find the file, it returns null
        infile = fopen(filename, "r");
        if(infile == NULL){ 
            printf("ERROR: file %s cannot be opened\n", filename);
        }
    }

    //Test your linked list functions here!!!
    
    printf("\n=== Testing createList ===\n");
    struct Node* myList = createList(infile);
    
    if (myList == NULL) {
        printf("List is empty or file was empty.\n");
    } else {
        printf("List created successfully!\n");
    }
    
    printf("\n=== Testing traverse ===\n");
    traverse(myList);
    
    printf("\n=== Testing removeNode (removing index 0) ===\n");
    struct Node* removed = removeNode(&myList, 0);
    if (removed != NULL) {
        printf("Removed node with data: %s\n", removed->data);
        freeNode(removed);
    }
    
    printf("\n=== List after removal ===\n");
    traverse(myList);
    
    printf("\n=== Testing createNode and insertAtEnd ===\n");
    struct Node* newNode = createNode("Test Node");
    insertAtEnd(&myList, newNode);
    
    printf("\n=== List after insertion ===\n");
    traverse(myList);
    
    printf("\n=== Testing freeList ===\n");
    freeList(&myList);
    printf("List freed successfully!\n");
    
    if (myList == NULL) {
        printf("Head is now NULL as expected.\n");
    }

    fclose(infile);

    return 0;
}
