#include <iostream>
#include <string>

using namespace std;

class Course {
public:
    string courseCode;
    string courseName;

    Course(string code, string name) : courseCode(code), courseName(name) {}
};

class Grade {
public:
    int marks;
    char grade;

    Grade() : marks(0), grade('E') {}

    void calculateGrade(int marks) {
        this->marks = marks;
        if (marks >= 69) this->grade = 'A';
        else if (marks >= 59) this->grade = 'B';
        else if (marks >= 49) this->grade = 'C';
        else if (marks >= 39) this->grade = 'D';
        else this->grade = 'E';
    }

    void displayGrade() {
        cout << "Marks: " << marks << " Grade: " << grade << endl;
    }
};

class Student {
public:
    string regNumber;
    string name;
    int age;
    Course *course;
    Grade grade;

    Student(string reg, string name, int age, Course *course, int marks)
        : regNumber(reg), name(name), age(age), course(course) {
        this->grade.calculateGrade(marks);
    }

    void editStudent(string name, int age, Course *course) {
        this->name = name;
        this->age = age;
        this->course = course;
    }

    void displayStudent() {
        cout << "Reg: " << regNumber << ", Name: " << name << ", Age: " << age
             << ", Course: " << course->courseCode << " - " << course->courseName << endl;
        grade.displayGrade();
    }
};

class Node {
public:
    Student *student;
    Node *next;

    Node(Student *student) : student(student), next(nullptr) {}
};

class StudentList {
public:
    Node *head;
    int size;

    StudentList() : head(nullptr), size(0) {}

    void addStudent(string regNumber, string name, int age, Course *course, int marks) {
        Student *student = new Student(regNumber, name, age, course, marks);
        Node *newNode = new Node(student);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    void editStudent(string regNumber, string name, int age, Course *course) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->student->regNumber == regNumber) {
                temp->student->editStudent(name, age, course);
                cout << "Student details updated!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!" << endl;
    }

    void addMarks(string regNumber, int marks) {
        Node *temp = head;
        while (temp != nullptr) {
            if (temp->student->regNumber == regNumber) {
                temp->student->grade.calculateGrade(marks);
                cout << "Marks and Grade updated!" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student not found!" << endl;
    }

    void displayStudents() {
        if (head == nullptr) {
            cout << "No students available." << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr) {
            temp->student->displayStudent();
            temp = temp->next;
        }
    }
};

int main() {
    StudentList studentList;
    string regNumber, name, courseCode, courseName;
    int age, marks;
    int choice;

    while (true) {
        cout << "\nStudent Management System (Linked List)" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Edit Student" << endl;
        cout << "3. Add Marks and Calculate Grade" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                cout << "Enter Registration Number: ";
                getline(cin, regNumber);

                cout << "Enter Name: ";
                getline(cin, name);

                cout << "Enter Age: ";
                cin >> age;
                cin.ignore(); 

                cout << "Enter Course Code: ";
                getline(cin, courseCode);

                cout << "Enter Course Name: ";
                getline(cin, courseName);

                cout << "Enter Marks (0-100): ";
                cin >> marks;

                Course *course = new Course(courseCode, courseName);
                studentList.addStudent(regNumber, name, age, course, marks);
                break;
            }
            case 2: {
                cout << "Enter Registration Number to edit: ";
                getline(cin, regNumber);

                cout << "Enter new Name: ";
                getline(cin, name);

                cout << "Enter new Age: ";
                cin >> age;
                cin.ignore(); 

                cout << "Enter new Course Code: ";
                getline(cin, courseCode);

                cout << "Enter new Course Name: ";
                getline(cin, courseName);

                Course *course = new Course(courseCode, courseName);
                studentList.editStudent(regNumber, name, age, course);
                break;
            }
            case 3: {
                cout << "Enter Registration Number to add marks: ";
                getline(cin, regNumber);

                cout << "Enter Marks (0-100): ";
                cin >> marks;

                studentList.addMarks(regNumber, marks);
                break;
            }
            case 4: {
                studentList.displayStudents();
                break;
            }
            case 5: {
                cout << "Exiting the program..." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }

    return 0;
}
