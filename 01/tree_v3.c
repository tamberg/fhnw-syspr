#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char label[32];
    struct node *left;
    struct node *right;
};

int main(void) {	
    // allocate nodes, on the heap
    struct node *ll = malloc(sizeof(struct node));
    strcpy(ll->label, "left left");
    ll->left = NULL;
    ll->right = NULL;

    struct node *lr = malloc(sizeof(struct node));
    strcpy(lr->label, "left right");
    lr->left = NULL;
    lr->right = NULL;

    struct node *l = malloc(sizeof(struct node));
    strcpy(l->label, "left");
    l->left = ll;
    l->right = lr;

    struct node *r = malloc(sizeof(struct node));
    strcpy(r->label, "right");
    r->left = NULL;
    r->right = NULL;

    struct node *root = malloc(sizeof(struct node));
    strcpy(root->label, "root");
    root->left = l;
    root->right = r;

    // print labels, depth-first
    printf("%s\n", root->label);
    printf("%s\n", root->left->label);
    printf("%s\n", root->left->left->label);
    printf("%s\n", root->left->right->label);
    printf("%s\n", root->right->label);

    // free nodes, leaves-first
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
