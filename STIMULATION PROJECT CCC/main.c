#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int issued;
    int issueDay;
    int issueMonth;
    int issueYear;
};

struct Book library[MAX];
int count = 0;

void addBook() {
    printf("Enter Book ID: ");
    scanf("%d", &library[count].id);
    printf("Enter Title: ");
    scanf(" %[^\n]s", library[count].title);
    printf("Enter Author: ");
    scanf(" %[^\n]s", library[count].author);
    library[count].issued = 0;
    count++;
}

void displayBooks() {
    if(count == 0) { printf("No books available\n"); return; }
    for(int i=0;i<count;i++){
        printf("\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
        library[i].id, library[i].title, library[i].author,
        library[i].issued ? "Issued" : "Available");
    }
}

void searchBook() {
    int id, found=0;
    printf("Enter Book ID: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(library[i].id==id){
            printf("Book Found\nTitle: %s\nAuthor: %s\nStatus: %s\n",
            library[i].title, library[i].author,
            library[i].issued? "Issued" : "Available");
            found=1; break;
        }
    }
    if(!found) printf("Book Not Found\n");
}

void issueBook() {
    int id, found=0;
    printf("Enter Book ID to Issue: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(library[i].id==id){
            if(library[i].issued){
                printf("Book already issued\n");
                return;
            }
            library[i].issued=1;
            printf("Enter issue date (DD MM YYYY): ");
            scanf("%d %d %d",&library[i].issueDay,&library[i].issueMonth,&library[i].issueYear);
            printf("Book Issued Successfully\n");
            found=1; break;
        }
    }
    if(!found) printf("Book Not Found\n");
}

void returnBook() {
    int id, found=0, d,m,y;
    printf("Enter Book ID to Return: ");
    scanf("%d",&id);

    for(int i=0;i<count;i++){
        if(library[i].id==id){
            if(!library[i].issued){
                printf("Book was not issued\n");
                return;
            }

            printf("Enter return date (DD MM YYYY): ");
            scanf("%d %d %d",&d,&m,&y);

            int daysLate = (d + m*30 + y*365) - (library[i].issueDay + library[i].issueMonth*30 + library[i].issueYear*365);
            daysLate -= 14;  
            if(daysLate > 0){
                printf("Late by %d days. Fine = ₹%d\n",daysLate*5,daysLate);
            } else {
                printf("Returned on time. No fine.\n");
            }
            library[i].issued=0;
            found=1;
            break;
        }
    }
    if(!found) printf("Book Not Found\n");
}

void deleteBook() {
    int id, found=0;
    printf("Enter Book ID to Delete: ");
    scanf("%d",&id);
    for(int i=0;i<count;i++){
        if(library[i].id==id){
            for(int j=i;j<count-1;j++) library[j]=library[j+1];
            count--;
            printf("Book Deleted Successfully\n");
            found=1;
            break;
        }
    }
    if(!found) printf("Book Not Found\n");
}

int main() {
    int choice;
    while(1){
        printf("\n====== LIBRARY MANAGEMENT SYSTEM ======\n");
        printf("1. Add Book\n2. Display Books\n3. Search Book\n4. Issue Book\n5. Return Book\n6. Delete Book\n7. Exit\nChoice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}