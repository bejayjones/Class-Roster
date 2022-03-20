#ifndef roster_h
#define roster_h
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;

class Roster{
    public:
    Student* classRosterArray[5];
    ~Roster();
    void add(string, string, string, string, int, DegreeProgram, int, int, int);
    void parse(string);
    void remove(string);
    int size = 0;
    void printAll();
    void printAverageDaysInCourse(string);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram);
};

#endif