#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
// int maxActivities(vector<int> start, vector<int> end)
// {
//     // sort activities based on end time
//     //  select A0 on time
//     cout << "secting A0\n";
//     int count = 1;
//     int currEnd = end[0];

//     for (int i = 1; i <= start.size(); i++)
//     {
//         if (start[i] >= currEnd)
//         {
//             cout << "secting A"<< i << "\n";
//             count++;
//             currEnd = end[i];
//         }
//     }
//     return count;
// }
// int main()
// {
//     vector<int> start = {1, 3, 0, 5, 8, 5};
//     vector<int> end = {2, 4, 6, 7, 9, 9};
//     cout << "Maximum number of activities that can be performed: " << maxActivities(start, end) << endl;

//     return 0;
// }


/* <-- pair in C++ --> */

 bool compare(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second; // sort based on end time asending oder
    // return p1.second > p2.second; // sort based on end time disending oder


    // return p1.first < p2.first; // sort based on end time asending oder
    // return p1.first > p2.first; // sort based on end time disending oder

}
int main(){
    vector<int> start = {0 , 1, 2 };
    vector<int> end = {9, 4, 6 };

    vector<pair<int, int>> activities(3 , make_pair(0,0));

    activities[0] = make_pair(0,9);
    activities[1] = make_pair(1,4);
    activities[2] = make_pair(2,6);

    // sort activities based on end time
    for (int i = 0; i < activities.size(); i++)
    {
        cout << "A" << i << " : (" << activities[i].first << "," << activities[i].second << ")\n"<<endl;
    }
    sort(activities.begin(), activities.end(),compare);

    cout<< "------sorted activities-------\n";
    for (int i = 0; i < activities.size(); i++)
    {
        cout << "A" << i << " : (" << activities[i].first << "," << activities[i].second << ")\n"<<endl;
    }

    return 0;
}
