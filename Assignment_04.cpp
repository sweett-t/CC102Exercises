#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file;

    file.open("color.txt", ios::out);
    if (!file) {
        cout << "Error creating color.txt!" << endl;
        return 1;
    }

    file << "Red\nBlue\nGreen\nYellow\nPurple\n";
    file.close();
    cout << "The file color.txt has been created and written successfully!" << endl;

    file.open("color.txt", ios::in);
    if (!file) {
        cout << "Error opening color.txt!" << endl;
        return 1;
    }

    fstream copyFile;
    copyFile.open("color_copy.txt", ios::out);
    if (!copyFile) {
        cout << "Error creating color_copy.txt!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        copyFile << line << endl;
    }

    file.close();
    copyFile.close();

    cout << "The file color_copy.txt has been created successfully (copy complete)!" << endl;

    return 0;
}
