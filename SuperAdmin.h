#ifndef SUPERADMIN_H
#define SUPERADMIN_H

#include <iostream>
#include <string>
#include "FileManager.h"

using namespace std;

class SuperAdmin
{
private:

    string password;

public:

    SuperAdmin()
    {
        password = "malik";
    }

    bool login(string enteredPassword)
    {
        return enteredPassword == password;
    }

    void displayMenu()
    {
        cout << "\n===== SUPER ADMIN PANEL =====" << endl;

        cout << "1. Create School" << endl;
        cout << "2. Delete School" << endl;
        cout << "3. Set Principal" << endl;
        cout << "4. View All Schools" << endl;
        cout << "5. Global Notification" << endl;
        cout << "6. Exit" << endl;
    }

void createSchool()
{
    string schoolName;
    string principalID;

    int totalClasses;
    int totalSections;

    cout << "Enter School Name: ";
    getline(cin, schoolName);

    cout << "Enter Principal ID: ";
    getline(cin, principalID);

    cout << "Enter Total Classes: ";
    cin >> totalClasses;

    cout << "Enter Total Sections: ";
    cin >> totalSections;

    string data =
        schoolName + "|" +
        principalID + "|" +
        to_string(totalClasses) + "|" +
        to_string(totalSections);

    FileManager::saveSchool(data);

    cout << "\nSchool Created Successfully!\n";
}

void viewSchools()
{
    cout << "\n===== ALL SCHOOLS =====\n";

    FileManager::loadSchools();
}

void addPrincipal()
{
    string id;
    string password;

    string name;
    string dob;
    string aadhar;
    string phone;

    string school;

    cout << "\nEnter Principal ID: ";
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

    string data =
        id + "|" +
        password + "|" +
        name + "|" +
        dob + "|" +
        aadhar + "|" +
        phone + "|" +
        school;

    FileManager::savePrincipal(data);

    cout << "\nPrincipal Added Successfully!\n";
}

void viewPrincipals()
{
    cout << "\n===== ALL PRINCIPALS =====\n";

    FileManager::loadPrincipals();
}

};

#endif