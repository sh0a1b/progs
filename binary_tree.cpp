/*
 * Binary Tree APIs
 * various problems related to binary tree and ordered binary tree(BST) are implemented here.
 * these problems are taken from: 'http://cslibrary.stanford.edu/110/BinaryTrees.html'
 * feel free to use/refer the implementation.
 * These are my implementations, please refer the link for other solutions.
 */

#include "binary_tree.hpp"

struct node* newNode(int data) {
    struct node *node = new(struct node);
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    /* make sure you free it */
    return node;
}

void inOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%d  ", root->data);
    inOrder(root->right);
}

void preOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d  ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(struct node *root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->data);
}

/*void insertToLeftOf(struct node *node, int data) {
    struct node *new_node = newNode(data);
    node->left = new_node;
}
void insertToRightOf(struct node *node, int data) {
    struct node *new_node = newNode(data);
    node->right = new_node;
}*/

/* increasing level of difficulty */
int size(struct node* node) {
    static int count = 0;
    if (node == NULL) {
        return(count);
    } else {
        count++;
        size(node->left);
        size(node->right);
    }
    return(count);
}

int max(int a, int b) {
    return ((a >= b) ? a : b);
}
int maxDept(struct node* node) {
    if (node == NULL) {
        return 0;
    } else {
        return max(maxDept(node->left), maxDept(node->right)) + 1;
    }
}

/* min value in a non-empty BST */
int minValue(struct node* node) {
    /* traverse to the left-most leaf-node and print its value */
    if (node == NULL) {
        return -1;
    }
    while(node) {
        if(node->left) {
            node = node->left;
        } else {
            break;
        }
    }
    return node->data;
}
/* max value in a non-empty BST */
int maxValue(struct node* node) {
    /* traverse to the left-most leaf-node and print its value */
    /*if (node == NULL) {
        return -1;
    }*/
    while(node) {
        if (node->right) {
            node = node->right;
        } else {
            break;
        }
    }
    return node->data;
}

