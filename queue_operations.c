#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
}Queue_S;

Queue_S *create_queue(unsigned capacity)
{
    Queue_S *queue = (Queue_S*)malloc(sizeof(Queue_S));
    queue->front = queue->size = 0;
    queue->capacity = capacity;
    queue->rear = capacity-1;
    queue->array = (int *)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isfull(Queue_S *queue)
{
    return (queue->size == queue->capacity);
}

int isempty(Queue_S *queue)
{
    return (queue->size == 0);
}

void enqueue(Queue_S *queue, int item)
{
    if(isfull(queue))
    {
        printf("Queue is full!\n");
        return;
    }
    queue->rear = (queue->rear+1)%(queue->capacity);
    queue->array[queue->rear]= item;
    queue->size = queue->size+1;
    printf("%i is enqueued\n",item);
}

int dequeue(Queue_S *queue)
{
    if(isempty(queue))
    {
        printf("Queue is empty!\n");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front+1)%(queue->capacity);
    queue->size = queue->size-1;
    return item;
}

int front(Queue_S *queue)
{
    if(isempty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int rear(Queue_S *queue)
{
    if(isempty(queue))
    {
        return INT_MIN;
    }
    return queue->array[queue->rear];
}


int main(void)
{
    Queue_S *new_queue = create_queue(10);
    enqueue(new_queue,1);
    enqueue(new_queue,2);
    enqueue(new_queue,3);
    enqueue(new_queue,4);
    enqueue(new_queue,5);
    printf("%i is in front\n",front(new_queue));
    printf("%i is dequeued\n",dequeue(new_queue));
    printf("%i is in front\n",front(new_queue));
    printf("%i is in rear\n",rear(new_queue));
    
    return 0;
}