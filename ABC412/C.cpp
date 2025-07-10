#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int f(vector<ll> S, ll left, ll goal ,ll lifetime){
    lifetime--;
    if (lifetime < 0) return -20000000;
    int max = 0, count = 0;
    vector<ll> biggerS;
    if (left*2 >= goal){
        return 1;
    }
    for (int i = 0; i < S.size(); i++){
        if (left*2 >= S[i] && S[i] > max){
            max = S[i]; 
        } else if (left*2 < S[i] && S[i] < goal){
            biggerS.push_back(S[i]);
        }
    }
    return f(biggerS, max, goal, lifetime) + 1;
}

int main() {
    int T;
    cin >> T;
    vector<int> count(T);
    rep(i, T){
        int N;
        cin >> N;
        vector<ll> S(N);
        rep(i, N) cin >> S[i];
        int max = 0, idx = 0;
        count[i] = f(S, S[0], S[N-1], N) + 1;
    }
    rep(i, T){
        if (count[i] < 0 ) cout << -1 << endl;
        else if (count[i] >= 2) cout << count[i] << endl;
    }


    return 0;
}