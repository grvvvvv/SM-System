#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileManager
{
public:

static bool verifyStudentLogin(
    string id,
    string password)
{
    ifstream file("students.txt");

    string line;

    while(getline(file, line))
    {
        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);

        if(first != string::npos &&
           second != string::npos)
        {
            string storedID =
                line.substr(0, first);

            string storedPassword =
                line.substr(
                    first + 1,
                    second - first - 1);

            if(storedID == id &&
               storedPassword == password)
            {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

static void loadSchools()
{
    ifstream file("schools.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static void loadStudents()
{
    ifstream file("students.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}


    static void saveStudent(string data)
    {
        ofstream file("students.txt", ios::app);

        if(file.is_open())
        {
            file << data << endl;
            file.close();
        }
    }

    static void saveTeacher(string data)
    {
        ofstream file("teachers.txt", ios::app);

        if(file.is_open())
        {
            file << data << endl;
            file.close();
        }
    }

    static void savePrincipal(string data)
    {
        ofstream file("principals.txt", ios::app);

        if(file.is_open())
        {
            file << data << endl;
            file.close();
        }
    }

    static void saveSchool(string data)
    {
        ofstream file("schools.txt", ios::app);

        if(file.is_open())
        {
            file << data << endl;
            file.close();
        }
    }

    static bool searchStudent(string id)
{
    ifstream file("students.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(id) != string::npos)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

static void loadPrincipals()
{
    ifstream file("principals.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static void loadTeachers()
{
    ifstream file("teachers.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static bool verifyPrincipalLogin(
    string id,
    string password)
{
    ifstream file("principals.txt");

    string line;

    while(getline(file, line))
    {
        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);

        if(first != string::npos &&
           second != string::npos)
        {
            string storedID =
                line.substr(0, first);

            string storedPassword =
                line.substr(
                    first + 1,
                    second - first - 1);

            if(storedID == id &&
               storedPassword == password)
            {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

static bool verifyTeacherLogin(
    string id,
    string password)
{
    ifstream file("teachers.txt");

    string line;

    while(getline(file, line))
    {
        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);

        if(first != string::npos &&
           second != string::npos)
        {
            string storedID =
                line.substr(0, first);

            string storedPassword =
                line.substr(
                    first + 1,
                    second - first - 1);

            if(storedID == id &&
               storedPassword == password)
            {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

static void saveParent(string data)
{
    ofstream file("parents.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}

static bool verifyParentLogin(
    string id,
    string password)
{
    ifstream file("parents.txt");

    string line;

    while(getline(file, line))
    {
        size_t first = line.find('|');
        size_t second = line.find('|', first + 1);

        if(first != string::npos &&
           second != string::npos)
        {
            string storedID =
                line.substr(0, first);

            string storedPassword =
                line.substr(
                    first + 1,
                    second - first - 1);

            if(storedID == id &&
               storedPassword == password)
            {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}
static void saveAttendance(string data)
{
    ofstream file("attendance.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}

static void loadAttendance()
{
    ifstream file("attendance.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static void saveResult(string data)
{
    ofstream file("results.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}

static void loadResults()
{
    ifstream file("results.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static void saveFees(string data)
{
    ofstream file("fees.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}

static void loadFees()
{
    ifstream file("fees.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

static void saveNotification(string data)
{
    ofstream file("notifications.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}
static void loadNotifications()
{
    ifstream file("notifications.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}
static void saveComplaint(string data)
{
    ofstream file("complaints.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}
static void loadComplaints()
{
    ifstream file("complaints.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}
static void saveLeaveRequest(string data)
{
    ofstream file("leave_requests.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}
static void loadLeaveRequests()
{
    ifstream file("leave_requests.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}
static bool searchTeacher(string id)
{
    ifstream file("teachers.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(id) != string::npos)
        {
            cout << line << endl;

            file.close();
            return true;
        }
    }

    file.close();

    return false;
}
static void removeTeacher(string teacherID)
{
    ifstream file("teachers.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(teacherID) == string::npos)
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("teachers.txt");
    rename("temp.txt", "teachers.txt");
}
static void removePrincipal(string principalID)
{
    ifstream file("principals.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(principalID) == string::npos)
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("principals.txt");
    rename("temp.txt", "principals.txt");
}
static void deleteSchool(string schoolName)
{
    ifstream file("schools.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(schoolName) == string::npos)
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("schools.txt");
    rename("temp.txt", "schools.txt");
}
static void saveRemovalRequest(string data)
{
    ofstream file("removal_requests.txt", ios::app);

    if(file.is_open())
    {
        file << data << endl;
        file.close();
    }
}
static void loadRemovalRequests()
{
    ifstream file("removal_requests.txt");

    string line;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}
static void updateResult(
    string studentID,
    string subject,
    int newMarks)
{
    ifstream file("results.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line))
    {
        string searchKey =
            studentID + "|" + subject;

        if(line.find(searchKey) != string::npos)
        {
            temp
            << studentID
            << "|"
            << subject
            << "|"
            << newMarks
            << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("results.txt");
    rename("temp.txt", "results.txt");
}
static void showStudentProfile(string id)
{
    ifstream file("students.txt");

    string line;

    while(getline(file, line))
    {
        if(line.find(id) != string::npos)
        {
            cout << line << endl;

            file.close();
            return;
        }
    }

    cout << "Student Not Found!\n";

    file.close();
}
static void editSchool(
    string oldName,
    string newName)
{
    ifstream file("schools.txt");
    ofstream temp("temp.txt");

    string line;

    while(getline(file, line))
    {
        if(line == oldName)
        {
            temp << newName << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("schools.txt");
    rename("temp.txt", "schools.txt");
}


};

#endif