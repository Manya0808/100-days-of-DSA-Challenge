#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Queue for building + traversal
struct Queue {
    struct TreeNode** arr;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int cap) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = cap;
    q->front = 0;
    q->size = 0;
    q->rear = cap - 1;
    q->arr = (struct TreeNode**)malloc(cap * sizeof(struct TreeNode*));
    return q;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = node;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}

// Build tree from level order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue* q = createQueue(n);
    struct TreeNode* root = newNode(arr[0]);
    enqueue(q, root);

    int i = 1;
    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        // left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }
    return root;
}

// Zigzag traversal (single line output)
void zigzagTraversal(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    int leftToRight = 1;

    while (!isEmpty(q)) {
        int size = q->size;

        int* level = (int*)malloc(size * sizeof(int));

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);

            int index = leftToRight ? i : (size - 1 - i);
            level[index] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        // print this level
        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        free(level);
        leftToRight = !leftToRight;
    }
}

// MAIN
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}