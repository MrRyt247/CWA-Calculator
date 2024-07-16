#include "semester.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student {
    private:
        string name;
        int index;
        double cwa;
        short int numOfSem;
        Semester* semesterPtr;
        void showPosition(double cwa);
        double calcCWA();
    public:
        Student(string n, int i) : name(n), index(i), cwa(0), numOfSem(0), semesterPtr(nullptr) {}
        ~Student() {
            delete[] semesterPtr;
        }
        void createSemester();
        void showCWA();
        void showSummary();
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
    for(int i=0; i<numOfSem; i++) {
        cout << "Semester " << i+1 << endl;
        cout << setw(50) << left << "Name of Course" << setw(10) << right << "Credit" << setw(10) << "Marks" 
             << setw(10) << "Grade" << endl;
        (semesterPtr+i)->showCourse();
        cout << setw(59) << "Total Credits: " << (semesterPtr+i)->getTotalCredits() << setw(18)
             << "Weighted Marks: " << (semesterPtr+i)->getWeightedMarks() << endl;
        cout << setw(75) << "SWA: " << (semesterPtr+i)->getSWA() << endl;
    }
    cout << "CWA: " << fixed << setprecision(2) << cwa << endl;
    showPosition(cwa);
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

#endif