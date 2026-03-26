#include <stdio.h>
#include <stdlib.h>

// Tree structure
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

// Queue implementation
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

// Zigzag function
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct Queue* q = createQueue(100);
    enqueue(q, root);

    int** result = (int**)malloc(100 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(100 * sizeof(int));

    int level = 0;
    int leftToRight = 1;

    while (!isEmpty(q)) {
        int size = q->size;
        result[level] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);

            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        leftToRight = !leftToRight;
        level++;
    }

    *returnSize = level;
    return result;
}

// Print result
void printResult(int** arr, int returnSize, int* colSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < colSizes[i]; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("]\n");
    }
}

// MAIN
int main() {
    /*
        Tree:
            3
           / \
          9  20
             / \
            15  7
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    int returnSize;
    int* returnColumnSizes;

    int** result = zigzagLevelOrder(root, &returnSize, &returnColumnSizes);

    printResult(result, returnSize, returnColumnSizes);

    return 0;
}