/************************************************************************/
/*                                                                      */
/* Interface file for a BINARY_TREE ADT                                 */
/*                                                                      */
/* Refer to lecture notes for details.                                  */
/*                                                                      */
/* David Vernon                                                         */
/* 5/3/2017 Added function to initialize the tree                       */
/*                                                                      */
/************************************************************************/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

typedef  struct {
            int number;
            char *string;
         } ELEMENT_TYPE;

typedef struct node *NODE_TYPE;

typedef struct node {
            ELEMENT_TYPE element;
            NODE_TYPE left, right;
         } NODE;

typedef NODE_TYPE BINARY_TREE_TYPE;

typedef BINARY_TREE_TYPE WINDOW_TYPE;

/*** function prototypes ***/

/*** initialize a tree ***/

void initialize(BINARY_TREE_TYPE *tree );
 
/*** insert an element in a tree ***/

BINARY_TREE_TYPE *insert(ELEMENT_TYPE e,  BINARY_TREE_TYPE *tree );
 
/*** returns & deletes the smallest node in a tree (i.e. the left-most node) */

ELEMENT_TYPE delete_min(BINARY_TREE_TYPE *tree);

/*** delete an element in a tree ***/

BINARY_TREE_TYPE *delete_element(ELEMENT_TYPE e, BINARY_TREE_TYPE *tree);

/*** inorder traversal of a tree, printing node elements **/

int inorder(BINARY_TREE_TYPE tree, int n);

/*** inorder traversal of a tree, printing node elements into a file pointer**/

int print_inorder(FILE *fp_out, BINARY_TREE_TYPE tree, int n);

/*** Returns the total number of probes using an inorder traversal of a tree**/

int get_total_probes(BINARY_TREE_TYPE tree, int n);

/*** print all elements in a tree by traversing inorder ***/

int print(BINARY_TREE_TYPE tree);

/*** error handler: print message passed as argument and take appropriate action ***/

int error(char *s);

/*** assign values to an element ***/

int assign_element_values(ELEMENT_TYPE *e, char s[]);

/*** delete all nodes ***/

int postorder_delete_nodes(BINARY_TREE_TYPE tree);

/*** checks if a binary tree contains element type e ***/

bool contains(ELEMENT_TYPE e, BINARY_TREE_TYPE tree);

/***computes the height of a binary search tree ***/

int height(BINARY_TREE_TYPE tree);

/*returns the maximum number between x and y*/
int max(int x, int y);

/*** computes the size of a tree ***/

int tree_size(BINARY_TREE_TYPE tree);

/*** computes the level of a tree ***/

int get_node_level(BINARY_TREE_TYPE tree, char s[], int level);