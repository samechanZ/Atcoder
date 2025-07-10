#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int Q;
    cin >> Q;
    queue<vector<ll>> A;
    vector<long long int> sums, front(2);
    bool has_front = false;
    rep(i, Q){
        int query;
        cin >> query;
        if (query == 1){
            vector<ll> cx(2);
            cin >> cx[0] >> cx[1];
            A.push(cx);
            if(!has_front){
                front = A.front();
                A.pop();
                has_front = true;
            }
        }else{
            ll k, sum = 0;
            cin >> k;
            int index = 0;
            while(k != 0){
                if(front[0] - k <= 0){
                    sum += front[1]*front[0];
                    k -= front[0];
                    if(!A.empty()){
                        front = A.front();
                        A.pop();
                    }else{
                        has_front = false;
                    }
                }else{
                    sum += front[1]*k;
                    front[0] -= k;
                    k = 0;
                }
                index += 1;
            }
            sums.push_back(sum);
        }
    }
    for (int i = 0; i < sums.size(); i++) cout << sums[i] << endl;
    return 0;
}