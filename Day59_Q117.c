#include <stdio.h>
#include <stdlib.h>

// Tree structure
struct Node {
    int val;
    struct Node *left;
    struct Node *right;
};

// Build tree function
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int *postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Create root node
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;

    (*postIndex)--;

    // If only one node
    if (inStart == inEnd)
        return root;

    // Find root in inorder
    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val)
            break;
    }

    // Build right first, then left
    root->right = buildTree(inorder, postorder, i + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, i - 1, postIndex);

    return root;
}

// Preorder traversal (output)
void preorder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    preorder(root);

    return 0;
}