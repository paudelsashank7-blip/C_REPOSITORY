#include<stdio.h>
#include<stdlib.h>

struct book{
    int id;
    char name[50];
    char pub[50];
};

void next_line(){
    printf("\n\n");
}

void next_tab(){
    printf("\t\t\t");
}

void menu(){
    next_line();
    next_tab(); printf("1: Add Book");
    next_line();
    next_tab(); printf("2: Search Book");
    next_line();
    next_tab(); printf("3: Exit");
    next_line();
}

int main(){
    struct book b1[10];   // increased size
    int n, a=1, i, temp_id;
    int count = 0;        // track books

    next_tab();
    printf("Library Management System");

    do{
        menu();
        printf("Enter your option: ");
        scanf("%d",&n);

        switch(n){

        case 1:
            system("cls");
            next_tab();
            printf("How many books to add: ");
            int num;
            scanf("%d",&num);

            for(i=0;i<num;i++){
                next_line();
                next_tab();
                printf("Give Id: ");
                scanf("%d",&b1[count].id);

                next_line();
                next_tab();
                printf("Give Name: ");
                scanf(" %[^\n]", b1[count].name);

                next_line();
                next_tab();
                printf("Give Publication: ");
                scanf(" %[^\n]", b1[count].pub);

                count++;
            }

            next_line();
            next_tab();
            printf("Books Added Successfully!");
            break;

        case 2:
            if(count == 0){
                next_line();
                next_tab();
                printf("No books available. Add books first.");
                break;
            }

            next_line();
            next_tab();
            printf("Give id to search: ");
            scanf("%d",&temp_id);

            int found = 0;

            for(i=0;i<count;i++){
                if(temp_id == b1[i].id){
                    found = 1;
                    next_line();
                    next_tab();
                    printf("Book Found!");

                    next_line();
                    next_tab();
                    printf("Id = %d", b1[i].id);

                    next_line();
                    next_tab();
                    printf("Name = %s", b1[i].name);

                    next_line();
                    next_tab();
                    printf("Publication = %s", b1[i].pub);
                }
            }

            if(!found){
                next_line();
                next_tab();
                printf("Book not found!");
            }

            break;

        case 3:
            next_line();
            next_tab();
            printf("Exiting...");
            a = 0;
            break;

        default:
            next_line();
            next_tab();
            printf("Invalid option");
        }

        next_line();
        next_tab();
        printf("Press 1 to continue, 0 to exit: ");
        scanf("%d",&a);

        system("cls");

    }while(a != 0);

    return 0;
}