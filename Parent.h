#ifndef PARENT_H
#define PARENT_H

#include "User.h"
#include "FileManager.h"

class Parent : public User
{
private:

    string studentID;
    string studentName;

public:

    Parent()
    {
        studentID = "";
        studentName = "";
    }

    void setParentInfo(
        string studentID,
        string studentName)
    {
        this->studentID = studentID;
        this->studentName = studentName;
    }

    string getStudentID()
    {
        return studentID;
    }

    void display()
    {
        User::display();

        cout << "Student ID: "
             << studentID
             << endl;

        cout << "Student Name: "
             << studentName
             << endl;
    }
void displayMenu()
{
    int choice;

    while(true)
    {
        cout << "\n===== PARENT PANEL =====\n";

        cout << "1. View Student Profile\n";
        cout << "2. View Attendance\n";
        cout << "3. View Results\n";
        cout << "4. View Fees\n";
        cout << "5. View Notifications\n";
        cout << "6. Submit Complaint\n";
        cout << "7. Leave School Request\n";
        cout << "8. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: viewStudentProfile(); break;
            case 2: viewAttendance(); break;
            case 3: viewResults(); break;
            case 4: viewFees(); break;
            case 5: viewNotifications(); break;
            case 6: submitComplaint(); break;
            case 7: leaveSchoolRequest(); break;
            case 8: return;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}
void viewAttendance()
{
    cout << "\n===== ATTENDANCE =====\n";

    FileManager::loadAttendance();
}
void viewResults()
{
    cout << "\n===== RESULTS =====\n";

    FileManager::loadResults();
}

void viewFees()
{
    cout << "\n===== FEES =====\n";

    FileManager::loadFees();
}

void viewNotifications()
{
    cout << "\n===== NOTIFICATIONS =====\n";

    FileManager::loadNotifications();
}
void submitComplaint()
{
    string parentID;
    string complaint;

    cout << "\nEnter Parent ID: ";
    getline(cin >> ws, parentID);

    cout << "Enter Complaint: ";
    getline(cin, complaint);

    string data =
        parentID + "|" +
        complaint;

    FileManager::saveComplaint(data);

    cout << "\nComplaint Submitted Successfully!\n";
}
void leaveSchoolRequest()
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

    FileManager::saveLeaveRequest(data);

    cout << "\nLeave Request Sent!\n";
}
void viewStudentProfile()
{
    string id;

    cout << "\nEnter Student ID: ";

    getline(cin >> ws, id);

    cout << "\n===== STUDENT PROFILE =====\n";

    FileManager::showStudentProfile(id);
}
bool login(string id, string password)
{
    return FileManager::verifyParentLogin(
        id,
        password);
}
};

#endif