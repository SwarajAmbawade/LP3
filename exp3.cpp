
#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int profit, weight;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;
    Item items[100];
    double maxProfit = 0;

    cout << "Enter number of items: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item "
             << i + 1 << ": ";
        cin >> items[i].profit >> items[i].weight;

        items[i].ratio =
            (double)items[i].profit / items[i].weight;
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    sort(items, items + n, compare);

    for (int i = 0; i < n; i++) {
        if (capacity == 0)
            break;

        if (items[i].weight <= capacity) {
            maxProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            maxProfit += items[i].ratio * capacity;
            capacity = 0;
        }
    }

    cout << "Maximum Profit = " << maxProfit << endl;

    return 0;
}



// Sample Output
// Enter number of items: 3
// Enter profit and weight of item 1: 60 10
// Enter profit and weight of item 2: 100 20
// Enter profit and weight of item 3: 120 30
// Enter knapsack capacity: 50
// Maximum Profit = 240


// Explanation
// Item	Profit	Weight	Profit/Weight
// 1	60	10	6
// 2	100	20	5
// 3	120	30	4

// The items are selected in descending order of their profit-to-weight ratio.
// - Take Item 1 completely: profit = 60, remaining capacity = 40.
// - Take Item 2 completely: profit = 100, remaining capacity = 20.
// - Take \(20/30\) of Item 3: profit = \(120 \times 20/30 = 80\).
// Maximum profit = 60 + 100 + 80 = 240.
// Complexity Analysis
// - Time Complexity: \(O(n\log n)\), due to sorting.
// - Space Complexity: \(O(n)\), for storing the items.
// Result: The Fractional Knapsack problem is successfully solved using the greedy method.



// Fractional Knapsack — Easy Line-by-Line Explanation
// Let's understand your C++ program in a way that's easy to remember for your DAA practical and viva.
// 1. First, understand the problem
// Imagine you have a bag that can carry a maximum weight of 50 kg. You have three items, and each item has a profit and weight.
// Item	Profit	Weight	Profit/Weight
// 1	₹60	10 kg	6
// 2	₹100	20 kg	5
// 3	₹120	30 kg	4

// Your goal is to earn maximum profit without exceeding the bag's capacity.

// The important rule is that you can take a fraction of an item. For example, you can take 20 kg out of an item's 30 kg.

// Greedy strategy: Always choose the item with the highest profit per unit of weight first.


// Part B: Create the Item structure
// A struct groups related information together.

// Every item has three properties:
// - profit — money earned from the item.
// - weight — how much the item weighs.
// - ratio — profit earned per unit of weight.
// For example, Item 1 has profit ₹60 and weight 10 kg.
// ratio = profit/weight =60/10 = 6

// So, Item 1 earns ₹6 per kg.

// Part C: Sorting comparison function
// This function tells sort() which item should come first.
// - If Item A has a higher ratio than Item B, A comes first.
// - The > operator sorts items in descending order of their ratio.
// For example:

// Before sorting: ratios 4, 6, 5

// After sorting: ratios 6, 5, 4

// This is the greedy part of the algorithm: we prioritize the most profitable weight.


// Part D: Start the main function = int main()
// Let's understand each line.
// - int main() — execution of the program starts here.
// - int n, capacity; — n stores the number of items, and capacity stores the maximum weight the bag can hold.
// - Item items[100]; — creates an array that can store up to 100 items.
// - double maxProfit = 0; — stores the total profit. Initially, it is zero because we haven't selected any items.
// double is used because fractional items can produce decimal profits.



// Real-life examples of Fractional Knapsack
// 1. Loading a truck: Select goods with the highest value per kg, and take partial quantities if space is limited.
// 2. Filling a container with fuel: Fill the available capacity with fuel, which can be divided into fractions.
// 3. Selling grains: Sell partial quantities of wheat or rice to maximize profit within a weight limit.
// 4. Allocating raw materials: Choose materials based on their profit per unit when resources are limited.
// Complexity
// - Time Complexity: \(O(n\log n)\) — sorting items by profit-to-weight ratio.
// - Space Complexity: \(O(n)\) — storing the items in an array.
// Viva tip: Fractional Knapsack uses a greedy strategy and gives an optimal solution because items can be divided into fractions.




// https://chatgpt.com/share/6aea5ce5-8dd4-83e8-aa69-78cd44f34486