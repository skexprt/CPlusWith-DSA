#include<iostream>
#include<string>
using namespace std;

class Car {
public:
    string name;
    string color;
    int *mileage;

    // Parameterized constructor
    Car(string n, string c) {
        name = n;
        color = c;
        mileage= new int;
        * mileage = 12;
    }

    // Copy constructor (optional, but added for clarity)
    Car(const Car &other) {
        name = other.name;
        color = other.color;
        mileage = new int;
        *mileage = *other.mileage;
    }
};

int main() {
    // Create the first Car object using the parameterized constructor
    Car c1("maruti 800", "white");

    // Create a copy of the first Car object using the copy constructor
    Car c2(c1);

    // Output the copied car's details
    cout << c2.name << endl;
    cout << c2.color << endl;

    return 0;
}