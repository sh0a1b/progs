/*
 * linked list implementation, problems taken from http://cslibrary.stanford.edu/105/
 * please refer the link.
 */

#include<stdio.h>
#include<stdlib.h>
#include <cstddef>

struct node {
    int data;
    struct node* next;
};

void printList(struct node* head) {
    struct node* current = head;

    while (current != NULL) {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

/* Reference pointer usage, modifies the head, pushes a new node at the head. */
void Push(struct node** headRef, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}

int Pop(struct node*& headRef) {
    struct node* current = NULL;
    int data;
    
    current = headRef;
    headRef = headRef->next;
    data = current->data;
    free(current);
    
    return data;
}
int Count(struct node* head, int searchFor) {
    int count = 0;
    struct node* current = head;

    while(current != NULL) {
        if (current->data == searchFor) {
            count++;
        }
        current = current->next;
    }
    return(count);
}

void DeleteList(struct node** headRef) {
    struct node* current = *headRef;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *headRef = NULL;
}

void InsertNth(struct node** headRef, int index, int data) {
    struct node *current = NULL, *prev = NULL, *newNode = NULL;

    if (*headRef == NULL) {
        /* list is empty, push it at first */
        Push(headRef, data);
    } else {
        current = *headRef;
        newNode = (struct node*) malloc(sizeof(struct node));
        newNode->data = data;
        for (int i = 0; i != index; i++) {
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        if (prev) {
            prev->next = newNode;
        } else {
            *headRef = newNode;
        }
    }
}

void SortedInsert(struct node** headRef, struct node* newNode) {
    struct node *current = NULL, *prev = NULL;

    if (*headRef == NULL) {
        /* list is empty */
        *headRef = newNode;
    } else {
        current = *headRef;
        while(current && current->data < newNode->data) {
            prev = current;
            current = current->next;
        }
        newNode->next = current;
        if (prev) {
            prev->next = newNode;
        } else {
            *headRef = newNode;
        }
    }
}

void InsertSort(struct node** headRef) {
    struct node* current = NULL, *next = NULL;

    if (*headRef == NULL) {
        /* list is empty */
        return;
    } else {
        current = (*headRef)->next;
        (*headRef)->next = NULL;
        while (current != NULL) {
            next = current->next;            
            SortedInsert(headRef, current);
            //current->next = NULL;
            current = next;
        }
    }
}

void Append(struct node** aRef, struct node** bRef) {
    struct node* current = (*aRef);

    if ((*aRef) == NULL) {
        /* list 'a' is empty */
        (*aRef) = (*bRef);
        return;
    }
    while (current->next) {
        current = current->next;
    }
    current->next = (*bRef);
    (*bRef) = NULL;
}

int Length(struct node* node) {
    int len = 0;
    struct node* current = node;
    while(current) {
        len++;
        current = current->next;
    }
    return(len);
}
void FrontBackSplit (struct node* source, struct node** frontRef, struct node** backRef) {
    int half;
    int len = Length(source);
    struct node *cur = source, *prev = NULL;
    if (len == 1) {
        (*frontRef) = source;
        (*backRef) = NULL;
    } else {
        if (len % 2 == 0) { /* even */
            half = len/2;
        } else { /* odd */
            half = (len/2) + 1;
        }
        /* split at prev, back will start at cur */
        for (int i = 0; i < half; i++) {
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
            (*frontRef) = source;
            (*backRef) = cur;
    }
 }

/* remove dups from a sorted linked list (increasing order) */
void RemoveDuplicates (struct node* head) {
    struct node *cur = nullptr, *next_node = nullptr;

    cur = head;
    next_node = cur->next;
    while(cur && next_node) {
        if (cur->data == next_node->data) {
            cur->next = next_node->next;
            free(next_node);
            next_node = cur->next;
        } else {
            cur = cur->next;
            next_node = next_node->next;
        }
    }
}

/* move head-node from srcRef to head of destRef */
void MoveNode(struct node** destRef, struct node** srcRef) {
    struct node* cur = (*srcRef);
    /* change the srcRef head-node */
    if (cur) {
    (*srcRef) = (*srcRef)->next;
    cur->next = (*destRef);
    (*destRef) = cur;
    }

}

void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef) {
    struct node *split_node = NULL;
    split_node = source;
    while (split_node) {
        MoveNode(aRef, &split_node);
        /* split_node now points to next element, which should go in bRef */
        if (split_node) {
            MoveNode(bRef, &split_node);
        }
    }
}

struct node* ShuffleMerge(struct node* a, struct node* b) {
    struct node *a_next = NULL, *b_next = NULL, *head = a;
    /* check if a or b is empty */
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    while (a && b) {
       a_next = a->next;
       b_next = b->next;
       if (b) {
           a->next = b;
       }
       if (a_next) {
           b->next = a_next;
       }
       a = a_next;
       b = b_next;
   }
   return head;
}
int main() {
    struct node* head = NULL, *head1 = NULL;
    struct node *front = NULL, *back = NULL;

    Push(&head, 5);
    Push(&head, 4);
    Push(&head, 3);
    Push(&head, 2);
    Push(&head, 1);

    // Push(&head1, 8);
    // Push(&head1, 6);
    // Push(&head1, 4);
    // Push(&head1, 2);

/*
    printf("count: %d\n", Count(head, 2));
    printList(head);
    DeleteList(&head);
    if (head == NULL) {
        printf("List Freed\n");
    }
    int i = Pop(head); //using c++ reference
    InsertNth(&head, 1, 4);
    SortedInsert(&head, newNode);
    InsertSort(&head);
    Append(&head, &head1);
    FrontBackSplit(head, &front, &back);
    RemoveDuplicates(head);
    MoveNode(&head, &head1);
    AlternatingSplit(head, &front, &back);
    front = ShuffleMerge(head, head1);
*/
    printList(head);
    printList(head1);
    printList(front);
    // printList(back);


}
