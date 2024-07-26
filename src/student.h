#ifndef STUDENT_H
#define STUDENT_H           // defines student header file if not defined
#include <windows.h>        // for set console attribute to colour the ostream
#include "semester.h"       // includes semester header file

using namespace std;

class Student {
    private:
        string name;
        int index;
        double cwa;
        short int numOfSem;
        Semester* semesterPtr;                  // semester pointer
        void showPosition(double cwa) const;    // private member
        double calcCWA();                       // functions
    public:
        Student(string n, int i) : name(n), index(i), cwa(0), numOfSem(0), semesterPtr(nullptr) {}
        ~Student() { delete[] semesterPtr; }

        // setter
        void createSemester();

        // getters
        void showCWA() const;
        void showSummary() const;
        void showTrails() const;
};

void Student::createSemester() {
    cout << "Enter the number of Semesters to calculate: ";
    cin >> numOfSem;
    semesterPtr = new Semester[numOfSem];

    for(int i=0; i<numOfSem; i++) {
        cout << "Semester " << i+1 << endl;
        (semesterPtr+i)->createCourse();
        cout << endl;
    }
    calcCWA();
}

double Student::calcCWA() {
    double sum = 0;
    for(int i=0; i<numOfSem; i++) {
        sum += (semesterPtr+i)->getSWA();
    }
    cwa = (numOfSem > 0) ? sum / numOfSem : 0;
    return cwa;
}

void colourText(string colour) {
   if(colour == "red") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
   else if(colour == "blue") SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
   else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void Student::showSummary() const {
    cout << "Name: " << name << endl;
    cout << "Index no.: " << index << endl;
    cout << string(80, '-') << endl;
    for(int i=0; i<numOfSem; i++) {
        colourText("red");      // colour the ostream red
        cout << "Year " << (i/2)+1 << '\t' << "Semester " << (i%2)+1 << endl;
        colourText("blue");       // colour the output stream blue
        cout << setw(50) << left << "Name of Course" << setw(8) << right << "Credit" << setw(12) << "Marks" 
             << setw(10) << "Grade" << endl;
        colourText("white");    // colour the ostream white
        (semesterPtr+i)->showCourse();
        cout << setw(55) << "Total Credits: " << setw(3) << (semesterPtr+i)->getTotalCredits() << setw(18)
             << "Weighted Marks: " << setw(4) << (semesterPtr+i)->getWeightedMarks() << endl;
        cout << setw(75) << "SWA: " << setw(4) << fixed << setprecision(2) << (semesterPtr+i)->getSWA() << endl;
    }
    cout << string(80, '-') << endl;
    showCWA();
    showPosition(cwa);
}

void Student::showPosition(double cwa) const {
    if(cwa < 40) cout << "Deferred" << endl;
    else if(cwa < 50) cout << "Pass" << endl;
    else if(cwa < 60) cout << "Second Class Lower" << endl;
    else if(cwa < 70) cout << "Second Class Upper" << endl;
    else cout << "First Class" << endl;
}

void Student::showCWA() const {
    cout << "Cummulative Weighted Average (CWA): " << fixed << setprecision(2) << cwa << endl;
}

void Student::showTrails() const {
    for(int i=0; i<numOfSem; i++) {
        list<string> trails = (semesterPtr+i)->getTrails();
        cout << "Year " << (i/2)+1 << '\t' << "Semester " << (i%2)+1 << endl;
        if(trails.empty()) {
            cout << "None" << endl;
        } else {
            cout << '<';
            for (string trail: (semesterPtr+i)->getTrails()) {
                cout << trail << ", ";
            }
            cout << "\b\b>" << endl;                    // deletes the last two characters from the input stream ", "
        }
    }
}

void displayTitle() {
    colourText("white");        // colour the output stream white
    cout << string(32, '-') << " CWA Calculator " << string(32, '-') << endl;
}

#endif