#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Heap {
    vector<int> vec; // to store max heap elements
    
public:
    void push(int val) {

        //step 1: add the new element to the end of the vector
        vec.push_back(val);

        // get the index of the newly added element and its parent
        int index = vec.size() - 1;  // newly added element index
        int parent = (index - 1) / 2; // parent index

        // heapify up
        while (parent >= 0 && vec[parent] < vec[index])  // O(log n)
        {
            swap(vec[parent], vec[index]);
            index = parent;
            parent = (index - 1) / 2;
        }  
    }

    void heapify(int index) {
        if (index >= vec.size())
        {
            return;
        }
        
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // check if left child exists and is greater than current largest
        if (leftChild < vec.size() && vec[leftChild] > vec[largest]) {
            largest = leftChild;
        }

        // check if right child exists and is greater than current largest
        if (rightChild < vec.size() && vec[rightChild] > vec[largest]) {
            largest = rightChild;
        }

        // if largest is not the current index, swap and continue heapifying
        if (largest != index) {
            swap(vec[index], vec[largest]);
            heapify(largest); // recursive call
        }
    }
    void pop() {

        swap(vec[0], vec[vec.size() - 1]); // step 1: swap first and last element
        vec.pop_back(); // step 2: remove last element

        // step 3: heapify down
        heapify(0); //O(log n)
        
    }
    int top() {
        return vec[0];  //hiest element
    }
    bool empty() {
        return vec.size() == 0; // true if heap is empty
    }
    int size() {
        return vec.size(); // number of elements in heap
    }
    void printHeap() {      // for debugging
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
};


// class Student {
//     string name;
//     int marks;
// public:
//      Student(string name, int marks){
//         this->name = name;
//         this->marks = marks;
//      }

//      // Accessors
//      string getName() const { return name; }
//      int getMarks() const { return marks; }

//         // Overload the < operator for priority_queue
//     bool operator < (const Student& obj) const {
//         return this->marks < obj.marks; // min-heap based on marks
//     }   
// };

// int main(){
    // priority_queue<Student> pq; // error: no matching function for call to 'std::priority_queue<Student>::priority_queue()'

    // pq.push(Student("Ankit", 85));
    // pq.push(Student("Boss", 73));
    // pq.push(Student("Charlie", 95));
    // pq.push(Student("Delta", 90));

    // cout << "Students in order of highest marks:" << endl;
    // while (!pq.empty()){
    //     cout << pq.top().getName() << " " << pq.top().getMarks() << endl;
    //     pq.pop();    
    // }

    // return 0;
// }


struct ComparePairs
{
    bool operator()(const pair<string, int>& p1, const pair<string, int>& p2) {
        return p1.second < p2.second; // min-heap based on second element (int)
    }
};


int main(){
    priority_queue<pair<string, int>, vector<pair<string,int>>,ComparePairs> pq; // max-heap based on pair's first element (string)
    pq.push(make_pair("Ankit", 85));
    pq.push(make_pair("Boss", 73));
    pq.push(make_pair("Charlie", 95));
    pq.push(make_pair("Delta", 90));
    
    while (!pq.empty())
    {
              
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop(); 
        

    }
    
    return 0;
}


