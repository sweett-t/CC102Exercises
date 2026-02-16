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
            cout << "\nEnter Salesperson (1-4): ";
            cin >> salespersonNumber;

            cout << "Enter Product (1-5): ";
            cin >> productNumber;

            cout << "Enter Amount: ";
            cin >> amount;

            sales[productNumber - 1][salespersonNumber - 1] += amount;

            cout << "Add another entry? (y/n): ";
            cin >> continueInput;

        } while (continueInput == 'y' || continueInput == 'Y');


        cout << "\nProduct\t";

        for (int sp = 0; sp < numberOfSalespeople; sp++) {
            cout << "S" << sp + 1 << "\t";
        }

        cout << "Total\n";

        double grandTotal = 0;


        for (int product = 0; product < numberOfProducts; product++) {
            double rowTotal = 0;

            cout << product + 1 << "\t";

            for (int sp = 0; sp < numberOfSalespeople; sp++) {
                cout << fixed << setprecision(2)
                     << sales[product][sp] << "\t";

                rowTotal += sales[product][sp];
            }

            cout << rowTotal << endl;
            grandTotal += rowTotal;
        }


        cout << "Total\t";

        for (int sp = 0; sp < numberOfSalespeople; sp++) {
            double columnTotal = 0;

            for (int product = 0; product < numberOfProducts; product++) {
                columnTotal += sales[product][sp];
            }

            cout << columnTotal << "\t";
        }

        cout << grandTotal << endl;

        cout << "\nRun program again? (y/n): ";
        cin >> runAgain;

    } while (runAgain == 'y' || runAgain == 'Y');

    return 0;
}
