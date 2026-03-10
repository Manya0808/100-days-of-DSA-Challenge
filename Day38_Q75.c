#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

int empty() {
    return (front == -1);
}

int size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

void push_front(int x) {
    if (front == -1) {
        front = rear = 0;
        deque[front] = x;
    }
    else if (front > 0) {
        front--;
        deque[front] = x;
    }
    else {
        printf("Deque Overflow\n");
    }
}

void push_back(int x) {
    if (rear == MAX-1) {
        printf("Deque Overflow\n");
        return;
    }

    if (front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void get_front() {
    if (empty())
        printf("Deque Empty\n");
    else
        printf("Front: %d\n", deque[front]);
}

void get_back() {
    if (empty())
        printf("Deque Empty\n");
    else
        printf("Back: %d\n", deque[rear]);
}

void clear() {
    front = rear = -1;
    printf("Deque Cleared\n");
}

void reverse() {
    if (empty()) return;

    int i = front, j = rear;
    while (i < j) {
        int temp = deque[i];
        deque[i] = deque[j];
        deque[j] = temp;
        i++;
        j--;
    }
}

void sort() {
    for (int i = front; i <= rear; i++) {
        for (int j = i+1; j <= rear; j++) {
            if (deque[i] > deque[j]) {
                int temp = deque[i];
                deque[i] = deque[j];
                deque[j] = temp;
            }
        }
    }
}

void display() {
    if (empty()) {
        printf("Deque Empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    int choice, value;

    while(1) {
        printf("\n1 push_front\n2 push_back\n3 pop_front\n4 pop_back\n");
        printf("5 front\n6 back\n7 size\n8 empty\n9 clear\n10 reverse\n11 sort\n12 display\n13 exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                printf("Size: %d\n", size());
                break;

            case 8:
                if(empty())
                    printf("Deque is Empty\n");
                else
                    printf("Deque is Not Empty\n");
                break;

            case 9:
                clear();
                break;

            case 10:
                reverse();
                break;

            case 11:
                sort();
                break;

            case 12:
                display();
                break;

            case 13:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}