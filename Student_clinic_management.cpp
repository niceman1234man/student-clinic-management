/*
      Perticipated students
      1.Yihunie Tarekegn                       NSR/2538/14
      2,Abduselam Tofik                         NSR/2950/14
      3.Yordanos Shaba                           NSR/2602/14
      4.Zulkif Azher                              NSR/2652/14


*/
#include <iostream>
#include <string>
using namespace std;

// Structure to represent a student
struct Student {
    int student_id;
    string name;
    string medical_condition;
    char sex;
    string serviceDate;
    Student* next;
};

// Function to create a new student
Student* createStudent(int id, const string& name, const string& condition, char sex, const string& date) {
    Student* student = new Student;
    student->student_id = id;
    student->name = name;
    student->medical_condition = condition;
    student->sex = sex;
    student->serviceDate = date;
    student->next = nullptr;
    return student;
}

// Function to add a student to the list
void addStudent(Student*& head, int id, const string& name, const string& condition, char sex, const string& date) {
    Student* newStudent = createStudent(id, name, condition, sex, date);
    if (head == nullptr) {
        head = newStudent;
    } else {
        Student* currentStudent = head;
        while (currentStudent->next != nullptr) {
            currentStudent = currentStudent->next;
        }
        currentStudent->next = newStudent;
    }
}

// Rest of the code remains the same...
// Function to update student details
void updateStudent(Student* head, int id, const string& newName, const string& newCondition, char newSex) {
    Student* currentStudent = head;
    while (currentStudent != nullptr) {
        if (currentStudent->student_id == id) {
            currentStudent->name = newName;
            currentStudent->medical_condition = newCondition;
            currentStudent->sex = newSex;
            return;
        }
        currentStudent = currentStudent->next;
    }
    cout << "Student not found." << endl;
}

// Function to delete a student from the list
void deleteStudent(Student*& head, int id) {
    if (head == nullptr) {
        cout << "No students in the list." << endl;
        return;
    }

    if (head->student_id == id) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout<<"deleted succesfully\n";
        return;
    }

    Student* currentStudent = head;
    Student* previousStudent = nullptr;
    while (currentStudent != nullptr) {
        if (currentStudent->student_id == id) {
            previousStudent->next = currentStudent->next;
            delete currentStudent;
            cout<<"deleted succesfully\n";
            return;
        }
        previousStudent = currentStudent;
        currentStudent = currentStudent->next;
    }

    cout << "Student not found." << endl;
}

// Function to search for a student by ID
Student* searchStudent(Student* head, int id) {
    Student* currentStudent = head;
    while (currentStudent != nullptr) {
        if (currentStudent->student_id == id) {
            return currentStudent;
        }
        currentStudent = currentStudent->next;
    }
    return nullptr;
}

// Function to display all students
void displayStudents(Student* head) {
    Student* currentStudent = head;
    if(head==NULL)
    cout<<"empity list\n";
    while (currentStudent != nullptr) {
        cout << "Student ID: " << currentStudent->student_id << endl;
        cout << "Name: " << currentStudent->name << endl;
        cout << "Sex: " << currentStudent->sex << endl;
        cout << "Medical Condition: " << currentStudent->medical_condition << endl;
        cout<<"service date:"<<currentStudent->serviceDate<<endl;
        cout << "------------------" << endl;
        currentStudent = currentStudent->next;
    }
}

int main() {
    Student* head = nullptr;

    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Update Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Search Student" << endl;
        cout << "5. Display Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

    switch (choice) {
        case 1: {
            int id;
            string name, condition;
             string serviceDate;

            char sex;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();  // Ignore the newline character
            getline(cin, name);
            cout << "Enter Student Sex (M/F): ";
            cin >> sex;
            cout << "Enter Medical Condition: ";
            cin.ignore();  // Ignore the newline character
            getline(cin, condition);
            cout<<"Enter service date :";
            cin.ignore();  // Ignore the newline character
            getline(cin, serviceDate);
            
            addStudent(head, id, name, condition, sex,serviceDate);
            cout << "Student added successfully." << endl;
            break;
        }
        case 2: {
            int id;
            string name, condition;
            char sex;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Student Name: ";
            cin.ignore();  // Ignore the newline character
            getline(cin, name);
            cout << "Enter Student Sex (M/F): ";
            cin >> sex;
            cout << "Enter Medical Condition: ";
            cin.ignore();  // Ignore the newline character
            getline(cin, condition);
            updateStudent(head, id, name, condition, sex);
            break;
        }
        case 3: {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            deleteStudent(head, id);
            break;
        }
        case 4: {
            int id;
            cout << "Enter Student ID: ";
            cin >> id;
            Student* student = searchStudent(head, id);
            if (student != nullptr) {
                cout << "Student found:" << endl;
                cout << "Student ID: " << student->student_id << endl;
                cout << "Name: " << student->name << endl;
                cout << "Sex: " << student->sex << endl;
                cout << "Medical Condition: " << student->medical_condition << endl;
                cout<<"service date:"<<student->serviceDate<<endl;
            } else {
                cout << "Student not found." << endl;
            }
            break;
        }
        case 5:
            displayStudents(head);
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            return 0;
    }
 }

}