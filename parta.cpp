#include <iostream>
#include <string>

const int numberStudents = 40; // Max

class Course
{
public:
    std::string courseCode;
    std::string courseName;
};

class Grade
{
public:
    int marks;
    char grade;

    Grade()
    {
        marks = 0;
        grade = 'E';
    }

    void calculateGrade(int studentMarks)
    {
        marks = studentMarks;
        if (marks >= 69)
            grade = 'A';
        else if (marks >= 59)
            grade = 'B';
        else if (marks >= 49)
            grade = 'C';
        else if (marks >= 39)
            grade = 'D';
        else
            grade = 'E';
    }

    void displayGrade()
    {
        std::cout << "Marks: " << marks << " Grade: " << grade << '\n';
    }
};

class Student
{
public:
    std::string regNumber;
    std::string name;
    int age;
    Course course;
    Grade grade;
};

class StudentSystem
{
private:
    Student students[numberStudents];
    int studentCount = 0;

public:
    void addStudent()
    {
        if (studentCount < numberStudents)
        {
            Student &newStudent = students[studentCount];

            std::cout << "Enter Registration Number: ";
            std::cin >> newStudent.regNumber;

            std::cout << "Enter Name: ";
            std::cin.ignore();
            std::getline(std::cin, newStudent.name);

            std::cout << "Enter Age: ";
            std::cin >> newStudent.age;

            std::cout << "Enter Course Code: ";
            std::cin.ignore();
            std::getline(std::cin, newStudent.course.courseCode);

            std::cout << "Enter Course Name: ";
            std::getline(std::cin, newStudent.course.courseName);

            studentCount++;
            std::cout << "Student added successfully!\n";
        }
        else
        {
            std::cout << "limit reached!\n";
        }
    }

    void editStudent()
    {
        std::string regNum;
        std::cout << "Enter Registration Number to edit: ";
        std::cin >> regNum;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].regNumber == regNum)
            {
                std::cout << "Editing student " << students[i].name << "\n";
                std::cout << "Enter new Name: ";
                std::cin.ignore();  
                std::getline(std::cin, students[i].name);
                std::cout << "Enter new Age: ";
                std::cin >> students[i].age;
                std::cout << "Enter new Course Code: ";
                std::cin >> students[i].course.courseCode;
                std::cout << "Enter new Course Name: ";
                std::cin.ignore(); 
                std::getline(std::cin, students[i].course.courseName);

                std::cout << "Student details updated!\n";
                return;
            }
        }
        std::cout << "Student not found!\n";
    }

    void addMarks()
    {
        std::string regNum;
        std::cout << "Enter Registration Number: ";
        std::cin >> regNum;

        for (int i = 0; i < studentCount; i++)
        {
            if (students[i].regNumber == regNum)
            {
                if (students[i].grade.marks != 0)
                {
                    std::cout << "Grades cannot be altered!\n";
                    return;
                }

                int marks;
                std::cout << "Enter Marks (0-100): ";
                std::cin >> marks;

                if (marks < 0 || marks > 100)
                {
                    std::cout << "Invalid marks! Should be between 0 and 100.\n";
                    return;
                }

                students[i].grade.calculateGrade(marks);
                std::cout << "Grade calculated!\n";
                return;
            }
        }
        std::cout << "Student not found!\n";
    }

    void displayStudents()
    {
        if (studentCount == 0)
        {
            std::cout << "No students available in the system\n";
            return;
        }

        for (int i = 0; i < studentCount; i++)
        {
            std::cout << "\nReg No: " << students[i].regNumber
                      << "\nName: " << students[i].name
                      << "\nAge: " << students[i].age
                      << "\nCourse: " << students[i].course.courseCode << " - " << students[i].course.courseName;
            students[i].grade.displayGrade();
        }
    }
};

int main()
{
    StudentSystem system;
    int choice;

    do
    {
        std::cout << "\nStudent System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Edit Student\n";
        std::cout << "3. Add Marks and Calculate Grade\n";
        std::cout << "4. Display Students\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system.addStudent();
            break;
        case 2:
            system.editStudent();
            break;
        case 3:
            system.addMarks();
            break;
        case 4:
            system.displayStudents();
            break;
        case 5:
            std::cout << "You exited the program\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
