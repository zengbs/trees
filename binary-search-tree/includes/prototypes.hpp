# ifndef __PROTOTYPES_HPP__
# define __PROTOTYPES_HPP__

#include "typedef.hpp"

bool validate(TreeNode* node, TreeNode* prev);
bool isValidBST(TreeNode* root);
void PrintInorder( TreeNode *node );
TreeNode* InorderSuccessor( TreeNode *node );
void DeleteNode( TreeNode **root, int key );
void AllocateNewNode( TreeNode **parent, int key, int left_root_right );
void InsertNode( TreeNode **root, int key );
TreeNode* SearchNode( TreeNode *root, int key );

# endif
