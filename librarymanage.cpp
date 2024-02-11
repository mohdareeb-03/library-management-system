#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    struct Book* next;
};
void greetings(){
    printf("\n\n");
    printf("\t\t\t\t\t      ****************************************\n");
    printf("\t\t\t\t\t      *                                      *\n");
    printf("\t\t\t\t\t      *                                      *\n");
    printf("\t\t\t\t\t      *     ----------------------------     *\n");
    printf("\t\t\t\t\t      *      LIBRARY MANAGEMENT SYSTEM       *\n");
    printf("\t\t\t\t\t      *     ----------------------------     *\n");
    printf("\t\t\t\t\t      *                                      *\n");
    printf("\t\t\t\t\t      *                                      *\n");
    printf("\t\t\t\t\t      ****************************************\n");
    printf("\n\n");
    printf("\t\t\t\t\t      *         MOHAMMAD AREEB               *\n");
    printf("\t\t\t\t\t      *        Roll No: 2200290100103        *\n");
    printf("\t\t\t\t\t      *        BRANCH: CSE SECTION: B        *\n");
}

struct Book* head = NULL;

void addBook(int id, const char* title, const char* author) {
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    newBook->id = id;
    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->next = head;
    head = newBook;
    printf("Book added successfully.\n");
}

void deleteBook(int id) {
    struct Book* current = head;
    struct Book* prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Book not found.\n");
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
free(current);
    printf("Book deleted successfully.\n");
}

void searchBook(int id) {
    struct Book* current = head;

    while (current != NULL) {
        if (current->id == id) {
            printf("Book found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", current->id, current->title, current->author);
            return;
        }
        current = current->next;
    }

    printf("Book not found.\n");
}

void displayBooks() {
    struct Book* current = head;

    if (current == NULL) {
        printf("The library is empty.\n");
        return;
    }

    printf("Library Books:\n");
    while (current != NULL) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", current->id, current->title, current->author);
        current = current->next;
    }
}

int main() {
    int choice, id;
    char title[100], author[100];
    greetings();
    while (1) {
        printf("\nLibrary Management System Menu:\n");
        printf("1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Search for a book\n");
        printf("4. Display all books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter book ID: ");
                scanf("%d",&id);
                printf("enter title: ");
                scanf("%s",&title);
                printf("enter author: ");
				scanf("%s",&author);
                addBook(id, title, author);
                break;
            case 2:
                printf("Enter the ID of the book to delete: ");
                scanf("%d", &id);
                deleteBook(id);
                break;
            case 3:
                printf("Enter the ID of the book to search for: ");
                scanf("%d", &id);
                searchBook(id);
                break;
            case 4:
                displayBooks();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
