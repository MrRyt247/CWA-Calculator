#include <iostream>
#include "src\student.h"            // includes student class
using namespace std;

//  main program

int main() {
    displayTitle();
    string name;
    int index;

    cout << "Enter your full name: ";
    getline(cin, name);             // Get getline of input
    cout << "Enter your index number: ";
    cin >> index;

    Student obj(name, index);
    obj.createSemester();
    obj.showSummary();

    // Student obj1("Gyanewaa", 1837422);
    // obj1.createSemester();
    // obj1.showCWA();

    return 0;
}