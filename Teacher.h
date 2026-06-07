#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"

class Teacher : public User
{
private:

    string schoolName;
    string subject;

public:

    Teacher()
    {
        schoolName = "";
        subject = "";
    }

    void setTeacherInfo(
        string schoolName,
        string subject)
    {
        this->schoolName = schoolName;
        this->subject = subject;
    }

    string getSubject()
    {
        return subject;
    }

    string getSchoolName()
    {
        return schoolName;
    }

    void display()
    {
        User::display();

        cout << "School: "
             << schoolName
             << endl;

        cout << "Subject: "
             << subject
             << endl;
    }
};

#endif