#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;

      Node(int data){
            this-> data = data;
            this-> next = NULL;
      }      
};
class Queue{
    Node* head;
    Node* tail;
    public:
     Queue(){
        head = tail = NULL;
     }

     void enqueue(int data) {
        Node* newNode = new Node(data);
        if (head == NULL){
            head = tail = newNode;
        }else{
            // if the queue is not empty, add the new node at the end
            tail->next = newNode;
            tail = newNode;
        }
     }

     void dequeue(){
        if(head  == NULL){
            cout << "Queue is empty"<< endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == NULL ){
            tail = NULL; // if the queue is now empty
        }
        delete temp; // free the memory of the dequeued node
     }

     int front(){
        if (head == NULL){
            cout << "Queue is empty "<< endl;
            return -1; // or some other error value 
        }
        return head->data; // return the data of the front node
     }

     bool empty(){
        return head == NULL ; // return true if the queue is empty
     }

};
int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
  while (!q.empty()){
    cout << q.front() << " ";
    q.dequeue();
  }
  return 0;
}
