#include <iostream>
#include <array>
using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;
    Node(string k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class HashTable
{
    int totSize;
    int currSize;
    Node **table;

    int hashFunction(string key)
    {
        int idx = 0;
        for (int i = 0; i < key.size(); i++)
        {
            idx += (key[i] * key[i]) % totSize;
        }

        return idx % totSize;
    }

    void rehash()
    { // O(n)
        Node **oldTable = table;
        int odlSize = totSize;

        totSize = 2 * totSize;

        currSize = 0;

        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }

        // copy old value
        for (int i = 0; i < odlSize; i++)
        {
            Node *temp = oldTable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->value);
                temp = temp->next;
            }

            // delete old table
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }

        delete oldTable;
    }

public:
    HashTable(int size = 5)
    {
        totSize = size;
        currSize = 0;
        table = new Node *[totSize];
        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }
    }

    

    void insert(string key, int value)
    { // O(1)
        int idx = hashFunction(key);
        Node *newNode = new Node(key, value);
        if (table[idx] == NULL)
        {
            table[idx] = newNode;
        }
        else
        {
            Node *temp = table[idx];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        currSize++;

        double lambda = currSize / (double)totSize;
        if (lambda > 1)
        {
            rehash(); // O(n) -->Worst case me O(n) hoti hai
        }
    }

    bool exists(string key)
    {
        int idx = hashFunction(key);
        Node *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }

            return false;
        }
    }

    void remove(string key)
    {
        int idx = hashFunction(key);
        Node *temp = table[idx];
        Node *prev = NULL;
        while (temp != NULL && temp->key != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return; // Key not found
        if (prev == NULL)
        {
            table[idx] = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }
        delete temp;
        currSize--;
    }

    int search(string key)
    {
        int idx = hashFunction(key);
        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return -1; // Key not found
    }

    void print(){
        for(int i=0; i<= totSize; i++){
            cout<<"idx"<<i<<"->";
            Node* temp = table[i];
            while (temp != NULL)
            {
                cout<<"(" << temp->key << "," << temp->value << ") ->";
                temp = temp->next;
            }
            
        }
    }
};
int main()
{

    HashTable ht;

    ht.insert("india", 150);
    ht.insert("china", 160);
    ht.insert("nepal", 10);
    ht.insert("UK", 60);
    ht.insert("US", 150);
    ht.insert("south", 80);
    ht.insert("asteliya", 100);

    if (ht.exists("india"))
    {
        cout << "India population :" << ht.search("india") << endl;
    }

    return 0;
}