#include <iostream>
using namespace std;

// Function to calculate binomial coefficient (nCr)
int binomialCoeff(int n, int r) {
    int res = 1;
    if (r > n - r)
        r = n - r; // Since C(n, r) == C(n, n-r)

    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

// Function to print Pascal's Triangle
void pascal_triangle(int n) {
    for (int i = 0; i < n; i++) {
        // Print spaces for alignment
        for (int j = 0; j < n - i - 1; j++)
            cout << "  ";

        // Print Pascal's Triangle values
        for (int j = 0; j <= i; j++)
            cout << binomialCoeff(i, j) << "   ";

        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter Number of lines: ";
    cin >> n;
    pascal_triangle(n);
    return 0;
}

 

