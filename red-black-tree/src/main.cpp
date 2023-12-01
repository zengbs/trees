#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/macro.hpp"
#include "../includes/rbtree.hpp"
#include "../includes/prototypes.hpp"


TreeNode *neel = NULL;




//#define MANUAL_TEST
#define RANDOM_TEST

int main(){

neel = (TreeNode*)malloc(sizeof(TreeNode));
neel->color = BLACK;
neel->left = NULL;
neel->right = NULL;


TreeNode *root = neel;
root->parent = neel;


#  ifdef MANUAL_TEST

   // Allocate null node
   InsertNode(&root, 2);

   print2D(root);

   if (!isValidBST(root)){
      printf("Invalid BST!\n");
      exit(EXIT_FAILURE);
   }

   if (!isBalanced(root)){
      printf("RBT is unbalanced!\n");
      exit(EXIT_FAILURE);
   }

#  endif


#  ifdef RANDOM_TEST

   // Initialization, should only be called once.
   srand((unsigned int)time(NULL));


   int numInsertion = 10000;
   int insert[ARRAY_LENGTH] = {0};

   for (int i=0;i<numInsertion;i++){
      // Returns a pseudo-random integer between 0 and RAND_MAX.
      int r = rand();

      InsertNode( &root, r );

      if ( insert[r%ARRAY_LENGTH] == 0)
         insert[r%ARRAY_LENGTH] = r;
      else{
         deleteNode(&root, insert[r%ARRAY_LENGTH] );
         insert[r%ARRAY_LENGTH] = 0;
      }

      if (!isValidBST(root)){
         printf("Invalid BST! at i=%d\n", i);
         exit(EXIT_FAILURE);
      }

      if (!isBalanced(root)){
         printf("RBT is unbalanced! at i=%d\n", i);
         exit(EXIT_FAILURE);
      }
   }

   DeallocateTree(&root);
   free(neel);

   printf("Valid Red-black tree with %d nodes!\n", numInsertion);

#  endif

   return 0;
}
