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

// Wrapper
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1);
}

// Inorder print (to verify)
void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

// Main function
int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[]  = {9, 3, 15, 20, 7};
    int n = 5;

    struct TreeNode* root = buildTree(preorder, n, inorder, n);

    printf("Inorder of constructed tree: ");
    printInorder(root);

    return 0;
}