#ifndef SEMESTER_H
#define SEMESTER_H          // // defines semester header file if not defined
#include "course.h"         // includes course header file
#include <list>             //for list
#include <iomanip>          // for setw manipulator
using namespace std;

class Semester {
    private:
        double swa;
        short int numOfCourses, totalCredits, weightedMarks;
        list<string> trailedCourses;        // list of trailed courses
        Course *coursePtr;                  // a course pointer
    public:
        Semester() : swa(0), totalCredits(0), weightedMarks(0), coursePtr(nullptr) {}       // constructor function
        ~Semester() { delete[] coursePtr; }                 // destructor function

        // setters
        void createCourse();
        double calcSWA();
        int calcTotalCredits(Course* ptr);
        double calcWeightedMarks(Course* ptr);
        void countTrails(Course* ptr);

        // getters
        double getSWA();
        short getTotalCredits();
        short getWeightedMarks();
        void showCourse();
        list<string> getTrails();
};

// Function Defintions

void Semester::showCourse() {
    for(int i=0; i<numOfCourses; i++) {
        cout << setw(50) << left << (coursePtr+i)->getCourseName() << setw(8) << right << (coursePtr+i)->getCredit()
             << setw(12) << (coursePtr+i)->getMarks() << setw(10) << (coursePtr+i)->getGrade() << endl;
    }
}

void Semester::createCourse() {
    cout << "Enter the number of courses for the semester: ";
    cin >> numOfCourses;
    coursePtr = new Course[numOfCourses];

    for(int i=0; i<numOfCourses; i++) {
        cout << i+1; (coursePtr+i)->setDetails();
        (coursePtr+i)->setGrade((coursePtr+i)->getMarks());
    }

    calcWeightedMarks(coursePtr);
    calcTotalCredits(coursePtr);
    countTrails(coursePtr);
    calcSWA();
}

double Semester::calcWeightedMarks(Course* ptr) {
    for(int i=0; i<numOfCourses; i++) {
        weightedMarks += (ptr+i)->getMarks() * (ptr+i)->getCredit();
    }
    return weightedMarks;
}

int Semester::calcTotalCredits(Course* ptr) {
    for(int i=0; i<numOfCourses; i++) {
        totalCredits += (ptr+i)->getCredit();
    }
    return totalCredits;
}

void Semester::countTrails(Course* ptr) {
    for(int i=0; i<numOfCourses; i++) {
        if((ptr+i)->getGrade() == 'F') {
            trailedCourses.push_back((ptr+i)->getCourseName());
        }
    }
}

double Semester::calcSWA() {
    if (totalCredits > 0) {
        swa = static_cast<double>(weightedMarks) / totalCredits;
    } else {
        swa = 0;
    }
    return swa;
}

double Semester::getSWA() {
    return swa;
}

short Semester::getTotalCredits() {
    return totalCredits;
}

short Semester::getWeightedMarks() {
    return weightedMarks;
}

list<string> Semester::getTrails() {
    return trailedCourses;
}

#endif