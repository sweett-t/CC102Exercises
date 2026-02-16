#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char runAgain;

    do {
        const int numberOfProducts = 5;
        const int numberOfSalespeople = 4;

        double sales[numberOfProducts][numberOfSalespeople] = {0};

        int salespersonNumber, productNumber;
        double amount;
        char continueInput;

        do {
            cout << "\nEnter Salesperson Number (1-4): ";
            cin >> salespersonNumber;

            cout << "Enter Product Number (1-5): ";
            cin >> productNumber;

            cout << "Enter Dollar Amount Sold: ";
            cin >> amount;

            sales[productNumber - 1][salespersonNumber - 1] += amount;

            cout << "Add another entry? (y/n): ";
            cin >> continueInput;

        } while (continueInput == 'y' || continueInput == 'Y');

        cout << "\n";
        cout << setw(10) << "Product";

        for (int sp = 0; sp < numberOfSalespeople; sp++) {
            cout << setw(10) << sp + 1;
        }

        cout << setw(12) << "Total" << endl;

        cout << "--------------------------------------------------\n";

        double grandTotal = 0;

        for (int product = 0; product < numberOfProducts; product++) {
            double rowTotal = 0;

            cout << setw(10) << product + 1;

            for (int sp = 0; sp < numberOfSalespeople; sp++) {
                cout << setw(10) << fixed << setprecision(2)
                     << sales[product][sp];

                rowTotal += sales[product][sp];
            }

            cout << setw(12) << rowTotal << endl;
            grandTotal += rowTotal;
        }

        cout << "--------------------------------------------------\n";

        cout << setw(10) << "Total";

        for (int sp = 0; sp < numberOfSalespeople; sp++) {
            double columnTotal = 0;

            for (int product = 0; product < numberOfProducts; product++) {
                columnTotal += sales[product][sp];
            }

            cout << setw(10) << columnTotal;
        }

        cout << setw(12) << grandTotal << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}