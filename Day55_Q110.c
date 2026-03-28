#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }

    struct TreeNode** queue = malloc(10000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    int* result = malloc(10000 * sizeof(int));
    int size = 0;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;

        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* node = queue[front++];

           
            if (i == levelSize - 1) {
                result[size++] = node->val;
            }

            if (node->left) queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
    }

    *returnSize = size;
    return result;
}