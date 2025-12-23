#include "../include/tree.h"

TreeNode* createNode(char* word, NodeType type) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->word = strdup(word); 
    newNode->type = type;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(TreeNode* parent, TreeNode* child) {
    if (parent == NULL || child == NULL) return;

    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void printTree(TreeNode* root, int level) {
    if (root == NULL) return;

    for (int i = 0; i < level; i++) printf("    | ");
    
    printf("-> [%s]: %s\n", getTypeString(root->type), root->word);

    printTree(root->firstChild, level + 1);

    printTree(root->nextSibling, level);
}

void visualizeDependency(TreeNode* root) {
    if(root == NULL) return;
    
    printf("\n[Dependency Tree]\n");
    printf("   ROOT (Ingredient): %s\n", root->word);
    
    TreeNode* child = root->firstChild;
    while(child != NULL) {
        printf("    +-- %s: %s\n", getTypeString(child->type), child->word);
        child = child->nextSibling;
    }
    printf("-------------------------------------------------\n");
}

void freeTree(TreeNode* root) {
    if (root == NULL) return;
    freeTree(root->firstChild);
    freeTree(root->nextSibling);
    free(root->word);
    free(root);
}

const char* getTypeString(NodeType type) {
    switch (type) {
        case ROOT_INGREDIENT: return "INGREDIENT";
        case QUANTITY: return "QTY";
        case UNIT: return "UNIT";
        case PREPARATION: return "PREP";
        default: return "OTHER";
    }
}