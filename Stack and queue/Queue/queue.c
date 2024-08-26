#include <stdio.h>
#include<stdlib.h>

//structure to represent a queue
typedef struct Queue {
    int front,rear,size;
    unsigned capacity;
    int* array;
} Queue;

//function to create a queue of given capacity, it initialize the size of queue as 0

Queue* initialize(unsigned size){
    Queue *que=(Queue*)malloc(sizeof(Queue));
    

};
