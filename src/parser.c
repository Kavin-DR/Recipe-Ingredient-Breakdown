#include "../include/parser.h"
#include <ctype.h>
#include <string.h>

const char* UNITS[] = {"cup", "cups", "tsp", "teaspoon", "tbsp", "tablespoon", "gram", "g", "kg", "oz", "slice", "slices", NULL};
const char* PREPS[] = {"chopped", "minced", "diced", "ground", "sifted", "melted", "sliced", "freshly", NULL};

int isQuantity(char* token) {
    if (isdigit(token[0])) return 1;
    return 0;
}

int isUnit(char* token) {
    for (int i = 0; UNITS[i] != NULL; i++) {
        if (strcasecmp(token, UNITS[i]) == 0) return 1;
    }
    return 0;
}

int isPreparation(char* token) {
    for (int i = 0; PREPS[i] != NULL; i++) {
        if (strcasecmp(token, PREPS[i]) == 0) return 1;
    }
    return 0;
}

TreeNode* parseIngredientLine(char* line) {
    char buffer[256];
    strcpy(buffer, line);

    TreeNode* modifiers[10];
    int modCount = 0;
    TreeNode* rootIngredient = NULL;

    char* token = strtok(buffer, " \n\r");
    while (token != NULL) {
        if (isQuantity(token)) {
            modifiers[modCount++] = createNode(token, QUANTITY);
        }
        else if (isUnit(token)) {
            modifiers[modCount++] = createNode(token, UNIT);
        }
        else if (isPreparation(token)) {
            modifiers[modCount++] = createNode(token, PREPARATION);
        }
        else {
            if(rootIngredient == NULL) {
                rootIngredient = createNode(token, ROOT_INGREDIENT);
            } else {
                char newName[100];
                sprintf(newName, "%s %s", rootIngredient->word, token);
                free(rootIngredient->word);
                rootIngredient->word = strdup(newName);
            }
        }
        token = strtok(NULL, " \n\r");
    }
    if (rootIngredient == NULL) {
        rootIngredient = createNode("Unknown", ROOT_INGREDIENT);
    }
    for(int i=0; i<modCount; i++) {
        addChild(rootIngredient, modifiers[i]);
    }

    return rootIngredient;
}