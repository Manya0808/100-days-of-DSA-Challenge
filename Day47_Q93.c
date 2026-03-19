#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue {
    int front, rear, size;
    struct Node** array;
};

struct Node* newNode(int data) {
    if (data == -1)
        return NULL;

    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue* createQueue(int size) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    q->size = size;
    q->array = (struct Node**)malloc(size * sizeof(struct Node*));
    return q;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == q->size - 1)
        return;

    if (q->front == -1)
        q->front = 0;

    q->array[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    if (q->front == -1)
        return NULL;

    struct Node* temp = q->array[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue* q = createQueue(n);

    struct Node* root = newNode(arr[0]);
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue(q);

        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(q, current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(q, current->right);
        }
        i++;
    }

    return root;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + (left > right ? left : right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level order traversal (-1 for NULL): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    printf("Height of Binary Tree = %d\n", height(root));

    return 0;
}