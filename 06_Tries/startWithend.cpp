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

    bool startsWith(string key)
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
        return true;
    }
};
int main(){
    vector<string> words = { "apple" , "app", "mango", "man", "woman"};
    
    Trie trie;
    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    cout<< trie.startsWith("app")<<endl;
    

    return 0;
}