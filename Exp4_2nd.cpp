
#include <iostream>
using namespace std;

int n;
int board[20][20] = {0};

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check same column
        if (board[i][col] == 1)
            return false;

        // Check upper-left diagonal
        if (col - (row - i) >= 0 &&
            board[i][col - (row - i)] == 1)
            return false;

        // Check upper-right diagonal
        if (col + (row - i) < n &&
            board[i][col + (row - i)] == 1)
            return false;
    }

    return true;
}

bool solve(int row) {
    // All queens placed successfully
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            cout << "Backtracking from row " << row << ", col " << col << endl;
            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int firstCol;

    cout << "Enter board size (N): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Invalid board size!";
        return 0;
    }

    cout << "Enter column for first queen (1 to "
         << n << "): ";
    cin >> firstCol;

    if (firstCol < 1 || firstCol > n) {
        cout << "Invalid column!";
        return 0;
    }

    // Fix the first queen in row 1
// just comment out below line to get normal N-queens code
    board[0][firstCol - 1] = 1;

    // if solve(0) then normal N-Queens code. just put 0
    if (solve(1)) {
        cout << "\nFinal N-Queens Matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "\nNo solution exists with first queen "
             << "in column " << firstCol << ".\n";
    }

    return 0;
}




// Algorithm (Step-by-Step)

// 1. Initialize and Input: Read the board size N and the column position firstCol for the first queen.
// 2. Place First Queen: Position the first queen at row 0 and column firstCol - 1.
// 3. Start Backtracking: Call the recursive function solve(row = 1) to place queens in the remaining rows.
// 4. Safety Check (isSafe): For a given cell (row, col), verify it is safe by checking:
// 	• Column: No queen exists in the same column in previous rows.
// 	• Left Diagonal: No queen exists diagonally up-left.
// 	• Right Diagonal: No queen exists diagonally up-right.
// 5. Recursive Exploration:
// 	• If a cell is safe, place a queen (board[row][col] = 1) and move to row + 1.
// 	• If all N queens are placed (row == N), return true (solution found).
// 	• If no columns are safe in the current row, clear the current cell (board[row][col] = 0) and backtrack to the previous row.
// 6. Output: Print the final matrix if a solution exists, otherwise print a "No solution" message.

// Sample Input & Output


// Sample Input

// text
// Enter board size (N): 4
// Enter column for first queen (1 to 4): 2

// Sample Output

// text
// Final N-Queens Matrix:
// 0 1 0 0 
// 0 0 0 1 
// 1 0 0 0 
// 0 0 1 0 


#include <iostream>
using namespace std;

int n;
int board[20][20] = {0};

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check same column
        if (board[i][col] == 1)
            return false;

        // Check upper-left diagonal
        if (col - (row - i) >= 0 &&
            board[i][col - (row - i)] == 1)
            return false;

        // Check upper-right diagonal
        if (col + (row - i) < n &&
            board[i][col + (row - i)] == 1)
            return false;
    }

    return true;
}

bool solve(int row) {
    // All queens placed successfully
    if (row == n)
        return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            if (solve(row + 1))
                return true;

            // Backtrack: remove the queen
            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int firstCol;

    cout << "Enter board size (N): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "Invalid board size!";
        return 0;
    }

    cout << "Enter column for first queen (1 to "
         << n << "): ";
    cin >> firstCol;

    if (firstCol < 1 || firstCol > n) {
        cout << "Invalid column!";
        return 0;
    }

    // Fix the first queen in row 1
// just comment out below line to get normal N-queens code
    board[0][firstCol - 1] = 1;

    // if solve(0) then normal N-Queens code. just put 0
    if (solve(1)) {
        cout << "\nFinal N-Queens Matrix:\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    } else {
        cout << "\nNo solution exists with first queen "
             << "in column " << firstCol << ".\n";
    }

    return 0;
}





// Algorithm (Step-by-Step)

// 1. Initialize and Input: Read the board size N and the column position firstCol for the first queen.
// 2. Place First Queen: Position the first queen at row 0 and column firstCol - 1.
// 3. Start Backtracking: Call the recursive function solve(row = 1) to place queens in the remaining rows.
// 4. Safety Check (isSafe): For a given cell (row, col), verify it is safe by checking:
// 	• Column: No queen exists in the same column in previous rows.
// 	• Left Diagonal: No queen exists diagonally up-left.
// 	• Right Diagonal: No queen exists diagonally up-right.
// 5. Recursive Exploration:
// 	• If a cell is safe, place a queen (board[row][col] = 1) and move to row + 1.
// 	• If all N queens are placed (row == N), return true (solution found).
// 	• If no columns are safe in the current row, clear the current cell (board[row][col] = 0) and backtrack to the previous row.
// 6. Output: Print the final matrix if a solution exists, otherwise print a "No solution" message.

// Sample Input & Output


// Sample Input

// text
// Enter board size (N): 4
// Enter column for first queen (1 to 4): 2
// Use code with caution.

// Sample Output

// text
// Final N-Queens Matrix:
// 0 1 0 0 
// 0 0 0 1 
// 1 0 0 0 
// 0 0 1 0 
// Use code with caution.

// Explanation of the Output

// The code modifies the standard N-Queens problem by forcing the user's choice for the very first row.
// 1. Row 0: The user selected column 2. In 0-indexed C++ arrays, this places a queen at board[0][1]. Matrix: 0 1 0 0.
// 2. Row 1: The algorithm skips checking column 0 and 1 (attacked by the first queen) and successfully places a queen at column 3 (board[1][3]). Matrix: 0 0 0 1.
// 3. Row 2: The algorithm finds a safe spot at column 0 (board[2][0]), away from the attacking ranges of the first two queens. Matrix: 1 0 0 0.
// 4. Row 3: The last remaining safe spot is column 2 (board[3][2]), completing the configuration. Matrix: 0 0 1 0.
// Because a valid configuration was found, the program prints the complete 4x4 matrix where 1 represents a queen and 0 represents an empty space.





// what are real life example of this, and complexity. tell in short
// 1. Real-life applications of Backtracking
// Sudoku solving: Try a number; if it causes a conflict, undo it and try another.

// Timetable scheduling: Assign classes to time slots while avoiding clashes.

// Maze solving: Explore a path; if it leads to a dead end, go back and try another.

// N-Queens: Place queens without allowing any two to attack each other.

// Puzzle solving: Explore possible moves until a valid solution is found.

// 2. Complexity of N-Queens
// Time complexity: 
// O
// (
// N!
// )
// O(N!) — commonly given for the standard backtracking approach.

// Space complexity: 
// O
// (
// N
// 2
// )
// O(N 
// 2
//  ) for the board matrix, plus 
// O
// (
// N
// )
// O(N) recursion stack space.

// Viva tip: Backtracking is a technique that builds a solution step by step and undoes choices whenever they lead to a dead end.