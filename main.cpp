#include <iostream>
#include "src\student.h"            // includes student class
using namespace std;

//  main program

int main() {
    displayTitle();                 // shows the title of this program
    string name;
    int index;

    cout << "Enter your full name: ";
    getline(cin, name);             // Get the line of input
    cout << "Enter your index number: ";
    cin >> index;

    Student obj(name, index);
    obj.createSemester();
    obj.showSummary();

    char choice;
    cout << endl << "Show trails? (y/n)" << endl;
    cin >> choice;
    switch (choice) {
    case 'y':
        obj.showTrails();
        break;
    default:
        break;
    }

    return 0;
}