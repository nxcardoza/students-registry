#include <stdio.h>
#include <string.h>
#include "student_registry.h"

int main()
{
    int choice;
    Student list[MAX_STUDENTS];[cite: 3]
int total = loadStudentsFromFile(list);[cite: 2]

    do
    {
       	printf("\n");
        printf("DR. SANTOS' STUDENT REGISTRY\n\n");
        printf("1. Add a Student\n");
        printf("2. Search by ID\n");
        printf("3. Search by GPA\n");
        printf("4. Search by Major\n");
        printf("5. Display All Students\n");
        printf("6. Save and Exit\n");
printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
printf("\n");

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
                saveStudentsToFile(list, total);
                printf("Thank you for your service.\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while(choice != 6);

    return 0;
}
