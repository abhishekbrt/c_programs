#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;

} Node;

typedef struct
{
    Node *top;
} Stack;

// function to create a new node
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("memory allocation failed \n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// function to intilize the stack
void initialize(Stack *s)
{
    s->top = NULL;
}

// function to check if the array is empty
int isEmpty(Stack *s)
{
    return s->top == NULL;
}

// function to push an element into stack
void push(Stack *s, int data)
{
    Node *node = createNode(data);
    node->next = s->top;
    s->top = node;
    printf("%d pushed to stack\n", data);
}

// function to pop an elment from stack
int pop(Stack *s)
{
    if (isEmpty(s))
    {
        printf("cannot pop from empty stack\n");
        return -1;
    }
    Node *temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    printf("%d popped from stack\n", poppedValue);
    return poppedValue;
}

// function to peek at the top element of the stack
int peek(Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty \n");
        return -1;
    }
    return s->top->data;
}

// function to display the stack
void display(Stack *s)
{
    if (isEmpty(s))
    {
        printf("stack is empty\n");
        return;
    }
    Node *current = s->top;
    while (current != NULL)
    {
        printf("%d ,", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Stack s;
    initialize(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    push(&s,7);
    push(&s,8);
    display(&s);
    // struct Stack t;
    return 0;
}