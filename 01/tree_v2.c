#include <stdio.h>
#include <stdlib.h>

#define MAX_CHILDREN 3

typedef struct node {
    char *label;
    struct node *children[MAX_CHILDREN];
} Node;

int main(void) {
    Node *n00 = malloc(sizeof(Node));
    n00->label = "I am left left";
    n00->children[0] = NULL;
    n00->children[1] = NULL;
    n00->children[2] = NULL;

    Node *n01 = malloc(sizeof(Node));
    n01->label = "I am left middle";
    n01->children[0] = NULL;
    n01->children[1] = NULL;
    n01->children[2] = NULL;

    Node *n02 = malloc(sizeof(Node));
    n02->label = "I am left right";
    n02->children[0] = NULL;
    n02->children[1] = NULL;
    n02->children[2] = NULL;

    Node *n0 = malloc(sizeof(Node));
    n0->label = "I am left";
    n0->children[0] = n00;
    n0->children[1] = n01;
    n0->children[2] = n02;

    Node *n1 = malloc(sizeof(Node));
    n1->label = "I am right";
    n1->children[0] = NULL;
    n1->children[1] = NULL;
    n1->children[2] = NULL;

    Node *root = malloc(sizeof(Node));
    root->label = "I am root";
    root->children[0] = n0;
    root->children[1] = n1;
    root->children[2] = NULL;

    free(root);
    free(n1);
    free(n0);
    free(n02);
    free(n01);
    free(n00);

    return 0;
}