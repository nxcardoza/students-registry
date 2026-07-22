#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student_registry.h"

//add student
void addStudent(Student list[], int *total)
{
    if(*total == MAX_STUDENTS)
    {
        printf("Student list is full.\n");
        return;
    }

    Student s; // build it locally, then store

    printf("Enter student ID: ");
    scanf("%d", &s.studentId);

    printf("Enter student Name: ");
    scanf(" %[^\n]", s.studentName);

    printf("Enter student Major: ");
    scanf(" %[^\n]", s.studentMajor);

    printf("Enter student GPA: ");
    scanf("%f", &s.studentGpa);

    printf("Enter student Credits: ");
    scanf("%d", &s.studentCredits);

    list[*total] = s;   // struct assignment copies the whole thing
    (*total)++;

    printf("Student has been sucessfully added!\n");
}

// search by id
void searchById(Student list[], int total)
{
    int search;

    printf("Enter student ID: ");
    scanf("%d", &search);

    for(int i = 0; i < total; i++)
    {
        if(list[i].studentId == search)
        {
            printf("\nID: %d\n", list[i].studentId);
            printf("Name: %s\n", list[i].studentName);
            printf("Major: %s\n", list[i].studentMajor);
            printf("GPA: %.2f\n", list[i].studentGpa);
            printf("Credits: %d\n", list[i].studentCredits);
            return;
        }
    }

    printf("Student not found.\n");
}

// search by gpa
void findByGPA(Student list[], int total)
{
    float search;
    int found = 0;

    printf("Enter minimum GPA: ");
    scanf("%f", &search);

    for(int i = 0; i < total; i++)
    {
        if(list[i].studentGpa >= search)
        {
            printf("%s - %.2f\n", list[i].studentName, list[i].studentGpa);
            found = 1;
        }
    }
    if(found == 0)
        printf("No students found.\n");
}

// search by major
void findByMajor(Student list[], int total)
{
    char search[50];
    int count = 0;

    printf("Enter Major: ");
    scanf(" %[^\n]", search);

    for(int i = 0; i < total; i++)
    {
        if(strcmp(list[i].studentMajor, search) == 0)
        {
            printf("%s\n", list[i].studentName);
            count++;
        }
    }

    printf("Total Students: %d\n", count);
}

// display all students
void displayStudents(Student list[], int total)
{
    if(total == 0)
    {
        printf("No students added.\n");
        return;
    }

    for(int i = 0; i < total; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("ID: %d\n", list[i].studentId);
        printf("Name: %s\n", list[i].studentName);
        printf("Major: %s\n", list[i].studentMajor);
        printf("GPA: %.2f\n", list[i].studentGpa);
        printf("Credits: %d\n", list[i].studentCredits);
    }
}

// save all students to file
void saveStudentsToFile(Student list[], int total)
{
    FILE *file = fopen("students.dat", "w");

    if(file == NULL)
    {
        printf("Error: Cannot open file for saving.\n");
        return;
    }

    for(int i = 0; i < total; i++)
    {
        fprintf(file, "%d|%s|%s|%.2f|%d\n",
                list[i].studentId,
                list[i].studentName,
                list[i].studentMajor,
                list[i].studentGpa,
                list[i].studentCredits);
    }

    fclose(file);
    printf("Saved %d student(s) to file.\n", total);
}

// load all students from file
int loadStudentsFromFile(Student list[])
{
    FILE *file = fopen("students.dat", "r");

    if(file == NULL)
    {
        printf("No existing data file has been found.\n");
        return 0;
    }

    char line[300];
    int total = 0;

    while(fgets(line, sizeof(line), file) != NULL && total < MAX_STUDENTS)
    {
        char *token;

        token = strtok(line, "|");
        list[total].studentId = atoi(token);

        token = strtok(NULL, "|");
        strcpy(list[total].studentName, token);

        token = strtok(NULL, "|");
        strcpy(list[total].studentMajor, token);

        token = strtok(NULL, "|");
        list[total].studentGpa = atof(token);

        token = strtok(NULL, "|\n");
        list[total].studentCredits = atoi(token);

        total++;
    }

    fclose(file);
    printf("Loaded %d student(s) from file.\n", total);
    return total;
}
