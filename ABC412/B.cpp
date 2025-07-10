#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    rep(i, S.size()){
        if (i == 0) continue;
        bool inT = false;
        if ('A' <= S[i]  && S[i] <= 'Z'){
            rep(j, T.size()){
                if(T[j] == S[i-1]) inT = true;
            }
            if (!inT){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}