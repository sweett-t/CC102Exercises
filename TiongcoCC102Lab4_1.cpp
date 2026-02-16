#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char runAgain;

    do {
        int numberOfStudents, numberOfQuizzes;

        cout << "Enter number of students: ";
        cin >> numberOfStudents;

        cout << "Enter number of quizzes: ";
        cin >> numberOfQuizzes;

        double quizScores[numberOfStudents][numberOfQuizzes];
        double studentAverage[numberOfStudents];

        for (int student = 0; student < numberOfStudents; student++) {
            cout << "\nEnter scores for Student " << student + 1 << endl;

            double total = 0;

            for (int quiz = 0; quiz < numberOfQuizzes; quiz++) {
                cout << "Quiz " << quiz + 1 << " score: ";
                cin >> quizScores[student][quiz];
                total += quizScores[student][quiz];
            }

            studentAverage[student] = total / numberOfQuizzes;
        }

        cout << "\n";
        cout << setw(8) << "Student";

        for (int quiz = 0; quiz < numberOfQuizzes; quiz++) {
            cout << setw(8) << ("Q" + to_string(quiz + 1));
        }

        cout << setw(10) << "Average" << endl;

        cout << "---------------------------------------------\n";

        for (int student = 0; student < numberOfStudents; student++) {
            cout << setw(8) << student + 1;

            for (int quiz = 0; quiz < numberOfQuizzes; quiz++) {
                cout << setw(8) << quizScores[student][quiz];
            }

            cout << setw(10) << fixed << setprecision(2)
                 << studentAverage[student] << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}