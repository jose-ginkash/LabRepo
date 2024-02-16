// Jose N. Mathew
// 2/9/24
// COP3502C - 24 Spring 0040


#include <stdio.h>
#include <stdlib.h>


typedef struct node 
{
    char letter;
    struct node* next;
} node;


// Returns number of nodes in the linkedList.
int length(node* head) 
{
    int length = 0;
    while (head != NULL) 
    {
        length++;
        head = head->next;
    }
    return length;
}


// Parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head) 
{
    int len = length(head);
    char* str = (char*)malloc(len + 1); // +1 is for null terminator
    char* tempp = str; // Temporary pointer to fill string
    while (head != NULL) 
    {
        *tempp++ = head->letter; // Copy letter from node to string
        head = head->next;
    }
    *tempp = '\0'; // Null-terminate string
    return str;
}


// Inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) 
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->letter = c;
    newnode->next = NULL;

    if (*pHead == NULL) // If list is empty, set new node as head
    {
        *pHead = newnode;
    } 
    else 
    {
        node* tempp = *pHead;
        while (tempp->next != NULL) 
        {
            tempp = tempp->next;
        }
        tempp->next = newnode; // Link last node to new node
    }
}


// Deletes all nodes in the linkedList.
void deleteList(node** pHead) 
{
    node* tempp;
    while (*pHead != NULL) // Go through the list
    {
        tempp = *pHead; // Holds the current node
        *pHead = (*pHead)->next; // Move to the next node
        free(tempp); // Free memory of current node
    }
}


int main(void) 
{
    int i, strLen, numberInputs;
    node* head = NULL;
    char* str;
    char c;
    FILE* inFile = fopen("input.txt", "r");
    fscanf(inFile, " %d\n", &numberInputs);
    while (numberInputs-- > 0) 
    {
        fscanf(inFile, " %d\n", &strLen);
        for (i = 0; i < strLen; i++) 
        {
            fscanf(inFile, " %c", &c);
            insertChar(&head, c);
        }
        str = toCString(head);
        printf("String is : %s\n", str);
        free(str);
        deleteList(&head);
        if (head != NULL) 
        {
            printf("deleteList is not correct!");
            break;
        }
    }
    fclose(inFile);
}
