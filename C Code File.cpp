#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store book details
struct library {
    char book_name[100];
    char author[100];
    int pages;
    float price;
};

int main() {
    struct library lib[100]; // Array to store books
    char ar_nm[100]; // For searching author
    int input, count = 0;

    while (1) {
        printf("\n\n********###### WELCOME TO E-LIBRARY #####********\n");
        printf("1. Add book information\n2. Display book information\n");
        printf("3. List all books of a given author\n");
        printf("4. List the count of books in the library\n");
        printf("5. Exit\n");

        // Get user input
        printf("\nEnter your choice: ");
        scanf("%d", &input);
        while (getchar() != '\n'); // Clear newline character from input buffer

        switch (input) {
            case 1:
                if (count >= 100) {
                    printf("Library storage is full!\n");
                    break;
                }

                printf("Enter book name: ");
                fgets(lib[count].book_name, 100, stdin);
                lib[count].book_name[strcspn(lib[count].book_name, "\n")] = '\0'; // Remove newline

                printf("Enter author name: ");
                fgets(lib[count].author, 100, stdin);
                lib[count].author[strcspn(lib[count].author, "\n")] = '\0'; // Remove newline

                printf("Enter number of pages: ");
                scanf("%d", &lib[count].pages);

                printf("Enter price: ");
                scanf("%f", &lib[count].price);
                while (getchar() != '\n'); // Clear buffer

                count++;
                printf("Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No books available in the library.\n");
                } else {
                    printf("Book Information:\n");
                    for (int i = 0; i < count; i++) {
                        printf("\nBook Name: %s\n", lib[i].book_name);
                        printf("Author: %s\n", lib[i].author);
                        printf("Pages: %d\n", lib[i].pages);
                        printf("Price: $%.2f\n", lib[i].price);
                        printf("-------------------------------------\n");
                    }
                }
                break;

            case 3:
                if (count == 0) {
                    printf("No books available to search.\n");
                    break;
                }

                printf("Enter author name: ");
                fgets(ar_nm, 100, stdin);
                ar_nm[strcspn(ar_nm, "\n")] = '\0'; // Remove newline

                printf("Books by %s:\n", ar_nm);

                { // Added scope
                    int found = 0; // Declare inside block scope
                    for (int i = 0; i < count; i++) {
                        if (strcmp(lib[i].author, ar_nm) == 0) {
                            printf("Book Name: %s | Pages: %d | Price: Rs %.2f\n", lib[i].book_name, lib[i].pages, lib[i].price);
                            found = 1;
                        }
                    }
                    if (!found) {
                        printf("No books found by this author.\n");
                    }
                } // Closed scope
                break;

            case 4:
                printf("Total number of books in the library: %d\n", count);
                break;

            case 5:
                printf("Exiting program. Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

