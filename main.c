#include <stdio.h>
#include <string.h>
#include <student_registry.h>

#define MAX_STUDENTS 100

// variables

int main()
{
    int choice;
    int total = 0;
    Student list[MAX_STUDENTS];

    do
    {
        printf("STUDENT REGISTRY\n\n");
        printf("1. Add a Student\n");
        printf("2. Search by ID\n");
        printf("3. Search by GPA\n");
        printf("4. Search by Major\n");
        printf("5. Display All Students\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent(list, &total);
                break;

            case 2:
                searchById(list, total);
                break;

            case 3:
                findByGPA(list, total);
                break;

            case 4:
                findByMajor(list, total);
                break;

            case 5:
                displayStudents(list, total);
                break;

            case 6:
                printf("Thank you for your service.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 6);

    return 0;
}

