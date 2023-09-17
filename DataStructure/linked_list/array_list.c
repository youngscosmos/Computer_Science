#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 200

typedef int element;
typedef struct
{
    int size;
    element array[MAX_LIST_SIZE];
} ArrayListType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType *al)
{
    al->size = 0;
}

int is_empty(ArrayListType *al)
{
    return al->size == 0;
}

int is_full(ArrayListType *al)
{
    return al->size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *al, int pos)
{
    if (pos < 0 || pos >= al->size)
        error("position error");
    return al->array[pos];
}

void print_list(ArrayListType *al)
{
    int i;
    for (i = 0; i < al->size; i++)
        printf("%d->", al->array[i]);
    printf("\n");
}

void insert_last(ArrayListType *al, element item)
{
    if (al->size >= MAX_LIST_SIZE)
        error("list overflow");
    al->array[al->size++] = item;
}

void insert(ArrayListType *al, int pos, element item)
{
    if (!is_full(al) && (pos >= 0) && (pos <= al->size))
    {
        for (int i = (al->size - 1); i >= pos; i--)
            al->array[i + 1] = al->array[i];
        al->array[pos] = item;
        al->size++;
    }
}

element delete(ArrayListType *al, int pos)
{
    element item;

    if (pos < 0 || pos >= al->size)
        error("position error");
    item = al->array[pos];
    for (int i = pos; i < (al->size - 1); i++)
        al->array[i] = al->array[i + 1];
    al->size--;
    return item;
}

int main(void)
{
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10);
    print_list(&list);
    insert(&list, 0, 20);
    print_list(&list);
    insert(&list, 0, 30);
    print_list(&list);
    insert_last(&list, 40);
    print_list(&list);
    delete (&list, 0);
    print_list(&list);
    return 0;
}