#include <stdlib.h>
#include <stdio.h>

#include "btree.h"

struct bnode *newNode(int val);
struct bnode *insertNode(struct bnode *cur, int val);
void print(struct bnode *cur);

int main() {
    struct bnode *bt = newNode(5);
    print(bt);

    insertNode(bt, 6);
    print(bt);
    insertNode(bt, 7);
    print(bt);
    insertNode(bt, 2);
    print(bt);
    insertNode(bt, 1);
    print(bt);
}

struct bnode *newNode(int val) {
    struct bnode *i = malloc(sizeof(struct bnode));
    i->val = val;
    i->left = NULL;
    i->right = NULL;

    return i;
}

void print(struct bnode *cur) {
    if (cur != NULL) {
        printf("%d", cur->val);

        if (cur->left != NULL) {
            printf("/");
        }
        if (cur->right != NULL) {
            printf(" \\");
        }
        printf("\n");
        print(cur->left);
        print(cur->right);
    } else {
        printf("N");
    }
}

struct bnode *insertNode(struct bnode *cur, int val) {
    if (cur == NULL) {
        return newNode(val);
    } else if (cur->val < val) {
        cur->right = insertNode(cur->right, val);
    } else if (cur->val > val) {
        cur->left = insertNode(cur->left, val);
    }

    return cur;
}
