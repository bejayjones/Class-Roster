#include <iostream>
#include "roster.h"
#include "student.h"
#include <sstream>
#include <vector>

using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, DegreeProgram degree, int daysInCourse1, int daysInCourse2, int daysInCourse3){
    classRosterArray[size] = new Student(studentID, firstName, lastName, emailAddress, age, degree, daysInCourse1, daysInCourse2, daysInCourse3);
    size++;
}
void Roster::remove(string input){
    for(int i = 0; i<5; i++){
        //cardinal variable added to increment if a student is found for deletion
        int del = 0;
        //Compare string received as input from function call
        //to string held in each object's studentID variable       
        if(classRosterArray[i]->getStudentID() == input){
            //if strings equal, delete pointer, increment index to exit loop
            //decrement Roster Array Size
            del = 1;
            size--;
            //delete item from array by moving items with a greater index than removed item to their index - 1
            for(int j = i + 1; j<5; j++){
                classRosterArray[j-1] = classRosterArray[j];
            }
            i = 5;
            cout<<"Student: " << input << " deleted" << endl;
        }
        //Check to see if del was incremented at the end of the loop
        //to indicate a student was deleted
        if(del == 0 && i == 4){
        cout<<"Student with this ID was not found"<<endl;
        }
    }
}
void Roster::parse(string student){
    //create a vector so we can parse our strings
    vector<string> result;
    //create a string stream with the value of a string element from our dataArray
    stringstream sstream(student); 
    //check that the input is valid
    while(sstream.good()){
        //create a substring that will store the whole string minus each iteration of getline
        string sub;
        getline(sstream,sub,',');
        //add each iteration of getline to our vector, result
        result.push_back(sub);
    }
    string studentID = result.at(0);
    string firstName = result.at(1);
    string lastName = result.at(2);
    string emailAddress = result.at(3);
    int age = stoi(result.at(4));
    int daysInCourse1 = stoi(result.at(5));
    int daysInCourse2 = stoi(result.at(6));
    int daysInCourse3 = stoi(result.at(7));
    DegreeProgram degree;
    //Convert string to enum type
    if(result.at(8) == "SECURITY"){
        degree = SECURITY;
    }
    else if(result.at(8) == "NETWORK"){
        degree = NETWORK;
    }
    else if(result.at(8) == "SOFTWARE"){
        degree = SOFTWARE;
    }
    else{
        cout << "Error: Could not Parse degree"<<endl;
    }
    add(studentID, firstName, lastName, emailAddress, age, degree, daysInCourse1, daysInCourse2, daysInCourse3);
}
void Roster::printAll(){
    for(int i = 0; i < size; i++){
        classRosterArray[i]->print();
    }
}
void Roster::printAverageDaysInCourse(string studentID){
    int average = 0;
    for(int i = 0; i<5; i++){
        //Compare string received as input from function call
        //to string held in each object's studentID variable
        if(classRosterArray[i]->getStudentID() == studentID){
        int* numDays = classRosterArray[i]->getNumDays();
        average = (numDays[0] + numDays[1] + numDays[2]) / 3;
        i = 5;
        }
    }
    cout << average << endl;
}
void Roster::printInvalidEmails(){
    for(int i = 0; i<5; i++){
        // Check to see if the email address of each student contains '@' and '.' and does not contain a space
        if(classRosterArray[i]->getEmailAddress().find('@') != string::npos && classRosterArray[i]->getEmailAddress().find('.') != string::npos &&
           classRosterArray[i]->getEmailAddress().find(' ') == string::npos){
        }
        // print all emails that do not meet the above criteria
        else{
            cout << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
}
//filter by a specified degree type then print each student
void Roster::printByDegreeProgram(DegreeProgram degree){
    for(int i = 0; i<5; i++){
        if(classRosterArray[i]->getDegree() == degree){
            classRosterArray[i]->print();
        }
    }
}
//delete dynamically allocated memory
Roster::~Roster(){
    delete [] classRosterArray;
}