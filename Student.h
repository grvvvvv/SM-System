#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"

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
};

#endif