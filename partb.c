#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STUDENTS 40


typedef struct Course {
    char courseCode[20];
    char courseName[50];
} Course;


typedef struct Grade {
    int marks;
    char grade;

    
    void (*calculateGrade)(struct Grade*, int);
} Grade;

void calculateGrade(Grade *g, int marks) {
    g->marks = marks;
    if (marks >= 69) {
        g->grade = 'A';
    } else if (marks >= 59) {
        g->grade = 'B';
    } else if (marks >= 49) {
        g->grade = 'C';
    } else if (marks >= 39) {
        g->grade = 'D';
    } else {
        g->grade = 'E';
    }
}

typedef struct Student {
    char regNumber[20];
    char name[50];
    int age;
    Course course;
    Grade grade;
    struct Student* next;  
} Student;

Student* head = NULL;

void addStudent() {
    if (head == NULL || MAX_STUDENTS > 0) {
        Student *newStudent = (Student *)malloc(sizeof(Student));

        printf("Enter Registration Number: ");
        scanf("%s", newStudent->regNumber);

        printf("Enter Name: ");
        getchar();  
        fgets(newStudent->name, sizeof(newStudent->name), stdin);
        newStudent->name[strcspn(newStudent->name, "\n")] = '\0';  

        printf("Enter Age: ");
        scanf("%d", &newStudent->age);

        printf("Enter Course Code: ");
        getchar();  // to consume the newline character
        fgets(newStudent->course.courseCode, sizeof(newStudent->course.courseCode), stdin);
        newStudent->course.courseCode[strcspn(newStudent->course.courseCode, "\n")] = '\0';

        printf("Enter Course Name: ");
        fgets(newStudent->course.courseName, sizeof(newStudent->course.courseName), stdin);
        newStudent->course.courseName[strcspn(newStudent->course.courseName, "\n")] = '\0';

        newStudent->grade.marks = 0;
        newStudent->grade.grade = 'E';
        newStudent->grade.calculateGrade = calculateGrade;

        
        newStudent->next = head;
        head = newStudent;

        printf("Student added successfully!\n");
    } else {
        printf("Maximum student limit reached!\n");
    }
}


void editStudent() {
    char regNum[20];
    printf("Enter Registration Number to edit: ");
    scanf("%s", regNum);

    Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->regNumber, regNum) == 0) {
            printf("Editing student %s\n", temp->name);
            printf("Enter new Name: ");
            getchar();  
            fgets(temp->name, sizeof(temp->name), stdin);
            temp->name[strcspn(temp->name, "\n")] = '\0';

            printf("Enter new Age: ");
            scanf("%d", &temp->age);

            printf("Enter new Course Code: ");
            getchar(); 
            fgets(temp->course.courseCode, sizeof(temp->course.courseCode), stdin);
            temp->course.courseCode[strcspn(temp->course.courseCode, "\n")] = '\0';

            printf("Enter new Course Name: ");
            fgets(temp->course.courseName, sizeof(temp->course.courseName), stdin);
            temp->course.courseName[strcspn(temp->course.courseName, "\n")] = '\0';

            printf("Student details updated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}


void addMarks() {
    char regNum[20];
    printf("Enter Registration Number to add marks: ");
    scanf("%s", regNum);

    Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->regNumber, regNum) == 0) {
            if (temp->grade.marks != 0) {
                printf("Grades cannot be altered!\n");
                return;
            }

            int marks;
            printf("Enter Marks (0-100): ");
            scanf("%d", &marks);

            if (marks < 0 || marks > 100) {
                printf("Invalid marks! Should be between 0 and 100.\n");
                return;
            }

            temp->grade.calculateGrade(&temp->grade, marks);
            printf("Grade calculated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found!\n");
}


void displayStudents() {
    if (head == NULL) {
        printf("No students available in the system\n");
        return;
    }

    Student *temp = head;
    while (temp != NULL) {
        printf("\nReg No: %s\n", temp->regNumber);
        printf("Name: %s\n", temp->name);
        printf("Age: %d\n", temp->age);
        printf("Course: %s - %s\n", temp->course.courseCode, temp->course.courseName);
        printf("Marks: %d, Grade: %c\n", temp->grade.marks, temp->grade.grade);
        temp = temp->next;
    }
}


int main() {
    int choice;
    do {
        printf("\nStudent System (Linked List)\n");
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Add Marks and Calculate Grade\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addStudent();
            break;
        case 2:
            editStudent();
            break;
        case 3:
            addMarks();
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            printf("You exited the program\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
