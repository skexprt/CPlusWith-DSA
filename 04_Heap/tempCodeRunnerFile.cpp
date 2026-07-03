// lass Student {
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