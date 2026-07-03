#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<vector>
using namespace std;

void printItenanry(unordered_map<string , string> &tickets){

    // find the starting point
    unordered_set<string> to;

    // insert all the destination cities in the set
    for(pair<string , string> ticket : tickets)  //O(n) 
        to.insert(ticket.second);

    // find the starting point
    string start = "";

    // starting point will be the one which is not present in 'to' set
    for(pair<string , string> ticket : tickets){   // O(n)
        if(to.find(ticket.first) == to.end()){
            start = ticket.first;
            break;
        }
    }

    // print the itinerary
    cout << start << " -> ";
    while(tickets.find(start) != tickets.end()){
        cout << tickets[start] << " -> ";
        start = tickets[start];
    }
    cout << "END" << endl;
}

int main(){

    unordered_map<string , string> tickets;

    tickets["Chennai"] = "Bengaluru" ;
    tickets["Mumbai"] = "Delhi" ;
    tickets["Goa"] = "Chennai" ;
    tickets["Delhi"] = "Goa" ;


    printItenanry(tickets);


    return 0;
}
