#include "../includes/macro.hpp"
#include "../includes/rbtree.hpp"
#include "../includes/prototypes.hpp"


static void DeleteFixedUpRBT( TreeNode **root, TreeNode *current )
{

   while( current != *root && current->color == BLACK )
   {
      TreeNode *sibling = NULL;

      if ( isLeftChild( current ) )
      {
         sibling = current->parent->right;

         // Case 1: sibling is red
         if ( sibling->color == RED ){
            sibling->color = BLACK;
            sibling->parent->color = RED;
            leftRotate( sibling->parent, root );
            sibling = current->parent->right;
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 1\n");
#           endif
         }

         // Case 2: sibling is black, both children of sibling are black
         else if ( sibling->color == BLACK
           && sibling->left->color == BLACK
           && sibling->right->color == BLACK ){
            sibling->color = RED;
            current = current->parent;
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 2\n");
#           endif
         }


         // Case 3: sibling is black, right/left child of sibling is black/red
         else if ( sibling->color == BLACK
           && sibling->left->color == RED
           && sibling->right->color == BLACK ){
            sibling->color = RED;
            sibling->left->color = BLACK;
            rightRotate( sibling, root );
            sibling = current->parent->right;
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 3\n");
#           endif

         }

         // Case 4: sibling is black, right child of sibling is red
         else if ( sibling->color == BLACK
              && sibling->right->color == RED ){
            sibling->color = current->parent->color;
            current->parent->color = BLACK;
            sibling->right->color = BLACK;
            leftRotate( current->parent, root );
            current = *root;
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 4\n");
#           endif
         }
         else REPORT_ERROR;

      }else{

         sibling = current->parent->left;
         // Case 1: sibling is red
         if ( sibling->color == RED ){
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 1-2\n");
#           endif
            sibling->color = BLACK;
            sibling->parent->color = RED;
            rightRotate( sibling->parent, root );
            sibling = current->parent->left;
         }

         // Case 2: sibling is black, both children of sibling are black
         else if ( sibling->color == BLACK
           && sibling->right->color == BLACK
           && sibling->left->color == BLACK ){
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 2-2\n");
#           endif
            sibling->color = RED;
            current = current->parent;
         }


         // Case 3: sibling is black, right/left child of sibling is black/red
         else if ( sibling->color == BLACK
           && sibling->right->color == RED
           && sibling->left->color == BLACK ){
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 3-2\n");
#           endif
            sibling->color = RED;
            sibling->right->color = BLACK;
            leftRotate( sibling, root );
            sibling = current->parent->left;

         }

         // Case 4: sibling is black, left child of sibling is red
         else if ( sibling->color == BLACK
              && sibling->left->color == RED ){
#           ifdef DEBUG
            printf("DeleteFixedUpRBT: case 4-2");
#           endif
            sibling->color = current->parent->color;
            current->parent->color = BLACK;
            sibling->left->color = BLACK;
            rightRotate( current->parent, root );
            current = *root;
         }
         else REPORT_ERROR;
      }
   }

   current->color = BLACK;

}

void deleteNode( TreeNode **root, int key )
{

   TreeNode *node = searchNode(*root, key);

   bool deleteNodeColor;
   TreeNode *deleteNodeChild = NULL;

   if ( node == NULL ){
      printf("The key %d is not found.\n", key);
      return;
   }

   // Checking duplicate
   if ( node->duplicate < 1 )  REPORT_ERROR

   // Case 0: The node to be deleted is duplicate
   if ( node->duplicate > 1 ){
      (node->duplicate)--;
      return;
   }

   // Case 1: The node to be deleted has no child
   if ( node->left == neel && node->right == neel ){

      if ( node == *root ) { *root = neel; free(node); return;}

      if ( node->parent->left == node ){
         node->parent->left  = neel;
      }else if (node->parent->right == node){
         node->parent->right = neel;
      }else{
         REPORT_ERROR
      }

      deleteNodeColor = node->color;
      deleteNodeChild = neel;
      deleteNodeChild->parent = node->parent;

#     ifdef DEBUG
      printf("deleteNode: Case 1\n");
#     endif

      free(node);
   }

   // Case 2: The node to be deleted has left child
   else if ( node->right == neel && node->left != neel ){

      if ( node == *root ) { *root = node->left; free(node); return; }

      if ( node->parent->left == node ){
         node->parent->left  = node->left;
      }else if (node->parent->right == node){
         node->parent->right = node->left;
      }else{
         REPORT_ERROR
      }

      node->left->parent = node->parent;

      deleteNodeColor = node->color;
      deleteNodeChild = node->left;
      deleteNodeChild->parent = node->parent;

      free(node);
   }

   // Case 3: The node to be deleted has right child
   else if ( node->right != neel && node->left == neel ){

      if ( node == *root ) { *root = node->right; free(node); return; }

      if ( node->parent->left == node ){
         node->parent->left  = node->right;
      }else if (node->parent->right == node){
         node->parent->right = node->right;
      }else{
         REPORT_ERROR
      }

      node->right->parent = node->parent;

      deleteNodeColor = node->color;
      deleteNodeChild = node->right;
      deleteNodeChild->parent = node->parent;

      free(node);
   }

   // Case 4: The node to be deleted has both child
   //         --> Delete the inorder successor in right-subtree
   else if ( node->right != neel && node->left != neel ){

      TreeNode *successor = inorderSuccessor(node);

      if ( successor->parent->left == successor ){
         successor->parent->left = successor->right;
      }else if( successor->parent->right == successor ){
         successor->parent->right = successor->right;
      }else{
         REPORT_ERROR
      }

      if ( successor->right != neel )
         successor->right->parent = successor->parent;

      node->key = successor->key;

      deleteNodeColor = successor->color;
      deleteNodeChild = successor->right;
      deleteNodeChild->parent = successor->parent;

      free(successor);
   }
   else REPORT_ERROR;


   if ( deleteNodeColor == BLACK )  DeleteFixedUpRBT( root, deleteNodeChild );

}


void DeallocateTree ( TreeNode **node )
{
    //do nothing if passed a non-existent node
    if ( *node == neel )   return;

    DeallocateTree( &((*node)->left) );
    DeallocateTree( &((*node)->right) );

    free(*node);
}
