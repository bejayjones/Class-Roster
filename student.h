#ifndef student_h
#define student_h
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;


class Student{
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    DegreeProgram degree;
    int numDays[3];
public:
    Student(string, string, string, string, int, DegreeProgram, int, int, int);

    string getStudentID();
    void setStudentID(string);

    string getFirstName();
    void setFirstName(string);

    string getLastName();
    void setLastName(string);

    string getEmailAddress();
    void setEmailAddress(string);

    int getAge();
    void setAge(int);

    DegreeProgram getDegree();
    void setDegree(DegreeProgram);

    int* getNumDays();
    void setNumDays(int*);

    void print();

};

#endif