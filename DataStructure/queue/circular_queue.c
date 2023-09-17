#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 8
typedef int element;
typedef struct
{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char *message) // error function
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) // check queue is empty or not
{
    return (q->front == q->rear);
}

int is_full(QueueType *q) // check queue is full or not
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void queue_print(QueueType *q)
{
    printf("Queue : (front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q)) // check queue is empty or not
    {
        int i = q->front;
        do
        {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear) // break recursion when front == rear
                break;
        } while (i != q->front);
    }
    printf("\n");
}

void enqueue(QueueType *q, element item)
{
    if (is_full(q))
        error("queue is full");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) // pull out element from index(front + 1)
{
    if (is_empty(q))
        error("Queue is empty");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element peek(QueueType *q) // show element of front of queue
{
    if (is_empty(q))
        error("Queue is empty");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

int main(void)
{
    QueueType q;
    int tmp;

    init_queue(&q);
    while (!is_full(&q)) // push until queue will be full
    {
        printf("type integer: ");
        scanf("%d", &tmp);
        enqueue(&q, tmp);
        queue_print(&q);
    }
    printf("queue is full\n");

    while (!is_empty(&q)) // pull out until queue will be empty
    {
        tmp = dequeue(&q);
        printf("integer that is pulled out : %d \n", tmp);
        queue_print(&q);
    }
    printf("queue is empty\n");
    return 0;
}
