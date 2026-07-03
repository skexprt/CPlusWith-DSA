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
};

string logestWordAllprifix(vector<string> &words)  //complexity O(n*m^2) where n is the number of words and m is the length of longest word
{
    Trie trie;

    for (int i = 0; i < words.size(); i++)
    {
        trie.insert(words[i]);
    }

    string longest = "";

    for (int i = 0; i < words.size(); i++)
    {
        string word = words[i];
        bool allPrefix = true;

        for (int j = 1; j <= word.size(); j++)
        {
            if (!trie.search(word.substr(0, j)))
            {
                allPrefix = false;
                break;
            }
        }

        if (allPrefix)
        {
            if (word.size() > longest.size())
            {
                longest = word;
            }
            else if (word.size() == longest.size() && word < longest)
            {
                longest = word;
            }
        }
    }
    return longest;
}

int main()
{
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout << logestWordAllprifix(words) << endl;
    return 0;
}