#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

const ll INF = 1LL<<60;

bool chmin(ll& a, ll b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}

int main() {
    ll x, y, z;
    cin >> x >> y >> z;
    string S;
    cin >> S;
    vector<vector<ll>> dp(S.size()+1, vector<ll>(2, INF));
    dp[0][0] = 0;
    rep(i, S.size()){
        chmin(dp[i][1], dp[i][0]+z);
        chmin(dp[i][0], dp[i][1]+z);
        if(S[i] == 'a'){
            chmin(dp[i+1][0], dp[i][0] + x);
            chmin(dp[i+1][1], dp[i][1] + y);
        }else{
            chmin(dp[i+1][0], dp[i][0] + y);
            chmin(dp[i+1][1], dp[i][1] + x);
        }
    }

    cout<< min(dp[S.size()][0], dp[S.size()][1]) << endl;
    return 0;
}