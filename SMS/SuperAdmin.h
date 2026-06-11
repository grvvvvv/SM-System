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
    int choice;

    while(true)
    {
        cout << "\n===== SUPER ADMIN PANEL =====\n";

        cout << "1. Create School\n";
        cout << "2. View Schools\n";
        cout << "3. Add Principal\n";
        cout << "4. View Principals\n";
        cout << "5. Delete School\n";
        cout << "6. Remove Principal\n";
        cout << "7. Edit School\n";
        cout << "8. Global Notification\n";
        cout << "9. Logout\n";

        cout << "\nEnter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1: createSchool(); break;
            case 2: viewSchools(); break;
            case 3: addPrincipal(); break;
            case 4: viewPrincipals(); break;
            case 5: deleteSchool(); break;
            case 6: removePrincipal(); break;
            case 7: editSchool(); break;
            case 8: globalNotification(); break;
            case 9: return;

            default:
                cout << "\nInvalid Choice!\n";
        }
    }
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
void removePrincipal()
{
    string principalID;

    cout << "\nEnter Principal ID to Remove: ";

    getline(cin >> ws, principalID);

    FileManager::removePrincipal(principalID);

    cout << "\nPrincipal Removed Successfully!\n";
}
void deleteSchool()
{
    string schoolName;

    cout << "\nEnter School Name to Delete: ";

    getline(cin >> ws, schoolName);

    FileManager::deleteSchool(schoolName);

    cout << "\nSchool Deleted Successfully!\n";
}
void globalNotification()
{
    string message;

    cout << "\nEnter Global Notification: ";

    getline(cin >> ws, message);

    FileManager::saveNotification(message);

    cout << "\nGlobal Notification Sent!\n";
}
void editSchool()
{
    string oldName;
    string newName;

    cout << "\nEnter Old School Name: ";
    getline(cin >> ws, oldName);

    cout << "Enter New School Name: ";
    getline(cin, newName);

    FileManager::editSchool(
        oldName,
        newName);

    cout << "\nSchool Updated Successfully!\n";
}

};

#endif