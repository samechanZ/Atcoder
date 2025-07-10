#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    set<string> newS;
    rep(i, N) cin >> S[i];
    rep(i, N){
        string si = S[i];
        rep(j, N){
            if (i == j) continue;
            string sj = S[j];
            newS.insert(si+sj);
        }
    }

    cout << newS.size() << endl;

    return 0;
}
