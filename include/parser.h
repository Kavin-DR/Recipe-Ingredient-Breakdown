#ifndef PARSER_H
#define PARSER_H

#include "tree.h"

TreeNode* parseIngredientLine(char* line);

int isQuantity(char* token);
int isUnit(char* token);
int isPreparation(char* token);

#endif