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

};

#endif