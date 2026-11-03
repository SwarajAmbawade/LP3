
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, capacity;
    int weight[100], profit[100];
    int dp[101][1001] = {0};

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter weights of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> weight[i];

    cout << "Enter profits of items:\n";
    for (int i = 1; i <= n; i++)
        cin >> profit[i];

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i] <= w) {
                dp[i][w] = max(
                    profit[i] + dp[i - 1][w - weight[i]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum profit = " << dp[n][capacity] << endl;

    return 0;
}



// Sample Output
// Enter number of items: 3
// Enter weights of items:
// 10 20 30
// Enter profits of items:
// 60 100 120
// Enter knapsack capacity: 50
// Maximum profit = 220


// Algorithm
// 1. Read the number of items, their weights, profits, and knapsack capacity.
// 2. Initialize the DP table with zeros.
// 3. For each item, check whether its weight fits in the current capacity.
// 4. If it fits, choose the maximum of:
//    - Including the item.
//    - Excluding the item.
// 5. If it does not fit, exclude the item.
// 6. Display the maximum profit.
// Key formula
// \[
// DP[i][w]=
// \begin{cases}
// DP[i-1][w], & wt_i>w\\
// \max(DP[i-1][w],p_i+DP[i-1][w-wt_i]), & wt_i\leq w
// \end{cases}
// \]

// Why is it called 0-1 Knapsack? Each item is either selected completely (1) or not selected (0). You cannot take a fraction of an item.
// Complexity
// - Time complexity: \(O(nW)\)
// - Space complexity: \(O(nW)\)
// Here, \(n\) is the number of items and \(W\) is the knapsack capacity.

// Note: This program supports up to 100 items and a capacity of 1000.




// 1. What is DP?
// DP (Dynamic Programming) is a technique that solves a big problem by breaking it into smaller subproblems and storing their results to avoid recalculating them.

// In this program: We use a 2D array dp[i][w] to store the maximum profit possible using the first i items with capacity w.
// 2. Code explanation (short)
// - weight[] — stores the weights of items.
// - profit[] — stores the profits of items.
// - dp[101][1001] — stores the maximum profit for different items and capacities.
// - if (weight[i] <= w) — checks whether the item fits in the knapsack.
// - max(...) — compares two choices:
//   - Include the item: profit[i] + dp[i-1][w-weight[i]]
//   - Exclude the item: dp[i-1][w]
// - dp[n][capacity] — gives the final maximum profit.
// 3. Working example
// Suppose we have these items:
// Item	Weight	Profit
// 1	10	60
// 2	20	100
// 3	30	120

// Knapsack capacity = 50

// We check which combination gives the maximum profit.
// Selected items	Total weight	Total profit
// 1 + 2	30	160
// 1 + 3	40	180
// 2 + 3	50	220
// 1 + 2 + 3	60	Not allowed

// Maximum profit = 220

// Items 2 and 3 are selected because their combined weight is exactly 50 and their total profit is 220.

// 4. How does DP make the decision?
// For item 3 at capacity 50, the program compares:
// - Include item 3: \(120 + 100 = 220\)
// - Exclude item 3: \(160\)
// Since 220 is greater than 160, it selects item 3 along with item 2.

// Remember for your viva: DP stores the best results of smaller problems in a table and uses them to find the maximum profit without checking every possible combination separately.







// what are real life example of this, and complexity. tell in short
// Real-life applications of 0-1 Knapsack
// 旅行 / Luggage packing: Selecting items to pack in a suitcase with a weight limit.

// Budget allocation: Choosing projects that give maximum profit within a fixed budget.

// Cargo loading: Selecting goods to maximize value in a truck with limited capacity.

// Memory management: Choosing which tasks or data to keep when memory is limited.

// Time and Space Complexity
// Time Complexity: 
// O
// (
// n
// W
// )
// O(nW)

// Space Complexity: 
// O
// (
// n
// W
// )
// O(nW)

// Where:

// n
// n = number of items

// W
// W = knapsack capacity

// Viva tip: The DP solution has pseudo-polynomial time complexity because it depends on the numerical capacity 
// W
// W, not just the number of items 
// n