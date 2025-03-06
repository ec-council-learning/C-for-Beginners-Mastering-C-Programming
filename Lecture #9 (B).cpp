#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of rows for the diamond pattern: ";
    cin >> n;

    for (int row = 1; row <= 2 * n - 1; ++row) {
    	cout << row;
    	break;
        int spaces = abs(n - row);
        int stars = 2 * n - 1 - 2 * spaces;

        // Print spaces
        for (int count = 1; count <= spaces; ++count) {
            cout << " ";
        }

        // Print stars
        for (int count = 1; count <= stars; ++count) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}

