#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }

    ~Node(){
        cout<<"~Node :"<<data<<endl;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        
    }

};

class list
{
    Node *head;
    Node *tail;

public:
    list()
    {
        head = NULL;
        tail = NULL;
    }

    ~list(){
        cout<<"~List\n";
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
        
    }

    void push_front(int val) // Fixed function name
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode; 
        }else{
            tail->next = newNode;
            tail = newNode;
        }
        

    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insert(int val, int pos){
        Node* newNode = new Node(val);

        Node* temp =head;
        for (int i = 0; i < pos-1; i++)
        {
            temp = temp->next;
        }
        // temp is now at pos-1 i.e. prev/left

        newNode->next = temp->next;
        temp->next = newNode; 
        
    }
};

int main()
{
    list ll; // Fixed object initialization
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);

    ll.printList(); // Display the linked list

    return 0;
}
