#include "course.h"
#include <iomanip>
#ifndef SEMESTER_H
#define SEMESTER_H

using namespace std;
int numOfCourses;
class Semester {
    private:
        double swa;
        short int totalCredits, weightedMarks;
        Course *coursePtr;
    public:
        Semester() : swa(0), totalCredits(0), weightedMarks(0), coursePtr(nullptr) {}
        ~Semester() { delete[] coursePtr; }
        void createCourse();
        void showCourse();
        double calcSWA();
        int calcTotalCredits(Course* ptr);
        double calcWeightedMarks(Course* ptr);
        double getSWA();
        short getTotalCredits();
        short getWeightedMarks();
};

void Semester::showCourse() {
    for(int i=0; i<numOfCourses; i++) {
        cout << setw(50) << left << (coursePtr+i)->getCourseName() << setw(10) << right << (coursePtr+i)->getCredit()
             << setw(10) << (coursePtr+i)->getMarks() << setw(10) << (coursePtr+i)->getGrade() << endl;
    }
}

void Semester::createCourse() {
    cout << "Enter the number of courses for the semester: ";
    cin >> numOfCourses;
    coursePtr = new Course[numOfCourses];

    for(int i=0; i<numOfCourses; i++) {
        cout << i+1; (coursePtr+i)->getDetails();
        (coursePtr+i)->setGrade((coursePtr+i)->getMarks());
    }

    calcWeightedMarks(coursePtr);
    calcTotalCredits(coursePtr);
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

#endif