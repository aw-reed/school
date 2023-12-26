#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<unordered_map>

using namespace std;

class Node {
public:
    char symbol;
    int freq;
    Node* left;
    Node* right;

    Node(char sym, int f) : symbol(sym), freq(f), left(nullptr), right(nullptr) {}
};

struct compareNodes {
    bool operator()(Node* a, Node* b){
        return a->freq > b->freq;
    }
};

Node* buildHuffmanTree(const vector<int>& frequencies){
    priority_queue<Node*, vector<Node*>, compareNodes> pq;

    for(char c = 'A'; c <= 'F'; c++){
        if (frequencies[c - 'A'] > 0){
            pq.push(new Node(c, frequencies[c - 'A']));
        }
    }
    while (pq.size() > 1){
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

void assignHuffmanCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes){
    if (!root){
        return;
    }
    if (root->symbol != '\0'){
        huffmanCodes[root->symbol] = code;
    }
    assignHuffmanCodes(root->left, code + "0", huffmanCodes);
    assignHuffmanCodes(root->right, code + "1", huffmanCodes);
}

int main(){
    vector<int> frequencies(6);
    char symbols[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    for (int i = 0; i < 6; i++){
        cin >> frequencies[i];
    }
    Node* root = buildHuffmanTree(frequencies);

    unordered_map<char, string> huffmanCodes;
    assignHuffmanCodes(root, "", huffmanCodes);

    for (char symbol : symbols){
        cout << symbol << ":" << huffmanCodes[symbol] << endl;
    }
    return 0;
}
