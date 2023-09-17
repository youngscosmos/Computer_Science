#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct
{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType; // Create Queue by using structure

void error(char *message) // error function
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q) // set front and rear as -1
{
    q->rear = -1;
    q->front = -1;
}

void queue_print(QueueType *q) // function of print queue
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        if (i <= q->front || i > q->rear)
            printf(" | ");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int is_full(QueueType *q) // check queue is full or not
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType *q) // check queue is empty or not
{
    if (q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(QueueType *q, int item)
{
    if (is_full(q))
    {
        error("queue is full");
        return;
    }
    else
        q->data[++(q->rear)] = item;
}

int dequeue(QueueType *q)
{
    if (is_empty(q))
    {
        error("queue is empty");
        return -1;
    }
    int item = q->data[++(q->front)];
    return item;
}

int main(void)
{
    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 1);
    queue_print(&q);
    enqueue(&q, 2);
    queue_print(&q);
    enqueue(&q, 3);
    queue_print(&q);

    dequeue(&q);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);
    dequeue(&q);
    queue_print(&q);

    return 0;
}