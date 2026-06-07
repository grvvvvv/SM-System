#ifndef PARENT_H
#define PARENT_H

#include "User.h"

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
};

#endif