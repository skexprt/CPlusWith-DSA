#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Row{
public:
    int idx;
    int soldier;

    Row(int idx, int soldier){
        this->idx = idx;
        this->soldier = soldier;
    }

    bool operator<(const Row &obj) const{
        if(this->soldier == obj.soldier){
            return this->idx > obj.idx;
        }
        return this->soldier > obj.soldier;
    }
};

void weakestSoldier(vector<vector<int>> &matrix, int k) {

    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++){
        int count = 0;
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++){
                count++;
        }
        rows.push_back(Row(i, count));
    }
    priority_queue<Row> pq(rows.begin(), rows.end());

    for(int i=0; i<k; i++){
        Row r = pq.top();
        pq.pop();
        cout<<r.idx<<" ";
    }
}


int main(){

    vector<vector<int>> matrix = {
        {1, 0, 0,0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };

    weakestSoldier(matrix, 3);
    return 0;
}