void print_vector(vector<int> vec) {
    vector<int>::iterator ptr;
    for (ptr = vec.begin(); ptr < vec.end(); ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");
}

void path_to_element(struct node *root, vector<int> vec, int element) {
    if (root == NULL) {
        return;
    } else {
        if (root->data == element) {
            vec.push_back(root->data);
            print_vector(vec);
            return;
        } else {
            vec.push_back(root->data);
        }
        path_to_element(root->left, vec, element);
        path_to_element(root->right, vec, element);
        
    }
}

int hasPathSum(struct node* node, int sum) {
    static int found = 0;
    /* 
     * check for sum when processing a leaf node
     * changes are an internal node with left or right leaf node might be empty
     * if we process when root = NULL(while recursing), then for non-path we get a true
     * ex failure: root=1, root->left=2, sum=1
     */
    if (node->left == NULL && node->right == NULL) {
        
        found = (found || node->data == sum) ? 1 : 0;
    } else {
        sum -= node->data;
        node->left && hasPathSum(node->left, sum);
        node->right && hasPathSum(node->right, sum);
    }
    return found;
}

/* 
 * passing an array to a recursive function, keep in mind that the array will be different at each level
 */
void printPaths(struct node *root, vector<int> vec) {
    if (root->left == NULL && root->right == NULL) {
        vec.push_back(root->data);
        print_vector(vec);
        //vec.pop_back();
        return;
    } else {
        vec.push_back(root->data);
        if(root->left) {
            printPaths(root->left, vec);
        }
        if(root->right) {
            printPaths(root->right, vec);
        }
    }
}

struct node* mirror(struct node* node) {
    if (node == NULL) {
        return NULL;
    } else {
        struct node* temp;
        temp = node->left;
        node->left = mirror(node->right);
        node->right = mirror(temp);
    }
    return node;
}

void doubleTree(struct node* node) {
    if (node == NULL) {
        return;
    } else {
        struct node* temp;
        doubleTree(node->left);
        temp = node->left;
        node->left = newNode(node->data);
        node->left->left = temp;
        doubleTree(node->right);
    }
}

int sameTree(struct node* a, struct node* b) {
    static int same = 1;
    if (a == NULL && b == NULL) {
        return same;
    } else {
        if ((a && b) && (a->data == b->data)) {
            sameTree(a->left, b->left);
            sameTree(a->right, b->right);
        } else {
            /* they are different */
            same = 0;
        }
    }
    return same;
}

/* countTrees implementation is missing */

/* check if the tree is a Binary Search Tree */
int isBST(struct node* node) {
    static int bst = 1;
    if(node == NULL) {
        return bst;
    } else if (node->left && node->data < maxValue(node->left)) {
        bst = 0;
    } else if (node->right && node->data >= minValue(node->right)) {
        bst = 0;
    }
    isBST(node->left);
    isBST(node->right);
    return bst;
}

/* effecient way to check if a tree is BST */
int isBSTRecur(struct node * node, int min, int max) {
    static int bst=1;
    if (node == NULL) {
        return bst;
    } else if (node->data < min || node->data > max) {
        bst = 0;
    } else {
        isBSTRecur(node->left, min, node->data);
        isBSTRecur(node->right, node->data, max);
    }
    return bst;
}
int isBST2(struct node* node) {
    return(isBSTRecur(node, INT32_MIN, INT32_MAX));
}

/* give an ordered binary tree (BST), convert it to doubly linked list */
struct node* minNode(struct node* node) {
    while(node) {
        if (node->left) {
            node = node->left;
        } else {
            break;
        }
    }
    return node;
}

struct node* maxNode(struct node* node) {
    while(node) {
        if (node->right) {
            node = node->right;
        } else {
            break;
        }
    }
    return node;
}

struct node* treeToList(struct node* node) {
    static int found = 0;
    static struct node* head = NULL;
    if(node == NULL) {
        return NULL;
    } else {
        treeToList(node->left);
        if (!found) {
            head = node;
            found = 1;
        }
        treeToList(node->right);
        /* get prev and next node to attact to current node */
        struct node* prev_node = maxNode(node->left);
        struct node* next_node = minNode(node->right);
        node->left = prev_node;
        node->right = next_node;
        if (prev_node) {
            prev_node->right = node;
        }
        if (next_node) {
            next_node->left = node;
        }
    return head;
    }
}

void printTreeToListBidirectional(struct node * node, int size) {
    struct node* new_root = treeToList(node);
    /* make it a circular doubly linked list, update last and first pointers */
    struct node* last_node = maxNode(new_root);
    new_root->left = last_node;
    last_node->right = new_root;

    for (int i = 0; i < size; i++) {
        printf("%d\t", new_root->data);
        new_root = new_root->right;
    }
    /* point to last node */
    new_root = new_root->left;
    printf("\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t", new_root->data);
        new_root = new_root->left;
    }
    printf("\n");
}

#ifdef TESTING
int main() {
    struct node *root = NULL;

/* binary tree creation */
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->left->right = newNode(7);

/* binary search tree creation */
/*
    root = NULL;
    root = newNode(4);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
*/
/*
    printf("Inorder traversal: "); inOrder(root); printf("\n");
    printf("Preorder traversal: "); preOrder(root); printf("\n");
    printf("Postorder traversal: "); postOrder(root); printf("\n");

    printf("size: %d\n", size(root));
    printf("maxDepth: %d\n", maxDept(root));
    printf("hasPathSum: %d\n", hasPathSum(root, 17));
    mirror(root);
    doubleTree(root);
    printf("sameTree: %d\n", sameTree(root, root1));
    printf("isBST: %d\n", isBST(root));
    printf("isBST2: %d\n", isBST2(root));
    printTreeToListBidirectional(root, 7);
*/

    return 0;
}
#endif /* TESTING */