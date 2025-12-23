#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    ROOT_INGREDIENT, 
    QUANTITY,       
    UNIT,           
    PREPARATION,    
    UNKNOWN
} NodeType;

typedef struct TreeNode {
    char* word;
    NodeType type;
    struct TreeNode* firstChild;  
    struct TreeNode* nextSibling; 
} TreeNode;

TreeNode* createNode(char* word, NodeType type);
void addChild(TreeNode* parent, TreeNode* child);
void printTree(TreeNode* root, int level);
void freeTree(TreeNode* root);
const char* getTypeString(NodeType type);

#endif