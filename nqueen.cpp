#include <bits/stdc++.h>
using namespace std;
int x[20];  // Position array
int solutionCount = 0;
bool isSafe(int row, int col) {
    for (int i = 1; i < row; ++i) {
        if (x[i] == col || abs(x[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    cout << "\n\nSolution " << ++solutionCount << ":\n\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i] == j)
                cout << " Q ";
            else
                cout << " - ";
        }
        cout << endl;
    }
}

// Recursive backtracking function
void solveNQueens(int row, int n) {
    for (int col = 1; col <= n; ++col) {
        if (isSafe(row, col)) {
            x[row] = col;
            if (row == n)
                printSolution(n);
            else
                solveNQueens(row + 1, n);
        }
    }
}
int main() {
    int n;
    cout << "Enter number of Queens: ";
    cin >> n;
    solveNQueens(1, n);
    if (solutionCount == 0)
        cout << "No solutions found.\n";
    else
        cout << "\nTotal solutions: " << solutionCount << endl;
    return 0;
}
