#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Huffman Tree Node
struct Node {
    char ch;           // Character
    int freq;          // Frequency
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;  // Min-heap based on frequency
    }
};

// Recursive function to generate Huffman codes
void generateCodes(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

// Function to build Huffman Tree and return root
Node* buildHuffmanTree(const unordered_map<char, int> &freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create leaf nodes for each character
    for (auto pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman Tree
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();  // Root of the Huffman Tree
}

// Encode input string using Huffman codes
string encode(const string &text, unordered_map<char, string> &huffmanCode) {
    string encodedStr = "";
    for (char c : text) {
        encodedStr += huffmanCode[c];
    }
    return encodedStr;
}

// Decode encoded string using Huffman Tree
string decode(const string &encodedStr, Node* root) {
    string decodedStr = "";
    Node* current = root;

    for (char bit : encodedStr) {
        if (bit == '0') current = current->left;
        else current = current->right;

        // Leaf node
        if (!current->left && !current->right) {
            decodedStr += current->ch;
            current = root;  // Go back to root for next character
        }
    }
    return decodedStr;
}

int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);

    // Step 1: Count frequency of each character
    unordered_map<char, int> freqMap;
    for (char c : text) freqMap[c]++;

    // Step 2: Build Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Step 3: Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Step 4: Display Huffman Codes
    cout << "\nHuffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Step 5: Encode the input text
    string encodedStr = encode(text, huffmanCode);
    cout << "\nEncoded String:\n" << encodedStr << endl;

    // Step 6: Decode to verify
    string decodedStr = decode(encodedStr, root);
    cout << "\nDecoded String:\n" << decodedStr << endl;

    return 0;
}
