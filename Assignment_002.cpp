#include <iostream>
using namespace std;

void analyzearrGrades(int *gradePtr, int NumStudents, int NumSubjects) {

    cout << "\nGrade Matrix\n\n";
    cout << "Student\t\t";
    for(int j = 0; j < NumSubjects; j++) {
        cout << "Subject" << j + 1 << "\t";
    }
    cout << endl;

    for(int j = 0; j <= NumSubjects; j++) {
        cout << "--------------";
    }
    cout << endl;

    for(int i = 0; i < NumStudents; i++) {
        cout << "Student" << i + 1 << "\t";
        for(int j = 0; j < NumSubjects; j++) {
            cout << *(gradePtr + i * NumSubjects + j) << "\t\t";
        }
        cout << endl;
    }

    cout << "\nAverage Grade Per Student\n";

    for(int i = 0; i < NumStudents; i++) {
        int sum = 0;
        for(int j = 0; j < NumSubjects; j++) {
            sum += *(gradePtr + i * NumSubjects + j);
        }
        double avg = (double)sum / NumSubjects;
        cout << "Student " << i + 1 << ": " << avg << endl;
    }

    int highest = *gradePtr;
    for(int i = 0; i < NumStudents; i++) {
        for(int j = 0; j < NumSubjects; j++) {
            int value = *(gradePtr + i * NumSubjects + j);
            if(value > highest) {
                highest = value;
            }
        }
    }
    cout << "\nHighest Grade in Matrix: " << highest << endl;


}
int main() {
    int NumStudents, NumSubjects;

    cout << "Student Grade Matrix Analyzer\n\n";
    cout << "Enter number of Students: ";
    cin >> NumStudents;
    cout << "Enter number of Subjects: ";
    cin >> NumSubjects;

    int arrGrades[NumStudents][NumSubjects];

    cout << "\nEnter grade\n";

    for(int i = 0; i < NumStudents; i++) {
        for(int j = 0; j < NumSubjects; j++) {
            cout << "Student " << i + 1 << " - Subject " << j + 1 << ": ";
            cin >> arrGrades[i][j];
        }
        cout << endl;
    }

    analyzearrGrades(&arrGrades[0][0], NumStudents, NumSubjects);

    return 0;
}
