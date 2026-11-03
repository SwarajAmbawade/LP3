
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$',
                                left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(pq.top(), "");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    char chars[n];
    int freq[n];

    cout << "Enter characters and frequencies:\n";

    for (int i = 0; i < n; i++)
        cin >> chars[i] >> freq[i];

    huffman(chars, freq, n);

    return 0;
}


// Sample Input
// Enter number of characters: 4
// Enter characters and frequencies:
// a 5
// b 9
// c 12
// d 13


// Sample Output
// Huffman Codes:
// d : 0
// c : 10
// a : 110
// b : 111


// Note: Huffman codes may differ depending on how equal-frequency nodes are handled. They will still be valid if generated from the correct Huffman tree.
// Complexity Analysis
// - Time Complexity: \(O(n\log n)\), using a min-priority queue.
// - Space Complexity: \(O(n)\), for the Huffman tree and priority queue.
// Result
// Thus, Huffman Encoding was implemented successfully using the greedy strategy, generating variable-length prefix codes based on character frequencies.




// Sample Input
// Enter number of characters: 6
// Enter characters and frequencies:
// a 5
// b 9
// c 12
// d 13
// e 16
// f 45


// Sample Output
// Huffman Codes:
// f : 0
// c : 100
// d : 101
// a : 1100
// b : 1101
// e : 111


// Note: Huffman codes can differ depending on how the program handles ties between equal frequencies. The output above is valid for the given frequencies and a corresponding Huffman tree.
// How the greedy strategy works
// Step	Nodes combined	New frequency
// 1	a(5) + b(9)	14
// 2	c(12) + d(13)	25
// 3	14 + e(16)	30
// 4	25 + 30	55
// 5	f(45) + 55	100

// The final root frequency is 100, equal to the sum of all character frequencies.

// Remember for your viva: Huffman Encoding uses a greedy strategy because it always combines the two nodes with the smallest frequencies at each step.





// Real-life Applications of Huffman Encoding
// 1. File Compression: Used in ZIP and other compression techniques to reduce file size.
// 2. Image Compression: Used in formats like JPEG as part of the compression process.
// 3. Data Transmission: Reduces the number of bits needed to transmit data.
// 4. Multimedia: Helps compress text, images, and other data efficiently.
// Time and Space Complexity
// - Time Complexity: \(O(n\log n)\) — using a min-priority queue.
// - Space Complexity: \(O(n)\) — to store the Huffman tree and priority queue.
// Here, \(n\) is the number of unique characters.

// Viva tip: Frequent characters get shorter codes, while less frequent characters get longer codes.