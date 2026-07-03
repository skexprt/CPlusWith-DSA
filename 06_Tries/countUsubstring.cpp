#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children;
    bool endOfWorld;

    Node()
    {
        endOfWorld = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWorld = true;
    }

    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endOfWorld;
    }


    int countNodesHelper(Node* root) {
        if (!root) return 0;
        int count = 0;
        for ( pair<char , Node*> child : root->children) {
            count += countNodesHelper(child.second);
        }
        return count + 1;
    }
    int countNodes() {
        return countNodesHelper(root);
    }
};

int countUniqueSubstr(string str){
    Trie trie;
    // suffix trie bana lo
    for (int i = 0; i < str.size(); i++)
    {
        string suffix = str.substr(i);
        trie.insert(suffix);
    }

    // Count unique substrings (this is a simplified approach; a more efficient method would involve traversing the trie)
    return trie.countNodes();
    
}

int main(){
    string str = "ababa";

    cout << "Number of unique substrings: " << countUniqueSubstr(str) << endl;

    return 0;
}