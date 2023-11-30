#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/typedef.hpp"
#include "../includes/prototypes.hpp"
#include "../includes/macro.hpp"



void AllocateNewNode( TreeNode **parent, int key, int left_root_right )
{
   TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

   if ( newNode == NULL ) REPORT_ERROR

   newNode->key    = key;
   newNode->left   = NULL;
   newNode->right  = NULL;
   newNode->duplicate = 1;

   if ( left_root_right == ROOT ){
      newNode->parent = NULL;
      *parent = newNode;
   }
   else if ( left_root_right == LEFT_CHILD ){
      newNode->parent = *parent;
      (*parent)->left  = newNode;
   }else{
      newNode->parent = *parent;
      (*parent)->right = newNode;
   }
}


void InsertNode( TreeNode **root, int key )
{

   TreeNode *current = *root;
   TreeNode *previous = NULL;

   while( current != NULL ){

      previous = current;

      if ( current->key > key ){
         current = current->left;
      }else if ( current->key < key ){
         current = current->right;
      }else{
         (current->duplicate)++;
         return;
      }

   }

   if ( previous == NULL )           AllocateNewNode( root, key, ROOT );
   else if ( previous->key > key )   AllocateNewNode( &previous, key, LEFT_CHILD );
   else                              AllocateNewNode( &previous, key, RIGHT_CHILD );
}

