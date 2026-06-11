#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>

using namespace std;

class User
{
protected:
    string id;
    string password;

    string name;
    string dob;
    string aadhar;
    string phone;

public:

    User()
    {
        id = "";
        password = "";
        name = "";
        dob = "";
        aadhar = "";
        phone = "";
    }

    void setBasicInfo(
        string id,
        string password,
        string name,
        string dob,
        string aadhar,
        string phone)
    {
        this->id = id;
        this->password = password;
        this->name = name;
        this->dob = dob;
        this->aadhar = aadhar;
        this->phone = phone;
    }

    string getID()
    {
        return id;
    }

    string getPassword()
    {
        return password;
    }

    string getName()
    {
        return name;
    }

    string getDOB()
    {
        return dob;
    }

    string getAadhar()
    {
        return aadhar;
    }

    string getPhone()
    {
        return phone;
    }

    void changePassword(string newPassword)
    {
        password = newPassword;
    }

    virtual void display()
    {
        cout << "\nID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "DOB: " << dob << endl;
        cout << "Phone: " << phone << endl;
    }

    virtual ~User() {}
};

#endif