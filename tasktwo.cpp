#include <iostream>

const int numberStudents = 40; // # of students who sat for exam is constant.

struct Course
{
    std::string courseCode;
    std::string courseName;
};

struct Grade
{
    int marks;
    char grade;

    Grade() : marks(0), grade('E') {} // Default

    void calculateGrade(int marks) // grading system
    {
        this->marks = marks;
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

    void displayGrade() const
    {
        std::cout << "Marks: " << marks << "Grade: " << grade << '\n';
    }
};

struct Student
{
    std::string regNumber;
    std::string name;
    int age;
    Course course;
    Grade grade;
};

Student students[numberStudents]; // I used array as member
int studentCount = 0;

void addStudent()
{
    if (studentCount < numberStudents)
    {
        Student &newStudent = students[studentCount]; // reference var declaration, I used it for new students registration

        std::cout << "Enter Registration Number: ";
        std::cin >> newStudent.regNumber;
        std::cout << "Enter Name: ";
        std::cin.ignore();
        std::getline(std::cin, newStudent.name);
        std::cout << "Enter Age: ";
        std::cin >> newStudent.age;
        std::cout << "Enter Course Code: ";
        std::cin >> newStudent.course.courseCode;
        std::cout << "Enter Course Name: ";
        std::cin.ignore();
        std::getline(std::cin, newStudent.course.courseName);

        studentCount++;
        std::cout << "Student added successfully!\n";
    }
    else
    {
        std::cout << "Maximum student limit already registered!\n";
    }
}

// edit student
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
            std::getline(std::cin, students[i].course.courseName); // I used getline to allow spaces too.

            std::cout << "Student details updated!\n";
            return;
        }
    }
    std::cout << "Student not found!\n";
}

// add marks ; calculate grade
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
                std::cout << "Grades cannot be altered.!\n";
                return;
            }

            int marks;
            std::cout << "Enter Marks (0-100): ";
            std::cin >> marks;

            if (marks < 0 || marks > 100)
            {
                std::cout << "Invalid marks! should be between 0 and 100.\n";
                return;
            }

            students[i].grade.calculateGrade(marks);
            std::cout << "Grade calculated!\n";
            return;
        }
    }
    std::cout << "Student not found!\n";
}

// display students
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

int main()
{
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
            std::cout << "You exited the program\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
