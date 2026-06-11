#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
#include "FileManager.h"

class Teacher : public User
{
private:

    string schoolName;
    string subject;

public:

    Teacher()
    {
        schoolName = "";
        subject = "";
    }

    void setTeacherInfo(
        string schoolName,
        string subject)
    {
        this->schoolName = schoolName;
        this->subject = subject;
    }

    string getSubject()
    {
        return subject;
    }

    string getSchoolName()
    {
        return schoolName;
    }

    void display()
    {
        User::display();

        cout << "School: "
             << schoolName
             << endl;

        cout << "Subject: "
             << subject
             << endl;
    }

    void displayMenu()
{
    int choice;

    while(true)
    {
        cout << "\n===== TEACHER PANEL =====\n";

        cout << "1. Admit Student\n";
        cout << "2. View Students\n";
        cout << "3. Mark Attendance\n";
        cout << "4. Enter Result\n";
        cout << "5. Set Fees\n";
        cout << "6. Search Student\n";
        cout << "7. Update Result\n";
        cout << "8. Request Student Removal\n";
        cout << "9. Send Notification\n";
        cout << "10. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                admitStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                markAttendance();
                break;

            case 4:
                enterResult();
                break;

            case 5:
                setFees();
                break;

            case 6:
                searchStudent();
                break;

            case 7:
                updateResult();
                break;

            case 8:
                requestStudentRemoval();
                break;

            case 9:
                sendNotification();
                break;

            case 10:
                return;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}

void admitStudent()
{
    string studentID;
    string password;

    string name;
    string dob;
    string aadhar;
    string phone;

    string school;

    int classNo;
    char section;
    int rollNo;

    string parentName;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, studentID);

    cout << "Enter Password: ";
    getline(cin, password);

    cout << "Enter Student Name: ";
    getline(cin, name);

    cout << "Enter DOB: ";
    getline(cin, dob);

    cout << "Enter Aadhar: ";
    getline(cin, aadhar);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter School Name: ";
    getline(cin, school);

    cout << "Enter Class: ";
    cin >> classNo;

    cout << "Enter Section: ";
    cin >> section;

    cout << "Enter Roll Number: ";
    cin >> rollNo;

    cin.ignore();

    cout << "Enter Parent Name: ";
    getline(cin, parentName);

    string studentData =
        studentID + "|" +
        password + "|" +
        name + "|" +
        dob + "|" +
        aadhar + "|" +
        phone + "|" +
        school + "|" +
        to_string(classNo) + "|" +
        section + "|" +
        to_string(rollNo) + "|" +
        parentName;

    FileManager::saveStudent(studentData);

    string parentID =
        "PA" + studentID.substr(1);

    string parentData =
        parentID + "|" +
        password + "|" +
        parentName + "|" +
        studentID;

    FileManager::saveParent(parentData);

    cout << "\nStudent Admitted Successfully!\n";
}

void viewStudents()
{
    cout << "\n===== ALL STUDENTS =====\n";

    FileManager::loadStudents();
}

void markAttendance()
{
    string studentID;
    string date;
    char status;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, studentID);

    cout << "Enter Date (DD-MM-YYYY): ";
    getline(cin, date);

    cout << "Enter Status (P/A): ";
    cin >> status;

    string data =
        studentID + "|" +
        date + "|" +
        status;

    FileManager::saveAttendance(data);

    cout << "\nAttendance Marked Successfully!\n";
}
void enterResult()
{
    string studentID;
    string subject;

    int marks;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, studentID);

    cout << "Enter Subject: ";
    getline(cin, subject);

    cout << "Enter Marks: ";
    cin >> marks;

    string data =
        studentID + "|" +
        subject + "|" +
        to_string(marks);

    FileManager::saveResult(data);

    cout << "\nResult Saved Successfully!\n";
}

void setFees()
{
    string studentID;
    int amount;
    string status;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, studentID);

    cout << "Enter Fees Amount: ";
    cin >> amount;

    cin.ignore();

    cout << "Enter Status (Paid/Unpaid): ";
    getline(cin, status);

    string data =
        studentID + "|" +
        to_string(amount) + "|" +
        status;

    FileManager::saveFees(data);

    cout << "\nFees Saved Successfully!\n";
}
void searchStudent()
{
    string id;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, id);

    cout << "\n===== SEARCH RESULT =====\n";

    if(!FileManager::searchStudent(id))
    {
        cout << "Student Not Found!\n";
    }
}
void requestStudentRemoval()
{
    string studentID;
    string reason;

    cout << "\nEnter Student ID: ";

    getline(cin >> ws, studentID);

    cout << "Enter Reason: ";

    getline(cin, reason);

    string data =
        studentID + "|" +
        reason;

    FileManager::saveRemovalRequest(data);

    cout << "\nRemoval Request Sent Successfully!\n";
}
void updateResult()
{
    string studentID;
    string subject;
    int marks;

    cout << "\nEnter Student ID: ";
    getline(cin >> ws, studentID);

    cout << "Enter Subject: ";
    getline(cin, subject);

    cout << "Enter New Marks: ";
    cin >> marks;

    FileManager::updateResult(
        studentID,
        subject,
        marks);

    cout << "\nResult Updated Successfully!\n";
}
void sendNotification()
{
    string message;

    cout << "\nEnter Notification: ";

    getline(cin >> ws, message);

    FileManager::saveNotification(message);

    cout << "\nNotification Sent Successfully!\n";
}
bool login(string id, string password)
{
    return FileManager::verifyTeacherLogin(
        id,
        password);
}
};

#endif