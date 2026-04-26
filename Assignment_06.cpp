#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int countPrimes(const char* filename) {
    fstream file;
    file.open(filename, ios::in);

    int num, count = 0;

    if (!file) {
        cout << "Error opening file." << endl;
        return 0;
    }

    while (file >> num) {
        if (isPrime(num)) {
            count++;
        }
    }

    file.close();
    return count;
}

int main() {
    int primeCount = countPrimesInFile("nums.txt");

    cout << "Number of prime numbers: " << primeCount << endl;

    return 0;
}
