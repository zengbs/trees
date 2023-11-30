#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/typedef.hpp"
#include "../includes/prototypes.hpp"
#include "../includes/macro.hpp"




int main(){

   // Initialization, should only be called once.
   srand((unsigned int)time(NULL));


   TreeNode *root = NULL;

   int numInsertion = 10000;


   int insert[ARRAY_LENGTH] = {0};

   for (int i=0;i<numInsertion;i++)
   {
      // Returns a pseudo-random integer between 0 and RAND_MAX.
      int r = rand();

      InsertNode( &root, r );

      // Insertion
      if ( insert[r%ARRAY_LENGTH] == 0)
      {
         insert[r%ARRAY_LENGTH] = r;
      }

      // Deletion
      else
      {
         DeleteNode(&root, insert[r%ARRAY_LENGTH] );
         insert[r%ARRAY_LENGTH] = 0;
      }

      if (!isValidBST(root))
      {
         printf("Invalid BST! at i=%d\n", i);
         exit(EXIT_FAILURE);
      }

   }

   DeallocateTree(&root);

   printf("Valid BST with %d nodes!\n", numInsertion);

   return 0;
}

