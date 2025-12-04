#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "members.dat"

// structure defining a Student Record
// holds all the personal info for one person
typedef struct 
{
    int id;
    char fullName[100];
    char batch[20];        // e.g., "CS", "SE", "Cyber", "AI"
    char type[10];         // "IEEE" or "ACM"
    char regDate[15];      // YYYY-MM-DD
    char dob[15];          // YYYY-MM-DD
    char interest[20];     // "IEEE", "ACM", or "Both"
} Student;

// structure to manage the dynamic array in memory
// keeps track of the pointer and how many items we have
typedef struct 
{
    Student *students;
    int count;
    int capacity;
} Database;

// Function Prototypes
void setupDatabase(Database *db);
void loadDatabase(Database *db, const char *filename);
void saveDatabase(Database *db, const char *filename);
void addStudent(Database *db, const char *filename);
void updateStudent(Database *db, int id);
void deleteStudent(Database *db, int id);
void printStudent(Student s);
void viewAll(Database *db);
void batchReport(Database *db);
void freeDatabase(Database *db);
int findIndex(Database *db, int id);


int main() 
{
    Database db;
    int choice, id;

    // initializing the struct and memory
    setupDatabase(&db);

    // loading existing data immediately on startup, so we don't lose records from previous runs
    loadDatabase(&db, FILENAME);

    while (1) 
    {
        printf("\nMenu\n");
        printf("1. Register New Student\n");
        printf("2. Update Membership/Batch\n");
        printf("3. Delete Registration\n");
        printf("4. View All Registrations\n");
        printf("5. Generate Batch-wise Report\n");
        printf("6. Exit\n");
        printf("Select option: ");
        
        // validating integer input
        if (scanf("%d", &choice) != 1) 
        {
            while(getchar() != '\n'); // clear invalid input
            continue;
        }
        while(getchar() != '\n'); // clear newline buffer

        switch (choice) 
        {
            case 1:
            {
                addStudent(&db, FILENAME);
                break;
            }
            case 2:
            {
                printf("Enter Student ID to update: ");
                scanf("%d", &id);
                updateStudent(&db, id);
                break;
            }
            case 3:
            {
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(&db, id);
                break;
            }
            case 4:
            {
                viewAll(&db);
                break;
            }
            case 5:
            {
                batchReport(&db);
                break;
            }
            case 6:
            {
                // save one last time just in case, though we save on operations
                saveDatabase(&db, FILENAME);
                freeDatabase(&db);
                printf("Database saved. Exiting...\n");
                return 0;
            }
            default:
                printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}



// This function allocates initial memory for the array and sets up the database
// its called at the very beginning of the program.
void setupDatabase(Database *db) 
{
    db->capacity = 10; // Start small
    db->count = 0;
    // using malloc to get space on heap
    db->students = (Student *)malloc(db->capacity * sizeof(Student));
    
    if (db->students == NULL) 
    {
        printf("Error: Malloc failed\n");
        exit(1);
    }
}

// This function loads all records from the binary file into memory
// this allows us to access data fast without reading the file constantly
// It is also called at the very beginning of the program.
void loadDatabase(Database *db, const char *filename) 
{
    FILE *fp = fopen(filename, "rb");
    Student temp;

    if (fp == NULL) 
    {
        printf("No existing database found. Starting fresh.\n");
        return;
    }

    // reading one struct at a time loop
    while (fread(&temp, sizeof(Student), 1, fp)) 
    {
        // Resize if full
        if (db->count == db->capacity) 
        {
            db->capacity *= 2;
            // expanding memory using realloc
            db->students = (Student *)realloc(db->students, db->capacity * sizeof(Student));
            
            if (db->students == NULL) 
            {
                printf("Error: Realloc failed during loading\n");
                fclose(fp);
                exit(1);
            }
        }
        // adding record to our dynamic array
        db->students[db->count++] = temp;
    }

    fclose(fp);
    printf("Loaded %d records from %s.\n", db->count, filename);
}

// This function rewrites the entire memory array to the file, which are used in the update and delete functions, and before exiting the program.
// it ensures the file matches exactly what is in RAM.
void saveDatabase(Database *db, const char *filename) 
{
    FILE *fp = fopen(filename, "wb"); // "wb" overwrites the file
    
    if (fp == NULL) 
    {
        printf("Error: Could not open file for saving\n");
        return;
    }

    // Write the whole array in one go
    if (db->count > 0) 
    {
        fwrite(db->students, sizeof(Student), db->count, fp);
    }

    fclose(fp);
    printf("Database synchronized with file.\n");
}

// This function adds a student to memory and append to file, for Case 1.
void addStudent(Database *db, const char *filename) 
{
    Student s;
    FILE *fp;
    
    // getting user inputs
    printf("Enter ID: ");
    scanf("%d", &s.id);
    while(getchar() != '\n'); 

    // Check for duplicate ID
    if (findIndex(db, s.id) != -1) //helper function used to check for duplicates, its described later below.
    {
        printf("Error: Student ID %d already exists!\n", s.id);
        return;
    }

    printf("Full Name: ");
    fgets(s.fullName, 100, stdin);
    s.fullName[strcspn(s.fullName, "\n")] = 0; // Remove newline

    printf("Batch (CS/SE/Cyber/AI): ");
    scanf("%s", s.batch);

    printf("Membership Type (IEEE/ACM): ");
    scanf("%s", s.type);

    printf("Reg Date (YYYY-MM-DD): ");
    scanf("%s", s.regDate);

    printf("DOB (YYYY-MM-DD): ");
    scanf("%s", s.dob);

    printf("Interest (IEEE/ACM/Both): ");
    scanf("%s", s.interest);

    // 1. Add to Memory
    // check if we need to grow array
    if (db->count == db->capacity) 
    {
        db->capacity *= 2;
        Student *temp = (Student *)realloc(db->students, db->capacity * sizeof(Student));
        
        if (temp == NULL) 
        {
            printf("Error: Memory expansion failed\n");
            return;
        }
        db->students = temp;
    }
    db->students[db->count++] = s;

    // 2. Append to File
    // opening in append binary mode to add to end of file
    fp = fopen(filename, "ab"); 
    
    if (fp != NULL) 
    {
        fwrite(&s, sizeof(Student), 1, fp);
        fclose(fp);
        printf("Student added successfully.\n");
    } 
    else 
    {
        printf("Error: Could not write to file\n");
    }
}

// This function updates an existing record, for Case 2.
void updateStudent(Database *db, int id) 
{
    int index = findIndex(db, id); //helper function used to find the index of the desired student
    
    if (index == -1) 
    {
        printf("Student ID not found.\n");
        return;
    }

    // getting new values
    printf("Updating Record for %s...\n", db->students[index].fullName);
    printf("New Batch (current: %s): ", db->students[index].batch);
    scanf("%s", db->students[index].batch);

    printf("New Membership Type (current: %s): ", db->students[index].type);
    scanf("%s", db->students[index].type);

    // since we changed data in the middle, we must rewrite the file to keep consistency
    saveDatabase(db, FILENAME);
}

// This funciton deletes a student from memory and file, for Case 3.
void deleteStudent(Database *db, int id) 
{
    int index = findIndex(db, id); //helper function used to find the index of the desired student
    
    if (index == -1) 
    {
        printf("Student ID not found.\n");
        return;
    }

    // shift elements left to fill the gap
    // If index is 2 and count is 5, we move 3,4 to 2,3
    // this overwrites the deleted element
    for (int i = index; i < db->count - 1; i++) 
    {
        db->students[i] = db->students[i + 1];
    }
    db->count--;

    // saving the new file after deletion
    saveDatabase(db, FILENAME);
    printf("Student deleted successfully.\n");
}

// This function displays all students in the database, for Case 4.
void viewAll(Database *db) 
{
    if (db->count == 0) 
    {
        printf("No records found.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-10s %-12s\n", "ID", "Name", "Batch", "Type", "Interest");
    
    // looping through all students
    for (int i = 0; i < db->count; i++) 
    {
        printStudent(db->students[i]); //helper function to print student record
    }
}

// THis function filters and shows students from a specific batch, for Case 5.
void batchReport(Database *db) 
{
    char targetBatch[20];
    int found = 0;
    
    printf("Enter Batch to filter (CS/SE/Cyber/AI): ");
    scanf("%s", targetBatch);

    printf("\n Report for Batch: %s\n", targetBatch);
    
    // linear search for matching batch
    for (int i = 0; i < db->count; i++) 
    {
        // simple case-insensitive check could be added, but i am keeping it standard
        if (strcmp(db->students[i].batch, targetBatch) == 0) 
        {
            printStudent(db->students[i]); //helper function to print student record
            found++;
        }
    }
    if (found == 0) printf("No students found in this batch.\n");
}

// This is just a helper to print one row
// It is used in viewAll function inside the loop to print every single student record.
// It is also used inside the batchReport function. If the loop finds a student, that student is printed using this function.
void printStudent(Student s) 
{
    printf("%-5d %-20s %-10s %-10s %-12s\n", 
           s.id, s.fullName, s.batch, s.type, s.interest);
}

// This is also just a helper to find array index by inputing ID
// it is used in addStudent function to check for any duplicates before adding a new student.
// it is also used in updateStudent to find the index of the student to update
// and it is used in deleteStudent to find the index of the student to delete.
int findIndex(Database *db, int id) 
{
    // linear search
    for (int i = 0; i < db->count; i++) 
    {
        if (db->students[i].id == id) 
        {
            return i;
        }
    }
    return -1;
}

// This function frees allocated memory before closing the program.
void freeDatabase(Database *db) 
{
    free(db->students);
    db->students = NULL;
    db->count = 0;
    db->capacity = 0;
    
    // reseting to safe state
    printf("Memory freed\n");
}