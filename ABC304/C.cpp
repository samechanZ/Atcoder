#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int dist(const vector<int> cord1, const vector<int> cord2){
    int dist = (cord1[0] - cord2[0])*(cord1[0] - cord2[0]) 
    + (cord1[1] - cord2[1])*(cord1[1] - cord2[1]);
    return dist;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<bool> infected(N, false);
    vector<vector<int>> cord(N, vector<int>(2));
    rep(i, N) cin >> cord[i][0] >> cord[i][1];

    queue<int> que;
    que.push(0);
    infected[0] = true;
    while(!que.empty()){
        int person = que.front();
        que.pop();
        rep(i, N){
            if(person == i) continue;
            if(dist(cord[person], cord[i]) <= D*D && !infected[i]){
                infected[i] = true;
                que.push(i);
            }
        }
    }
    rep(i, infected.size()) {
        if(infected[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}