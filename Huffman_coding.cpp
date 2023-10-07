#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Define a structure for nodes in the Huffman tree
struct HuffmanNode {
    char data;            // Character data (for leaf nodes)
    int frequency;        // Frequency of the character
    HuffmanNode* left;   // Pointer to the left child
    HuffmanNode* right;  // Pointer to the right child

    HuffmanNode(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Custom comparison operator for the priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) const {
        return lhs->frequency > rhs->frequency;
    }
};

// Function to build the Huffman tree
HuffmanNode* buildHuffmanTree(map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> pq;

    // Create leaf nodes for each character and add them to the priority queue
    for (const auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman tree by merging nodes until only one node remains
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top();
        pq.pop();
        HuffmanNode* right = pq.top();
        pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    return pq.top();
}

// Function to generate Huffman codes
void generateHuffmanCodes(HuffmanNode* root, string code, map<char, string>& huffmanCodes) {
    if (!root) {
        return;
    }

    // If the node is a leaf node, store its code in the map
    if (root->data != '\0') {
        huffmanCodes[root->data] = code;
    }

    // Traverse the left subtree with code '0'
    generateHuffmanCodes(root->left, code + "0", huffmanCodes);

    // Traverse the right subtree with code '1'
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main() {
    // If frequency is same, order should be taken in alphabetical order
    string input = "ABBCDBCCDAABBEEEBEAB";
    // string input = "BCCABBDDAECCBBAEDDCC";
    map<char, int> frequencies;

    // Calculate character frequencies
    for (char c : input) {
        frequencies[c]++;
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate Huffman codes
    map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Clean up memory
    delete root;

    return 0;
}
