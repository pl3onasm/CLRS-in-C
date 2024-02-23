/* 
  Generic binary search tree implementation 
  Author: David De Potter
  LICENSE: MIT, see LICENSE file in repository root folder
*/

#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// constants and macros
#define NIL   T->nil
#define ROOT  T->root

// data structures and types
typedef struct node {
  void *data;
  struct node *parent;
  struct node *left;
  struct node *right;
} node;

typedef struct {
  node *root, *nil;
} tree;

// function prototypes
tree *newTree (void);
node *newNode (tree *T, void *data);
void insertNode (tree *tree, node *n, int (*cmp)(void *, void *));
void freeTree (tree *tree);
node *searchKey (tree *T, void *key, int (*cmp)(void *, void *));
void deleteNode (tree *tree, node *z);
node *treeMinimum (tree *T, node *x);
void printTree (tree *T, node *x, short *count, void (*printData)(void *));
void printNode(node *x, void (*printData)(void *));
void writeTreeToFile (tree *T, node *x, FILE *fp, 
  void (*printData)(void *, FILE *));
void buildTreeFromFile (tree *tree, char *filename, size_t dataSize,
  int (*cmp)(void *, void *), bool (*dataFromStr)(void *, char *));

#endif  // BST_H_INCLUDED