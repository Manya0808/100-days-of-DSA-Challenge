#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct TreeNode** arr;
    int front, rear;
};

struct Queue* createQueue(int n) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * n);
    q->front = q->rear = 0;
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* node) {
    q->arr[q->rear++] = node;
}

struct TreeNode* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

struct TreeNode* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Queue* q = createQueue(n);
    struct TreeNode* root = createNode(arr[0]);
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct TreeNode* curr = dequeue(q);

        if (i < n && arr[i] != -1) {
            curr->left = createNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

void levelOrder(struct TreeNode* root) {
    if (!root) return;

    struct Queue* q = createQueue(1000);
    enqueue(q, root);

    while (q->front < q->rear) {
        int levelSize = q->rear - q->front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = dequeue(q);
            printf("%d ", node->val);

            if (node->left)
                enqueue(q, node->left);
            if (node->right)
                enqueue(q, node->right);
        }
        printf("\n"); 
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}