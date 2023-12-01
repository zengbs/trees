#include "../includes/macro.hpp"
#include "../includes/rbtree.hpp"
#include "../includes/prototypes.hpp"


bool isLeftChild( TreeNode * node )
{
   if      ( node->parent->left == node ) return true;
   else if ( node->parent->right == node ) return false;
   else REPORT_ERROR;
}


void printInorder( TreeNode *node )
{

   if ( node == neel ) return;

   printInorder(node->left);

   printf("%d(%d)  ", node->key, node->duplicate);

   printInorder(node->right);

}


// Only works for the node having both child
TreeNode* inorderSuccessor( TreeNode *node )
{

   TreeNode *current = node->right;

   while( current->left != neel ){
      current = current->left;
   }

   return current;
}
