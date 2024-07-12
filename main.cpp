#include <iostream>
#include "src\student.h"
using namespace std;

//  main program

int main() {
    cout << "----- CWA Calculator -----" << endl;

    // char choice;
    // cin >> choice;2

    Student obj("Boison", 1818322);
    obj.createSemester();
    obj.showSummary();

    Student obj1("Gyanewaa", 1837422);
    obj1.createSemester();
    obj1.showCWA();

    return 0;
}