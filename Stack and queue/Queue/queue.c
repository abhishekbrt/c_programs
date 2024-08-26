#include <stdio.h>
#include <stdlib.h>

typedef unsigned capacity_q;
// structure to represent a queue
typedef struct
{
    int front, rear, size;
    capacity_q capacity;
    int *array;
} Queue;

// function to create a queue of given capacity, it initialize the capacity of queue as 0
Queue *initialize(capacity_q capacity)
{
    Queue *que = (Queue *)malloc(sizeof(Queue));
    que->capacity = capacity;
    que->size = 0;
    que->front = 0;
    que->rear = capacity - 1;
    que->array = (int *)malloc(que->capacity * sizeof(int));
    return que;
}

// Queue is full when size become equal to capacity
int isFull(Queue *que)
{
    if (que->size == que->capacity)
    {
        return 1;
    }
    return 0;
}

// Queue is empty when size==0
int isEmpty(Queue *que)
{
    return que->size == 0;
}

// Function to add an item to the queue also called enqueue. it changes the rear and size
void enqueue(Queue *que, int item)
{
    if (isFull(que))
    {
        printf("Queue is already full !!\n");
        return;
    }
    que->rear = (que->rear + 1) % que->capacity;
    que->array[que->rear] = item;
    que->size++;
    printf("%d, enqueued to queue\n", item);
}

// function to remove an item from queue also called dequeue.
void dequeue(Queue *que)
{
    if (isEmpty(que))
    {
        printf("Queue is already empty\n");
        return;
    }
    int item = que->array[que->front];
    que->front = (que->front + 1) % que->capacity;
    que->size--;
    printf("%d, dequeued from queue\n", item);
}

// function to display the elements of the queue
void display(Queue *que)
{
    if (isEmpty(que))
    {
        printf("Queue is empty\n");
        return;
    }
    int i;
    printf("Queue elements: ");
    for (i = que->front; i <= que->rear; i = (i + 1))
    {
        printf("%d ", que->array[i]);
    }
    printf("\n");
}

int main()
{
    Queue *que = initialize(5);
    enqueue(que, 1);
    enqueue(que, 2);
    enqueue(que, 3);
    enqueue(que, 4);
    enqueue(que, 5);
    enqueue(que, 6);
    enqueue(que, 7);
    enqueue(que, 8);
    dequeue(que);
    display(que);
}
