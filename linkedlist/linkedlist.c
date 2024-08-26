#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to insert node at the beginning of the list
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// function to insert node at the last of the list
void insertAtLast(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// function to delete a node with a given value
void deleteValue(struct Node **head, int value)
{
    struct Node *temp = *head;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// function to print the linkedlist
void printList(struct Node *list)
{
    while (list != NULL)
    {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 1);
    insertAtLast(&head, 2);
    insertAtLast(&head, 3);
    insertAtBeginning(&head, 4);
    deleteValue(&head, 2);

    printList(head);
}