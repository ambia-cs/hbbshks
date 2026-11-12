#include <stdio.h>
#include <cs50.h>

// Function declarations
void AddBooks(int BookIDs[], int ShelfNumbers[], int *count);
void DisplayBooks(int BookIDs[], int ShelfNumbers[], int count);
void SearchBook(int BookIDs[], int ShelfNumbers[], int count);
void UpdateBookID(int BookIDs[], int count);

int main()
{
// Arrays to store book IDs and shelf numbers
int BookIDs[100];
int ShelfNumbers[100];

int count = 0;
int choice;

// Repeat menu until user chooses Exit
do
{
printf("\n____________ Book Inventory Manager ____________\n");
printf("1. Add Books\n");
printf("2. Display All Books\n");
printf("3. Search Book ID\n");
printf("4. Update Book ID\n");
printf("5. Exit\n");

choice = get_int("\nEnter your choice: ");

if (choice == 1)
{
AddBooks(BookIDs, ShelfNumbers, &count);
}
else if (choice == 2)
{
DisplayBooks(BookIDs, ShelfNumbers, count);
}
else if (choice == 3)
{
SearchBook(BookIDs, ShelfNumbers, count);
}
else if (choice == 4)
{
UpdateBookID(BookIDs, count);
}
else if (choice == 5)
{
printf("Thank you! Goodbye.\n");
}
else
{
printf("Invalid choice! Please try again.\n");
}

}
while (choice != 5);

return 0;
}

// Function 1: Add Books
void AddBooks(int BookIDs[], int ShelfNumbers[], int *count)
{
int i;

// Check inventory capacity
if (*count == 100)
{
printf("Book inventory is full!\n");
return;
}

int n = get_int("How many books do you want to add? ");

// Validate number of books
if (n <= 0 || n > 100 - *count)
{
printf("Invalid number of books! Available space: %d\n",
100 - *count);
return;
}

// Add books
for (i = 0; i < n; i++)
{
BookIDs[*count] = get_int("\nEnter Book ID: ");

ShelfNumbers[*count] = get_int("Enter Shelf Number: ");

(*count)++;
}

printf("\nBooks added successfully!\n");
}

// Function 2: Display All Books
void DisplayBooks(int BookIDs[], int ShelfNumbers[], int count)
{
int i;

if (count == 0)
{
printf("No books have been added yet.\n");
}
else
{
printf("\nBook ID\t\tShelf Number\n");
printf("--------------------------------\n");

for (i = 0; i < count; i++)
{
printf("%d\t\t%d\n", BookIDs[i], ShelfNumbers[i]);
}
}
}

// Function 3: Search Book using Linear Search
void SearchBook(int BookIDs[], int ShelfNumbers[], int count)
{
int i;
int found = 0;

if (count == 0)
{
printf("No books available to search.\n");
return;
}

int SearchID = get_int("Enter Book ID to search: ");

for (i = 0; i < count; i++)
{
if (BookIDs[i] == SearchID)
{
printf("\nBook found!\n");
printf("Book ID: %d\n", BookIDs[i]);
printf("Shelf Number: %d\n", ShelfNumbers[i]);

found = 1;
break;
}
}

if (found == 0)
{
printf("Book ID not found.\n");
}
}

// Function 4: Update Book ID using Pointer
void UpdateBookID(int BookIDs[], int count)
{
int i;
int found = 0;
int *ptr;

if (count == 0)
{
printf("No books available to update.\n");
return;
}

int SearchID = get_int("Enter Book ID to update: ");

for (i = 0; i < count; i++)
{
if (BookIDs[i] == SearchID)
{
int NewID = get_int("Enter new Book ID: ");

ptr = &BookIDs[i];
*ptr = NewID;

printf("Book ID updated successfully!\n");

found = 1;
break;
}
}

if (found == 0)
{
printf("Book ID not found.\n");
}
}


