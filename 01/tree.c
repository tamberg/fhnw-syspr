#include <stdio.h>

typedef struct node {
    char *label;
    struct node *left;
    struct node *right;
} Node;

int main() {	
	Node *ll;
	ll->label = "I am left left";
	ll->left = NULL;
	ll->right = NULL;
	
	Node *lr;
	lr->label = "I am left right";
	lr->left = NULL;
	lr->right = NULL;

	Node *l;
	l->label = "I am left";
	l->left = ll;
	l->right = lr;

	Node *r;
	r->label = "I am right";
	r->left = NULL;
	r->right = NULL;

	Node *root;
	root->label = "I am root";
	root->left = l;
	root->right = r;
	
	return 0;
}