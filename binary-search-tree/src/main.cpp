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

   for (int i=0;i<numInsertion;i++){
      // Returns a pseudo-random integer between 0 and RAND_MAX.
      int r = rand();

      InsertNode( &root, r );

      if ( insert[r%ARRAY_LENGTH] == 0)
         insert[r%ARRAY_LENGTH] = r;
      else{
         DeleteNode(&root, insert[r%ARRAY_LENGTH] );
         insert[r%ARRAY_LENGTH] = 0;
      }

      if (!isValidBST(root)){
         printf("Invalid BST! at i=%d\n", i);
         exit(EXIT_FAILURE);
      }
   }


   return 0;
}

