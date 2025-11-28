#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int rCount = 3, cCount = 3;

   int **grid = (int **)calloc(rCount, sizeof(int*));
    if (grid == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int r = 0; r < rCount; r++) {
        grid[r] = (int *)calloc(cCount, sizeof(int));
        if (grid[r] == NULL) {
            printf("Memory allocation failed at row %d!\n", r);
            return 1;
        }
    }

    printf("Enter elements:\n");
    for (int r = 0; r < rCount; r++) {
        for (int c = 0; c < cCount; c++) {
            scanf("%d", &grid[r][c]);
        }
    }

    printf("Matrix output:\n");
    for (int r = 0; r < rCount; r++) {
        for (int c = 0; c < cCount; c++) {
            printf("%d ", grid[r][c]);
        }
        printf("\n");
    }

    // Free memory
    for (int r = 0; r < rCount; r++) {
        free(grid[r]);
    }
    free(grid);
    grid = NULL;

    return 0;
}

