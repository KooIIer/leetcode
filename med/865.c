#include <math.h>
#include <stdio.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

int m(struct TreeNode* root, int d) {
    if (root->left == NULL && root->right == NULL) {
        // printf("%d\n", d);
        return d;
    }
    if (root->left == NULL) {
        return m(root->right, d+1);
    }
    if (root->right == NULL) {
        return m(root->left, d+1);
    }
    return (int)(fmax(m(root->right, d+1), m(root->left, d+1)));
}

struct TreeNode* f(struct TreeNode* root, int d, int md) {
    if (root->left == NULL && root->right == NULL) {
        if (d != md) {
            return NULL;
        }
        return root;
    }
    if (root->left == NULL) {
        return f(root->right, d+1, md);
    }
    if (root->right == NULL) {
        return f(root->left, d+1, md);
    }

    struct TreeNode* right = f(root->right, d+1, md);
    struct TreeNode* left = f(root->left, d+1, md);

    if (right != NULL && left != NULL) {
        return root;
    }
    if (right != NULL) {
        return right;
    }
    return left;
}

struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    int md = m(root, 0);
    printf("md %d\n", md);
   
    struct TreeNode* ans = f(root, 0, md);
    printf("val %d\n", ans->val);

    return 0;
}

int main() {
    TreeNode root = {3, &(TreeNode){5, &(TreeNode){6, NULL, NULL}, &(TreeNode){2, &(TreeNode){7, NULL, NULL}, &(TreeNode){4, NULL, NULL}}}, &(TreeNode){1, &(TreeNode){0, NULL, NULL}, &(TreeNode){8, NULL, NULL}}};


    TreeNode* ans = subtreeWithAllDeepest(&root);
   
    printf("%d: %d, %d\n", ans->val, ans->left->val, ans->right->val);

    return 0;
}
