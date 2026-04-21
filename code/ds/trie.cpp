// class for a node of the trie
class TrieNode {
public:
    bool endofWord;
    TrieNode* children[26];

    // Constructore to initialize a trie node
    TrieNode()
    {
        endofWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

// class for the Trie implementation
class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    // Function to insert a word into the trie
    void insert(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->endofWord = true;
    }

    // Function to search a word in the trie
    bool search(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return node->endofWord;
    }

    // Function to check if there is any word in the trie
    // that starts with the given prefix
    bool startsWith(string prefix)
    {
        TrieNode* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                return false;
            }
            node = node->children[index];
        }
        return true;
    }

    // Function to delete a word from the trie
    void deleteWord(string word)
    {
        TrieNode* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                return;
            }
            node = node->children[index];
        }
        if (node->endofWord == true) {
            node->endofWord = false;
        }
    }

    // Function to print the trie
    void print(TrieNode* node, string prefix) const
    {
        if (node->endofWord) {
            cout << prefix << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                print(node->children[i],
                      prefix + char('a' + i));
            }
        }
    }

    // Function to start printing from the root
    void print() const { print(root, ""); }
};