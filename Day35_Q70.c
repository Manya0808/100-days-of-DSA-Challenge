#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int s1[MAX];
    int s2[MAX];
    int top1;
    int top2;
} MyQueue;

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->s1[++obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
    return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top2 == -1){
        while(obj->top1 != -1){
            obj->s2[++obj->top2] = obj->s1[obj->top1--];
        }
    }
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

int main() {

    MyQueue* q = myQueueCreate();

    myQueuePush(q,1);
    myQueuePush(q,2);
    myQueuePush(q,3);

    printf("Front element: %d\n", myQueuePeek(q));

    printf("Popped: %d\n", myQueuePop(q));

    printf("Front after pop: %d\n", myQueuePeek(q));

    if(myQueueEmpty(q))
        printf("Queue is Empty\n");
    else
        printf("Queue is Not Empty\n");

    return 0;
}