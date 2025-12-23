#include <stdio.h>
#include "../include/tree.h"
#include "../include/parser.h"
void visualizeDependency(TreeNode* root);

int main() {
    printf("==================================================\n");
    printf("   Recipe Ingredient Breakdown (Tree Parsing)     \n");
    printf("==================================================\n\n");

    char* recipes[] = {
        "2 cups chopped tomatoes",
        "1/2 teaspoon ground salt",
        "3 cups sifted flour",
        "1 tablespoon melted butter",
        "5 large sliced apples"
    };
    int count = 5;

    for (int i = 0; i < count; i++) {
        printf("Raw Input: \"%s\"", recipes[i]);
        
        TreeNode* root = parseIngredientLine(recipes[i]);
        
        visualizeDependency(root);
        
        freeTree(root);
    }

    return 0;
}