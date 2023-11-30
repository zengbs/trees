#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "includes/typedef.hpp"
#include "includes/prototypes.hpp"
#include "includes/macro.hpp"



TreeNode* SearchNode( TreeNode *root, int key )
{
   TreeNode *current = root;

   while( current->key != key ){
      if      ( current->key > key )  current = current->left;
      else if ( current->key < key )  current = current->right;
      else { REPORT_ERROR }

      if ( current == NULL ) return NULL;
   }

   return current;

}

