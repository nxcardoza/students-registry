#ifndef STUDENT_REGISTRY_H 
#define STUDENT_REGISTRY_H 

#define MAX_STUDENTS 100

typedef struct {
    int studentId;
    char studentName[50];
    char studentMajor[50];
    float studentGpa;
    int studentCredits;
} Student;

void addStudent(Student list[], int *total);
void searchById(Student list[], int total);
void findByGPA(Student list[], int total);
void findByMajor(Student list[], int total);
void displayStudents(Student list[], int total);

void saveStudentsToFile(Student list[], int total);
int loadStudentsFromFile(Student list[]);

#endif
