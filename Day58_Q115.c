#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find index in inorder
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

// Build tree
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = newNode(rootVal);

    int inIndex = findIndex(inorder, inStart, inEnd, rootVal);
    int leftSize = inIndex - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd);

    return root;
}

// Postorder traversal (LEFT RIGHT ROOT)
void printPostorder(struct TreeNode* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    // Input inorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    struct TreeNode* root = build(preorder, 0, n - 1,
                                 inorder, 0, n - 1);

    // Output postorder
    printPostorder(root);

    return 0;
}