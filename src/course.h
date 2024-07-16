#include <iostream>
#include <string>
#include <limits>
#ifndef COURSE_H
#define COURSE_H
using namespace std;

class Course {
    private:
        string name;
        short credit, marks;
        char grade;
    public:
        void getDetails() {
            cout << ". Enter the name of the course: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            getline(cin, name);
            cout << "   Enter the credit assigned to the course: ";
            cin >> credit;
            cout << "   Enter the marks obtained: ";
            cin >> marks; cout << endl;
        }
        string getCourseName() {
            return name;
        }
        short getMarks() {
            return marks;
        }
        short getCredit() {
            return credit;
        }
        void setGrade(short marks) {
            if(marks < 40) grade = 'F';
            else if(marks < 50) grade = 'D';
            else if(marks < 60) grade = 'C';
            else if(marks < 70) grade = 'B';
            else grade = 'A';
        }
        char getGrade() {
            return grade;
        }
};

#endif