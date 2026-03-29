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

// Mirror function
void mirror(struct TreeNode* root) {
    if (root == NULL) return;

    // Swap left and right
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recur for children
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Build tree from array (level order)
struct TreeNode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) return NULL;

    struct TreeNode* root = newNode(arr[i]);

    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Main
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* root = buildTree(arr, n, 0);

    mirror(root);

    inorder(root);

    return 0;
}