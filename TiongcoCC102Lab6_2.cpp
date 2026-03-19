// NAME COUNT: ODD - SWEET C CRUZ TIONGCO (FULLNAME)

#include <iostream>
#include <iomanip>
using namespace std;

struct Book {
    string barcode, title;
    int year, rating;

    static string getCategory(int r) {
        if (r == 5) return "Excellent";
        if (r == 4) return "Very Good";
        if (r == 3) return "Good";
        if (r == 2) return "Fair";
        if (r == 1) return "Poor";
        return "No Rating";
    }
};

int main() {
    string used[1000];
    int count = 0;
    char again;

    do {
        int n;
        cout << "Enter number of books: ";
        cin >> n;
        cin.ignore();

        Book books[n];

        for (int i = 0; i < n; i++) {
            cout << "\nBook " << i + 1 << "\n";

            while (true) {
                cout << "Enter Barcode: ";
                getline(cin, books[i].barcode);

                bool dup = false;
                for (int j = 0; j < count; j++) {
                    if (used[j] == books[i].barcode) {
                        dup = true;
                        break;
                    }
                }

                if (!dup) {
                    used[count++] = books[i].barcode;
                    break;
                }

                cout << "Duplicate barcode! Try again.\n";
            }

            cout << "Enter Title: ";
            getline(cin, books[i].title);

            cout << "Enter Year: ";
            cin >> books[i].year;

            do {
                cout << "Enter Rating (0-5): ";
                cin >> books[i].rating;

                if (books[i].rating < 0 || books[i].rating > 5)
                    cout << "Invalid! Try again.\n";

            } while (books[i].rating < 0 || books[i].rating > 5);

            cin.ignore();
        }

        int bw = 9, tw = 7, yw = 6, rw = 8, cw = 10;

        for (int i = 0; i < n; i++) {
            bw = max(bw, (int)books[i].barcode.length() + 2);
            tw = max(tw, (int)books[i].title.length() + 2);
        }

        cout << "\n" << left
             << setw(bw) << "Barcode"
             << setw(tw) << "Title"
             << setw(yw) << "Year"
             << setw(rw) << "Rating"
             << setw(cw) << "Category" << "\n";

        cout << string(bw + tw + yw + rw + cw, '-') << "\n";

        for (int i = 0; i < n; i++) {
            cout << left
                 << setw(bw) << books[i].barcode
                 << setw(tw) << books[i].title
                 << setw(yw) << books[i].year
                 << setw(rw) << books[i].rating
                 << setw(cw) << Book::getCategory(books[i].rating)
                 << "\n";
        }

        cout << "\nRun again? (y/n): ";
        cin >> again;
        cin.ignore();

    } while (again == 'y' || again == 'Y');

    return 0;
}
