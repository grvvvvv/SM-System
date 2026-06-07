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
    cout << "\n===== PRINCIPAL PANEL =====\n";

    cout << "1. Add Teacher\n";
    cout << "2. View Teachers\n";
    cout << "3. Logout\n";
}

};

#endif