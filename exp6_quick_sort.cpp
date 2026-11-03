
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Partition function
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void deterministicQuickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        deterministicQuickSort(a, low, p - 1);
        deterministicQuickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(int a[], int low, int high) {
    if (low < high) {
        int randomIndex = low + rand() % (high - low + 1);

        // Select a random pivot
        swap(a[randomIndex], a[high]);

        int p = partition(a, low, high);
        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

// Display array
void display(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int a[100], b[100];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    cout << "\nOriginal array: ";
    display(a, n);

    deterministicQuickSort(a, 0, n - 1);
    cout << "Deterministic Quick Sort: ";
    display(a, n);

    randomizedQuickSort(b, 0, n - 1);
    cout << "Randomized Quick Sort: ";
    display(b, n);

    return 0;
}



// Sample Output
// Enter number of elements: 6
// Enter elements: 45 12 78 23 9 34

// Original array: 45 12 78 23 9 34
// Deterministic Quick Sort: 9 12 23 34 45 78
// Randomized Quick Sort: 9 12 23 34 45 78


// Algorithm
// 1. Deterministic Quick Sort
// 1. Select the last element as the pivot.
// 2. Partition the array around the pivot.
// 3. Recursively sort the left and right subarrays.
// 2. Randomized Quick Sort
// 1. Select a random element as the pivot.
// 2. Swap it with the last element.
// 3. Partition the array around the pivot.
// 4. Recursively sort the left and right subarrays.
// Time Complexity Analysis
// Case	Deterministic Quick Sort	Randomized Quick Sort
// Best	\(O(n\log n)\)	\(O(n\log n)\)
// Average / Expected	\(O(n\log n)\)	\(O(n\log n)\) expected
// Worst	\(O(n^2)\)	\(O(n^2)\)
// Auxiliary space	\(O(n)\) worst case	\(O(n)\) worst case

// Result
// The deterministic and randomized Quick Sort algorithms were implemented successfully. Both sort the elements in ascending order. Randomized Quick Sort uses a random pivot to reduce the likelihood of consistently unbalanced partitions, improving expected performance on many inputs.





// 1. How does Quick Sort work?
// Suppose our array is:

// [45, 12, 78, 23, 9]

// Quick Sort selects a pivot, places smaller elements on its left and larger elements on its right, and repeats the process.
// 2. Important functions
// 1. partition()
// int pivot = a[high];


// - Selects the last element as the pivot.
// - Moves smaller elements to the left and larger elements to the right.
// - Returns the pivot's correct position.
// Example: [45, 12, 78, 23, 9]

// The pivot is 9. After partitioning:

// [9, 12, 78, 23, 45]

// Now 9 is in its correct position.

// 2. deterministicQuickSort()
// int p = partition(a, low, high);
// deterministicQuickSort(a, low, p - 1);
// deterministicQuickSort(a, p + 1, high);


// It always selects the last element as the pivot and recursively sorts the left and right parts.

// 3. randomizedQuickSort()
// int randomIndex = low + rand() % (high - low + 1);
// swap(a[randomIndex], a[high]);


// It selects a random element as the pivot, swaps it with the last element, and then uses the same partition logic.
// 3. Difference between the two

// Deterministic Quick Sort

// Always picks the last element as pivot.

// Example: Pivot = 9




// Randomized Quick Sort

// Picks a random element as pivot.

// Example: Pivot could be 45, 12, or any other element.



// Both produce the same sorted array:

// [9, 12, 23, 45, 78]

// Viva tip: Randomized Quick Sort reduces the chance of worst-case performance, but its worst-case time complexity is still \(O(n^2)\).



// 1. Real-life examples
// - Deterministic Quick Sort: Sorting student marks by always choosing the last mark as the pivot.
// - Randomized Quick Sort: Sorting a large list of product prices by randomly selecting a pivot to reduce the chance of unbalanced partitions.
// 2. Time Complexity
// Case	Deterministic	Randomized
// Best	\(O(n\log n)\)	\(O(n\log n)\)
// Average	\(O(n\log n)\)	\(O(n\log n)\) expected
// Worst	\(O(n^2)\)	\(O(n^2)\)

// Space complexity: \(O(\log n)\) on average; \(O(n)\) in the worst case due to recursion.

// Viva tip: Randomized Quick Sort reduces the likelihood of worst-case performance by selecting a random pivot, but it does not eliminate the worst case.