#ifndef __STRUCT_CPP__
#define __STRUCT_CPP__

typedef struct BSTNode TreeNode;

struct BSTNode {
   int key;
   int duplicate;
   TreeNode *parent;
   TreeNode *left;
   TreeNode *right;
};

#endif
