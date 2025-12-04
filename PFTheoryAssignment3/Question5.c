#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STARTSIZE 2
#define LINEMAX 1024

// Structure to hold our text editor buffer
// Using dynamic array of char* pointers instead of fixed 2D array
// this is more memory efficient because:
//  we are only allocating memory for lines that exist
//  each line uses exactly the memory it needs.
//  can grow/shrink at runtime based on actual usage
typedef struct 
{
    char **lines;        // pointer to array of string pointers
    int rowCount;        // current number of lines
    int capacity;        // maximum lines before reallocation needed
} SheetData;

// Function prototypes
void setupSheet(SheetData *sheet);
void insertLine(SheetData *sheet, int index, char *text);
void deleteLine(SheetData *sheet, int index);
void showContent(SheetData *sheet);
void shrinkToFit(SheetData *sheet);
void saveFile(SheetData *sheet, char *filename);
void loadFile(SheetData *sheet, char *filename);
void freeSheet(SheetData *sheet);

int main() 
{
    SheetData editor;
    char buffer[LINEMAX];
    char path[100];
    int choice, pos;

    setupSheet(&editor);

    printf("FAST University Text Editor\n");
    
    //This is our menu.
    while(1) 
    {
        printf("\nMenu\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Print All Lines\n");
        printf("4. Shrink Memory\n");
        printf("5. Save to File\n");
        printf("6. Load from File\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        if(scanf("%d", &choice) != 1) 
        {
            // clearing invalid input
            while(getchar() != '\n'); 
            printf("Invalid input.\n");
            continue;
        }
        while(getchar() != '\n'); // consume newline

        switch(choice) 
        {
            case 1:
            {
                printf("Enter index (0 to %d): ", editor.rowCount);
                scanf("%d", &pos);
                while(getchar() != '\n');
                
                printf("Enter text: ");
                if(fgets(buffer, LINEMAX, stdin)) 
                {
                    // remove trailing newline from fgets
                    buffer[strcspn(buffer, "\n")] = 0;
                    insertLine(&editor, pos, buffer);
                }
                break;
            }

            case 2:
            {
                printf("Enter index to delete (0 to %d): ", editor.rowCount - 1);
                scanf("%d", &pos);
                deleteLine(&editor, pos);
                break;
            }

            case 3:
                showContent(&editor);
                break;

            case 4:
                shrinkToFit(&editor);
                break;

            case 5:
                printf("Enter filename: ");
                scanf("%s", path);
                saveFile(&editor, path);
                break;

            case 6:
                printf("Enter filename: ");
                scanf("%s", path);
                loadFile(&editor, path);
                break;

            case 7:
                freeSheet(&editor);
                printf("Goodbye.\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// initialize buffer with small default capacity
// ising malloc to allocate initial array of pointers
void setupSheet(SheetData *sheet) 
{
    sheet->capacity = STARTSIZE;
    sheet->rowCount = 0;
    
    // Allocate space for pointer array (not the actual strings yet)
    sheet->lines = (char**)malloc(sheet->capacity * sizeof(char*));
    
    if(sheet->lines == NULL) 
    {
        printf("ERROR: Setup Sheet failed\n");
        exit(1);
    }
    
    printf("Sheet initialized: %d\n", sheet->capacity);
}

// This function is used for adding new lines, for Case 1.
// this function demonstrates:
//  Dynamic growth using realloc
//  exact memory allocation (strlen+1) for each line
//  shifting pointers (not strings) to make room
void insertLine(SheetData *sheet, int index, char *text) 
{
    // validate index
    if(index < 0 || index > sheet->rowCount) 
    {
        printf("Index out of bounds\n");
        return;
    }

    // Check if we need to grow the array
    if(sheet->rowCount == sheet->capacity) 
    {
        int newLimit = sheet->capacity * 2;
        
        // Use realloc to expand the pointer array
        char **temp = (char**)realloc(sheet->lines, newLimit * sizeof(char*));
        
        if(temp == NULL) 
        {
            printf("ERROR: Expansion failed\n");
            return;
        }
        
        sheet->lines = temp;
        sheet->capacity = newLimit;
        printf("Memory expanded: %d\n", newLimit);
    }

    // shift pointers to make room for new line
    // using memmove because it handles overlapping memory correctly
    // we are only moving pointers (8 bytes each), not entire strings
    if(index < sheet->rowCount) 
    {
        memmove(&sheet->lines[index + 1], &sheet->lines[index], 
                (sheet->rowCount - index) * sizeof(char*));
    }

    // allocate exact memory needed for this specific line
    // strlen(text) + 1 for null terminator
    sheet->lines[index] = (char*)malloc(strlen(text) + 1);
    
    if(sheet->lines[index] == NULL) 
    {
        printf("ERROR: Line alloc failed\n");
        return;
    }

    // copy the text into newly allocated memory
    strcpy(sheet->lines[index], text);
    sheet->rowCount++;
    
    printf("Line inserted at %d\n", index);
}

//  This function is used for deleting lines, for Case 2.
// demonstrates proper memory cleanup and pointer compaction.
void deleteLine(SheetData *sheet, int index) 
{
    // validate index
    if(index < 0 || index >= sheet->rowCount) 
    {
        printf("Index out of bounds\n");
        return;
    }

    // free the actual string memory first
    free(sheet->lines[index]);

    // compact the pointer array using memmove
    // this shifts all pointers after deleted index down by one position
    if(index < sheet->rowCount - 1) 
    {
        memmove(&sheet->lines[index], &sheet->lines[index + 1], 
                (sheet->rowCount - index - 1) * sizeof(char*));
    }

    sheet->rowCount--;
    printf("Line deleted at %d\n", index);
}


//  This function is used for showing all the lines/content inside our file, for Case 3.
void showContent(SheetData *sheet) 
{
    printf("\nContent:\n");
    printf("Lines: %d, Capacity: %d\n", sheet->rowCount, sheet->capacity);
    
    if(sheet->rowCount == 0) 
    {
        printf("Sheet is empty\n");
    } 
    else 
    {
        for(int i = 0; i < sheet->rowCount; i++) 
        {
            printf("%d: %s\n", i, sheet->lines[i]);
        }
    }
}

//  This function is used fit exact number of lines with no extra space, for Case 4.
void shrinkToFit(SheetData *sheet) 
{
    if(sheet->rowCount == 0) 
    {
        printf("Cannot shrink empty buffer\n");
        return;
    }
    
    if(sheet->rowCount < sheet->capacity) 
    {
        // Use realloc to shrink pointer array to exact size needed
        char **temp = (char**)realloc(sheet->lines, sheet->rowCount * sizeof(char*));
        
        if(temp != NULL) 
        {
            sheet->lines = temp;
            sheet->capacity = sheet->rowCount;
            printf("Memory optimized: %d\n", sheet->capacity);
        } 
        else 
        {
            printf("Shrink failed\n");
        }
    } 
    else 
    {
        printf("Buffer already optimized\n");
    }
}

// This function saves all lines to a file, for Case 5.
void saveFile(SheetData *sheet, char *filename) 
{
    FILE *fp = fopen(filename, "w");
    
    if(fp == NULL) 
    {
        printf("ERROR: Cannot write file\n");
        return;
    }

    // Writing each line to file
    for(int i = 0; i < sheet->rowCount; i++) 
    {
        fprintf(fp, "%s\n", sheet->lines[i]);
    }

    fclose(fp);
    printf("Saved %d lines to %s\n", sheet->rowCount, filename);
}

// This function loads lines from file and rebuild dynamic structure, for Case 6.
void loadFile(SheetData *sheet, char *filename) 
{
    FILE *fp = fopen(filename, "r");
    
    if(fp == NULL) 
    {
        printf("ERROR: Cannot read file\n");
        return;
    }

    // clear existing sheet before loading
    freeSheet(sheet);
    setupSheet(sheet);

    char buffer[LINEMAX];
    int count = 0;

    // reading file line by line and rebuilding dynamic structure
    while(fgets(buffer, LINEMAX, fp)) 
    {
        // remove newline character
        buffer[strcspn(buffer, "\n")] = 0;
        
        // insert at end of buffer
        insertLine(sheet, count, buffer);
        count++;
    }

    fclose(fp);
    printf("Loaded %d lines from %s\n", count, filename);
}

// This function frees all dynamically allocated memory, for Case 7 when exiting program.
// it free both string memory and pointer array
void freeSheet(SheetData *sheet) 
{
    // first free each individual string
    for(int i = 0; i < sheet->rowCount; i++) 
    {
        free(sheet->lines[i]);
    }
    
    // then free the pointer array itself
    free(sheet->lines);
    
    // reseting to safe state
    sheet->lines = NULL;
    sheet->rowCount = 0;
    sheet->capacity = 0;
    
    printf("Memory freed\n");
}