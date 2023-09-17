#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 8
typedef int element;
typedef struct
{
    int front, rear;
    element data[MAX_QUEUE_SIZE];
} DequeType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init_deque(DequeType *q)
{
    q->front = q->rear = 0;
}

int is_empty(DequeType *q)
{
    return (q->front == q->rear);
}

int is_full(DequeType *q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType *q)
{
    printf("Deque (front = %d, rear = %d) = ", q->front, q->rear);
    if (!is_empty(q))
    {
        int i = q->front;
        do
        {
            i = (i + 1) % (MAX_QUEUE_SIZE);
            printf("%d | ", q->data[i]);
            if (i == q->rear)
                break;
        } while (i != q->front);
    }
    printf("\n");
}

element delete_front(DequeType *q)
{
    if (is_empty(q))
        error("Deque is empty");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

element get_front(DequeType *q)
{
    if (is_empty(q))
        error("Deque is empty");
    return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType *q, element val)
{
    if (is_full(q))
        error("Deque is full");
    q->data[q->front] = val;
    q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType *q)
{
    if (is_empty(q))
        error("Deque is empty");
    int prev = q->rear;
    q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
    return q->data[prev];
}

element get_rear(DequeType *q)
{
    if (is_empty(q))
        error("Deque is empty");
    return q->data[q->rear];
}

void add_rear(DequeType *q, element item)
{
    if (is_full(q))
        error("Deque is full");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

int main(void)
{
    DequeType q;

    init_deque(&q);
    for (int i = 0; i < 7; i++)
    {
        add_front(&q, i);
        deque_print(&q);
    }
    for (int i = 0; i < 7; i++)
    {
        delete_rear(&q);
        deque_print(&q);
    }
    return 0;
}