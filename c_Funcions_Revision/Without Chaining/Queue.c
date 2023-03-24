#include<stdio.h>
#define MAX 5

typedef struct QUEUE
{
    int data[MAX];
    int start,end,total;
}Queue;

void push(Queue *f, int num)
{
    if (f->total<MAX)
    {
        f->data[f->end] = num;
        f->end+=1;
        f->end = f->end%MAX; 
        f->total++;
    }
    else
    {
        printf("Queue full!");
    }
}

int pop(Queue *f)
{
    int num;
    if(f->total>0)
    {
        num = f->data[f->start];
        f->start+=1;
        f->start = f->start%MAX; 
        f->total--;
    }
    return num;
}

void print(Queue *f)
{
    for (int i = f->start%MAX; i<(f->total + f->start); i++)
    {
        printf("%d", f->data[i%MAX]);
    }
    printf("\n");
}

int main()
{
    int num;
    Queue f;
    f.start = 0;
    f.end = 0;
    f.total = 0;

    push(&f, 1);
    push(&f, 2);
    push(&f, 3);
    push(&f, 4);
    push(&f, 5);

    print(&f);

    num = pop(&f);

    print(&f);

    push(&f,6);

    print(&f);
}