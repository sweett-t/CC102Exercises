#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    fstream file;

    file.open("original.txt", ios::out);
    if (!file) {
        cout << "Error creating original.txt!" << endl;
        return 1;
    }

    file << "One\nTwo\nThree\nFour\nFive\nSix\n";
    file.close();
    cout << "The file original.txt has been created and written successfully!" << endl;

    string words[6];
    int i = 0;

    file.open("original.txt", ios::in);
    if (!file) {
        cout << "Error opening original.txt!" << endl;
        return 1;
    }

    while (i < 6 && getline(file, words[i])) {
        i++;
    }
    file.close();

    sort(words, words + i);
    cout << "Numbers sorted alphabetically successfully!" << endl;

    file.open("sorted.txt", ios::out);
    if (!file) {
        cout << "Error creating sorted.txt!" << endl;
        return 1;
    }

    for (int j = 0; j < i; j++) {
        file << words[j] << endl;
    }

    file.close();

    cout << "The file sorted.txt has been created successfully!" << endl;

    return 0;
}
