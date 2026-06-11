#include <iostream>
#include <string>

#include "SuperAdmin.h"
#include "Principal.h"
#include "Teacher.h"
#include "Student.h"
#include "Parent.h"

using namespace std;

int main()
{
    string choice;

    while(true)
    {
        cout << "\n==========================\n";
        cout << " SCHOOL MANAGEMENT SYSTEM\n";
        cout << "==========================\n\n";

        cout << "1. Principal\n";
        cout << "2. Teacher\n";
        cout << "3. Student\n";
        cout << "4. Parent\n\n";

        cout << "Type 'admin' for Super Admin\n";
        cout << "Type 'exit' to Exit\n\n";

        cout << "Enter Choice: ";
        getline(cin >> ws, choice);

        // exit
        if(choice == "exit")
        {
            cout << "\nThank You For Using SMS!\n";
            break;
        }

        // for S-admin
        else if(choice == "admin")
        {
            SuperAdmin admin;

            string password;

            cout << "\nEnter Admin Password: ";
            getline(cin, password);

            if(admin.login(password))
            {
                cout << "\nLogin Successful!\n";
                admin.displayMenu();
            }
            else
            {
                cout << "\nWrong Password!\n";
            }
        }

        // for principal
        else if(choice == "1")
        {
            Principal p;

            string id;
            string password;

            cout << "\nEnter Principal ID: ";
            getline(cin, id);

            cout << "Enter Password: ";
            getline(cin, password);

            if(p.login(id, password))
            {
                cout << "\nLogin Successful!\n";
                p.displayMenu();
            }
            else
            {
                cout << "\nInvalid Credentials!\n";
            }
        }

        // for teacjer
        else if(choice == "2")
        {
            Teacher t;

            string id;
            string password;

            cout << "\nEnter Teacher ID: ";
            getline(cin, id);

            cout << "Enter Password: ";
            getline(cin, password);

            if(t.login(id, password))
            {
                cout << "\nLogin Successful!\n";
                t.displayMenu();
            }
            else
            {
                cout << "\nInvalid Credentials!\n";
            }
        }

        // for student
        else if(choice == "3")
        {
            Student s;

            string id;
            string password;

            cout << "\nEnter Student ID: ";
            getline(cin, id);

            cout << "Enter Password: ";
            getline(cin, password);

            if(s.login(id, password))
            {
                cout << "\nLogin Successful!\n";
                s.displayMenu();
            }
            else
            {
                cout << "\nInvalid Credentials!\n";
            }
        }

        // for parent
        else if(choice == "4")
        {
            Parent p;

            string id;
            string password;

            cout << "\nEnter Parent ID: ";
            getline(cin, id);

            cout << "Enter Password: ";
            getline(cin, password);

            if(p.login(id, password))
            {
                cout << "\nLogin Successful!\n";
                p.displayMenu();
            }
            else
            {
                cout << "\nInvalid Credentials!\n";
            }
        }

        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}