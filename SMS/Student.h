#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include "FileManager.h"

class Student : public User
{
private:

    string schoolName;

    int classNo;
    char section;

    int rollNo;

    int attendancePresent;
    int attendanceAbsent;

    double feesDue;

public:

    Student()
    {
        schoolName = "";

        classNo = 0;
        section = 'A';

        rollNo = 0;

        attendancePresent = 0;
        attendanceAbsent = 0;

        feesDue = 0;
    }

    void setStudentInfo(
        string schoolName,
        int classNo,
        char section,
        int rollNo,
        double feesDue)
    {
        this->schoolName = schoolName;

        this->classNo = classNo;
        this->section = section;

        this->rollNo = rollNo;

        this->feesDue = feesDue;
    }

    void updateAttendance(
        int present,
        int absent)
    {
        attendancePresent = present;
        attendanceAbsent = absent;
    }

    void display()
    {
        User::display();

        cout << "School: " << schoolName << endl;
        cout << "Class: " << classNo << endl;
        cout << "Section: " << section << endl;
        cout << "Roll No: " << rollNo << endl;

        cout << "Present: "
             << attendancePresent
             << endl;

        cout << "Absent: "
             << attendanceAbsent
             << endl;

        cout << "Fees Due: "
             << feesDue
             << endl;
    }

    void displayMenu()
{
    int choice;

    while(true)
    {
        cout << "\n===== STUDENT PANEL =====\n";

        cout << "1. View Profile\n";
        cout << "2. View Attendance\n";
        cout << "3. View Results\n";
        cout << "4. View Fees\n";
        cout << "5. View Notifications\n";
        cout << "6. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: viewProfile(); break;
            case 2: viewAttendance(); break;
            case 3: viewResults(); break;
            case 4: viewFees(); break;
            case 5: viewNotifications(); break;
            case 6: return;

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



//temporary
void showResultSummary()
{
    cout << "\n===== RESULT SUMMARY =====\n";

    cout << "Total Marks: 457\n";
    cout << "Percentage: 91.4%\n";
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
void viewProfile()
{
    string id;

    cout << "\nEnter Student ID: ";

    getline(cin >> ws, id);

    cout << "\n===== PROFILE =====\n";

    FileManager::showStudentProfile(id);
}
bool login(string id, string password)
{
    return FileManager::verifyStudentLogin(
        id,
        password);
}
};

#endif