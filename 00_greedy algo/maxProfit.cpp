#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class job
{
public:
    int idx;
    int deadline;
    int profit;
    job(int idx, int deadine, int profit)
    {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs)
{
    int n = pairs.size();
    vector<job> jobs;
    for (int i = 0; i < n; i++)
    {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }
    // sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), [](job &a, job &b)
         { return a.profit > b.profit; });
    cout << "selecting job" << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safedeadline = 2;
    for (int i = 1; i < n; i++)
    {
        if (jobs[i].deadline > safedeadline)
        {

            cout << "selecting job" << jobs[i].idx << endl;
                profit += jobs[i].profit;

            safedeadline++; // increase the safedeadline
        }
    }
    cout << "max profit is " << profit << endl;

    return profit;
}
int main()
{
    int n;
    vector<pair<int, int>> jobs(n, make_pair(0, 0));
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

     maxProfit(jobs);

    return 0;
}