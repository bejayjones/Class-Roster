#include "student.h"
#include <iostream>
#include <string>

using namespace std;
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, DegreeProgram degree, int daysInCourse1, int daysInCourse2, int daysInCourse3){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->degree = degree;
    this->numDays[0] = daysInCourse1;
    this->numDays[1] = daysInCourse2;
    this->numDays[2] = daysInCourse3;
}

string Student::getStudentID(){
    return studentID;
}
void Student::setStudentID(string studentID){
    this->studentID = studentID;
}

string Student::getFirstName(){
    return firstName;
}
void Student::setFirstName(string firstName){
    this->firstName = firstName;
}

string Student::getLastName(){
    return lastName;
}
void Student::setLastName(string lastName){
    this->lastName = lastName;
}

string Student::getEmailAddress(){
    return emailAddress;
}
void Student::setEmailAddress(string emailAddress){
    this->emailAddress = emailAddress;
}

int Student::getAge(){
    return age;
}
void Student::setAge(int age){
    this->age = age;
}

DegreeProgram Student::getDegree(){
    return degree;
}
void Student::setDegree(DegreeProgram degree){
    this->degree = degree;
}

int* Student::getNumDays(){
    return numDays;
}
void Student::setNumDays(int* numDays){
    for(int i = 0; i < 3; i++){
        this->numDays[i] = numDays[i];
    }
}
void Student::print(){
    cout << getStudentID() << "    First Name: " << getFirstName() << "   Last Name: " <<
    getLastName() << "   Age: " << getAge() << "    daysInCourse: {" << getNumDays()[0] <<
    ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}   Degree Program: ";
    switch(getDegree()) {
        case NETWORK:
        cout << "NETWORK"<<endl;
        break;
        case SOFTWARE:
        cout << "SOFTWARE" << endl;
        break;
        case SECURITY:
        cout << "SECURITY" << endl;
        break;
    }
}
