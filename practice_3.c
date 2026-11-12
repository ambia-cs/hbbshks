#include <stdio.h>

#define MAX 100

// Function declarations
void addBooks(int bookID[], int shelf[], int *count);
void displayBooks(int bookID[], int shelf[], int count);
void searchBook(int bookID[], int shelf[], int count);
void updateBookID(int bookID[], int count);

int main()
{
int bookID[MAX];
int shelf[MAX];
int count = 0;
int choice;

do
{
printf("\n========== Book Inventory Manager ==========\n");
printf("1. Add Books\n");
printf("2. Display All Books\n");
printf("3. Search Book ID\n");
printf("4. Update Book ID\n");
printf("5. Exit\n");

printf("\nEnter your choice: ");
scanf("%d", &choice);

if (choice == 1)
{
addBooks(bookID, shelf, &count);
}
else if (choice == 2)
{
displayBooks(bookID, shelf, count);
}
else if (choice == 3)
{
searchBook(bookID, shelf, count);
}
else if (choice == 4)
{
updateBookID(bookID, count);
}
else if (choice == 5)
{
printf("\nThank you for using Book Inventory Manager!\n");
}
else
{
printf("\nInvalid choice! Please try again.\n");
}

}
while (choice != 5);

return 0;
}

// Function to add books
void addBooks(int bookID[], int shelf[], int *count)
{
int n;

printf("\nHow many books do you want to add? ");
scanf("%d", &n);

if (n <= 0 || n > MAX - *count)
{
printf("Invalid number! You can store up to 100 books.\n");
return;
}

for (int i = 0; i < n; i++)
{
printf("\nEnter Book ID: ");
scanf("%d", &bookID[*count]);

printf("Enter Shelf Number: ");
scanf("%d", &shelf[*count]);

(*count)++;
}

printf("\nBooks added successfully!\n");
}

// Function to display all books
void displayBooks(int bookID[], int shelf[], int count)
{
if (count == 0)
{
printf("\nNo books have been added yet.\n");
return;
}

printf("\n========== Book Records ==========\n");
printf("Book ID\t\tShelf Number\n");

for (int i = 0; i < count; i++)
{
printf("%d\t\t%d\n", bookID[i], shelf[i]);
}
}

// Function to search for a book
void searchBook(int bookID[], int shelf[], int count)
{
int id;
int found = 0;

printf("\nEnter Book ID to search: ");
scanf("%d", &id);

for (int i = 0; i < count; i++)
{
if (bookID[i] == id)
{
printf("\nBook Found!\n");
printf("Book ID: %d\n", bookID[i]);
printf("Shelf Number: %d\n", shelf[i]);

found = 1;
break;
}
}

if (found == 0)
{
printf("\nBook not found!\n");
}
}

// Function to update a book ID using a pointer
void updateBookID(int bookID[], int count)
{
int oldID, newID;

printf("\nEnter the Book ID you want to update: ");
scanf("%d", &oldID);

for (int i = 0; i < count; i++)
{
if (bookID[i] == oldID)
{
printf("Enter the new Book ID: ");
scanf("%d", &newID);

int *ptr = &bookID[i];
*ptr = newID;

printf("\nBook ID updated successfully!\n");
return;
}
}

printf("\nBook ID not found!\n");
}
