#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to build tree
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex) {
    
    if (inStart > inEnd)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    if (inStart == inEnd)
        return root;

    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val)
            break;
    }

    root->right = build(inorder, i + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, i - 1, postorder, postIndex);

    return root;
}

// Main function from LeetCode
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, 0, inorderSize - 1, postorder, &postIndex);
}

// Print preorder (just to verify output)
void preorder(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    printf("Enter postorder: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    struct TreeNode* root = buildTree(inorder, n, postorder, n);

    printf("Preorder of constructed tree: ");
    preorder(root);

    return 0;
}