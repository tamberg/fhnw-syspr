#include <stdio.h>
#include <stdlib.h>

struct node {
    char *label;
    struct node *left;
    struct node *right;
};

int main(void) {	
    // allocate nodes, on the heap
    struct node *ll = malloc(sizeof(struct node));
    ll->label = "left left";
    ll->left = NULL;
    ll->right = NULL;

    struct node *lr = malloc(sizeof(struct node));
    lr->label = "left right";
    lr->left = NULL;
    lr->right = NULL;

    struct node *l = malloc(sizeof(struct node));
    l->label = "left";
    l->left = ll;
    l->right = lr;

    struct node *r = malloc(sizeof(struct node));
    r->label = "right";
    r->left = NULL;
    r->right = NULL;

    struct node *root = malloc(sizeof(struct node));
    root->label = "root";
    root->left = l;
    root->right = r;

    // print node labels
    printf("%s\n", root->label);
    printf("%s\n", root->left->label);
    printf("%s\n", root->left->left->label);
    printf("%s\n", root->left->right->label);
    printf("%s\n", root->right->label);

    // free tree nodes
    free(root->left->left);
    root->left->left = NULL;

    free(root->left->right);
    root->left->right = NULL;

    free(root->left);
    root->left = NULL;

    free(root->right);
    root->right = NULL;

    free(root);
    root = NULL;

    return 0;
}
