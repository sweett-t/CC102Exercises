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

        // Input scores
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

        cout << "\nStudent\t";

        for (int quiz = 0; quiz < numberOfQuizzes; quiz++) {
            cout << "Q" << quiz + 1 << "\t";
        }

        cout << "Average\n";

        for (int student = 0; student < numberOfStudents; student++) {
            cout << student + 1 << "\t";

            for (int quiz = 0; quiz < numberOfQuizzes; quiz++) {
                cout << quizScores[student][quiz] << "\t";
            }

            cout << fixed << setprecision(2)
                 << studentAverage[student] << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
