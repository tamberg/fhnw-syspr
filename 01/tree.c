#include <stdio.h>
#include <stdlib.h>

struct node {
    char *label;
    struct node *left;
    struct node *right;
};

int main(void) {
    struct node ll = { "left left", NULL, NULL };
    struct node lr = { "left right", NULL, NULL };
    struct node l = { "left", &ll, &lr };
    struct node r = { "right", NULL, NULL };
    struct node n = { "root", &l, &r };

    struct node *root = &n;
    printf("%s\n", root->label);
    printf("%s\n", root->left->label);
    printf("%s\n", root->left->left->label);
    printf("%s\n", root->left->right->label);
    printf("%s\n", root->right->label);

    return 0;
}
