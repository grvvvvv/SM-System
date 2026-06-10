#ifndef PRINCIPAL_H
#define PRINCIPAL_H


#include "User.h"
#include "FileManager.h"

class Principal : public User
{
private:

    string schoolName;

public:

    Principal()
    {
        schoolName = "";
    }

    void setSchoolName(string schoolName)
    {
        this->schoolName = schoolName;
    }

    string getSchoolName()
    {
        return schoolName;
    }

    void display() override
    {
        User::display();

        cout << "School: "
             << schoolName
             << endl;
    }

    void addTeacher()
{
    string id;
    string password;

    string name;
    string dob;
    string aadhar;
    string phone;

    string school;
    string subject;

    cout << "\nEnter Teacher ID: ";
    getline(cin >> ws, id);

    cout << "Enter Password: ";
    getline(cin, password);

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter DOB: ";
    getline(cin, dob);

    cout << "Enter Aadhar: ";
    getline(cin, aadhar);

    cout << "Enter Phone: ";
    getline(cin, phone);

    cout << "Enter School Name: ";
    getline(cin, school);

    cout << "Enter Subject: ";
    getline(cin, subject);

    string data =
        id + "|" +
        password + "|" +
        name + "|" +
        dob + "|" +
        aadhar + "|" +
        phone + "|" +
        school + "|" +
        subject;

    FileManager::saveTeacher(data);

    cout << "\nTeacher Added Successfully!\n";
}

void viewTeachers()
{
    cout << "\n===== ALL TEACHERS =====\n";

    FileManager::loadTeachers();
}

void displayMenu()
{
    int choice;

    while(true)
    {
        cout << "\n===== PRINCIPAL PANEL =====\n";

        cout << "1. Add Teacher\n";
        cout << "2. View Teachers\n";
        cout << "3. Search Teacher\n";
        cout << "4. Remove Teacher\n";
        cout << "5. View Students\n";
        cout << "6. View Attendance\n";
        cout << "7. View Results\n";
        cout << "8. View Complaints\n";
        cout << "9. View Removal Requests\n";
        cout << "10. Send Notification\n";
        cout << "11. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: addTeacher(); break;
            case 2: viewTeachers(); break;
            case 3: searchTeacher(); break;
            case 4: removeTeacher(); break;
            case 5: viewStudents(); break;
            case 6: viewAttendance(); break;
            case 7: viewResults(); break;
            case 8: viewComplaints(); break;
            case 9: viewRemovalRequests(); break;
            case 10: sendNotification(); break;
            case 11: return;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
}

void sendNotification()
{
    string message;

    cout << "\nEnter Notification: ";

    getline(cin >> ws, message);

    FileManager::saveNotification(message);

    cout << "\nNotification Sent Successfully!\n";
}
void viewComplaints()
{
    cout << "\n===== COMPLAINTS =====\n";

    FileManager::loadComplaints();
}
void viewLeaveRequests()
{
    cout << "\n===== LEAVE REQUESTS =====\n";

    FileManager::loadLeaveRequests();
}
void viewStudents()
{
    cout << "\n===== ALL STUDENTS =====\n";

    FileManager::loadStudents();
}
void viewAttendance()
{
    cout << "\n===== ATTENDANCE RECORDS =====\n";

    FileManager::loadAttendance();
}
void viewResults()
{
    cout << "\n===== RESULT RECORDS =====\n";

    FileManager::loadResults();
}
void searchTeacher()
{
    string id;

    cout << "\nEnter Teacher ID: ";
    getline(cin >> ws, id);

    cout << "\n===== SEARCH RESULT =====\n";

    if(!FileManager::searchTeacher(id))
    {
        cout << "Teacher Not Found!\n";
    }
}
void removeTeacher()
{
    string teacherID;

    cout << "\nEnter Teacher ID to Remove: ";
    getline(cin >> ws, teacherID);

    FileManager::removeTeacher(teacherID);

    cout << "\nTeacher Removed Successfully!\n";
}
void viewRemovalRequests()
{
    cout << "\n===== REMOVAL REQUESTS =====\n";

    FileManager::loadRemovalRequests();
}
bool login(string id, string password)
{
    return FileManager::verifyPrincipalLogin(
        id,
        password);
}

};

#endif