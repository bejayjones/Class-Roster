#include <iostream>
#include "roster.h"
#include "student.h"
#include <string>

using namespace std;

int main(){
  //Construct an instance of the Roster class
  Roster Class;
  const string studentData[5] =
  {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
  "A5,Brandon,Jones,brandonnoahjones@gmail.com,22,7,40,20,SOFTWARE"};

  cout<<" --------Class--Roster------- "<<endl;
  cout<<" -C867-Scripting-Programming- "<<endl;
  cout<<" -------------C++------------ "<<endl;
  cout<<" ----------002390118--------- "<<endl;
  cout<<" --------Brandon-Jones------- "<<endl;
  //Parse each string in the studentData array
  for(int i = 0; i<5; i++){
    Class.parse(studentData[i]);
  }
  //Print each student object in the classRosterArray
  Class.printAll();
  //Validate that emails are correct, if not, print them
  Class.printInvalidEmails();
  //Calculate average days in course for each student object
  for(int i = 0; i<5; i++){
    Class.printAverageDaysInCourse(Class.classRosterArray[i]->getStudentID());
  }
  //print student objects only belonging to Software degree program
  Class.printByDegreeProgram(SOFTWARE);
  //delete student A3
  Class.remove("A3");
  Class.printAll();
  //try deleting student A3 once more
  Class.remove("A3");
}