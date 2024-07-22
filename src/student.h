#ifndef STUDENT_H
#define STUDENT_H           // defines student header file if not defined
#include "semester.h"       // includes semester header file
using namespace std;

class Student {
    private:
        string name;
        int index;
        double cwa;
        short int numOfSem;
        Semester* semesterPtr;              // semester pointer
        void showPosition(double cwa);      // private member
        double calcCWA();                   // functions
    public:
        Student(string n, int i) : name(n), index(i), cwa(0), numOfSem(0), semesterPtr(nullptr) {}
        ~Student() { delete[] semesterPtr; }

        // setter
        void createSemester();

        // getters
        void showCWA();
        void showSummary();
        void showTrails();
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

void Student::showSummary() {
    cout << "Name: " << name << endl;
    cout << "Index no.: " << index << endl;
    cout << string(80, '-') << endl;
    for(int i=0; i<numOfSem; i++) {
        cout << "Year " << (i/2)+1 << '\t' << "Semester " << (i%2)+1 << endl;
        cout << setw(50) << left << "Name of Course" << setw(8) << right << "Credit" << setw(12) << "Marks" 
             << setw(10) << "Grade" << endl;
        (semesterPtr+i)->showCourse();
        cout << setw(55) << "Total Credits: " << setw(3) << (semesterPtr+i)->getTotalCredits() << setw(18)
             << "Weighted Marks: " << setw(4) << (semesterPtr+i)->getWeightedMarks() << endl;
        cout << setw(75) << "SWA: " << setw(4) << fixed << setprecision(2) << (semesterPtr+i)->getSWA() << endl;
    }
    cout << string(80, '-') << endl;
    cout << "CWA: " << fixed << setprecision(2) << cwa << endl;
    showPosition(cwa);
    showTrails();
}

void Student::showPosition(double cwa) {
    if(cwa < 40) cout << "Deferred" << endl;
    else if(cwa < 50) cout << "Pass" << endl;
    else if(cwa < 60) cout << "Second Class Lower" << endl;
    else if(cwa < 70) cout << "Second Class Upper" << endl;
    else cout << "First Class" << endl;
}

void Student::showCWA() {
    cout << "Cummulative Weighted Average(CWA): " << cwa << endl;
}

void Student::showTrails() {
    for(int i=0; i<numOfSem; i++) {
        cout << '<';
        for (string trail: (semesterPtr+i)->getTrails()) {
            cout << trail << ", ";
        }
        cout << "\b\b>" << endl;
    }
}

void displayTitle() {
    cout << string(32, '-') << " CWA Calculator " << string(32, '-') << endl;
}

#endif