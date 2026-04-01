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
    node->left = NULL;
    node->right = NULL;
    return node;
}

int cameras = 0;

// DFS function
int dfs(struct TreeNode* root) {
    if (root == NULL) return 2;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;

    if (dfs(root) == 0) {
        cameras++;
    }

    return cameras;
}

// -------- MAIN FUNCTION --------
int main() {
    // Example tree: [0,0,null,0,0]
    struct TreeNode* root = newNode(0);
    root->left = newNode(0);
    root->left->left = newNode(0);
    root->left->right = newNode(0);

    int result = minCameraCover(root);
    printf("Minimum cameras needed: %d\n", result);

    return 0;
}