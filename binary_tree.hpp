#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <vector>

using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* enable this for testing */
#define TESTING 1;

struct node* newNode(int data);

/* traversals */
void inOrder(struct node *root);
void preOrder(struct node *root);
void postOrder(struct node *root);

/* insert apis */
void insertToLeftOf(struct node *node, int data);
void insertToRightOf(struct node *node, int data);

int size(struct node* node);
int maxDept(struct node*);
int minValue(struct node* node);
int maxValue(struct node* node);
void path_to_element(struct node *root, vector<int> vec, int element);
int hasPathSum(struct node* node, int sum);
void printPaths(struct node *root, vector<int> vec);
struct node* mirror(struct node* node);
void doubleTree(struct node* node);
int sameTree(struct node* a, struct node* b);
int isBST(struct node* node);
int isBSTRecur(struct node * node, int min, int max);
int isBST2(struct node* node);
struct node* treeToList(struct node* node);
void printTreeToListBidirectional(struct node * node, int size);