#include <iostream>
#include <iomanip>
using namespace std;

struct Book {
    string barcode, title;
    int year, rating;
};

string used[1000];
int count = 0;

void input(Book books[], int n) {
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
}

void display(Book books[], int n) {
    int bw = 9, tw = 7, yw = 6, rw = 8, cw = 10;
    for (int i = 0; i < n; i++) {
        bw = max(bw, (int)books[i].barcode.length() + 2);
        tw = max(tw, (int)books[i].title.length() + 2);
    }
    cout << "\n===== BOOK LIST =====\n";
    cout << "\n" << left
         << setw(bw) << "Barcode"
         << setw(tw) << "Title"
         << setw(yw) << "Year"
         << setw(rw) << "Rating"
         << setw(cw) << "Category" << "\n";
    cout << string(bw + tw + yw + rw + cw, '-') << "\n";
    for (int i = 0; i < n; i++) {
        string category;
        if (books[i].rating == 5) category = "Excellent";
        else if (books[i].rating == 4) category = "Very Good";
        else if (books[i].rating == 3) category = "Good";
        else if (books[i].rating == 2) category = "Fair";
        else if (books[i].rating == 1) category = "Poor";
        else category = "No Rating";
        cout << left
             << setw(bw) << books[i].barcode
             << setw(tw) << books[i].title
             << setw(yw) << books[i].year
             << setw(rw) << books[i].rating
             << setw(cw) << category
             << "\n";
    }
}

int main() {
    char again;
    do {
        int n;
        cout << "Enter number of books: ";
        cin >> n;
        cin.ignore();

        Book books[n];

        input(books, n);
        display(books, n);

        cout << "\nRun again? (y/n): ";
        cin >> again;
        cin.ignore();
    } while (again == 'y' || again == 'Y');

    return 0;
}
