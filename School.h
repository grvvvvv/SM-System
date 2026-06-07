#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <string>

using namespace std;

class School
{
private:

    string schoolName;

    string principalID;

    int totalClasses;
    int totalSections;

    int nextRollNo;

public:

    School()
    {
        schoolName = "";

        principalID = "";

        totalClasses = 0;
        totalSections = 0;

        nextRollNo = 1;
    }

    void setSchoolInfo(
        string schoolName,
        string principalID,
        int totalClasses,
        int totalSections)
    {
        this->schoolName = schoolName;

        this->principalID = principalID;

        this->totalClasses = totalClasses;
        this->totalSections = totalSections;
    }

    string getSchoolName()
    {
        return schoolName;
    }

    string getPrincipalID()
    {
        return principalID;
    }

    int generateRollNo()
    {
        return nextRollNo++;
    }

    void display()
    {
        cout << "\nSchool Name: "
             << schoolName
             << endl;

        cout << "Principal ID: "
             << principalID
             << endl;

        cout << "Classes: "
             << totalClasses
             << endl;

        cout << "Sections: "
             << totalSections
             << endl;
    }
};

#endif