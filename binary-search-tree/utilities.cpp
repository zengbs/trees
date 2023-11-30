#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "includes/typedef.hpp"
#include "includes/prototypes.hpp"
#include "includes/macro.hpp"



void PrintInorder( TreeNode *node )
{

   if ( node == NULL ) return;

   PrintInorder(node->left);

   printf("%d(%d)  ", node->key, node->duplicate);

   PrintInorder(node->right);

}


// Only works for the node having both child
TreeNode* InorderSuccessor( TreeNode *node )
{

   TreeNode *current = node->right;

   while( current->left != NULL ){
      current = current->left;
   }

   return current;
}

