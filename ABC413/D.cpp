#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<bool> ans;
    rep(j, T){
        int N;
        cin >> N;
        vector<ll> A(N);
        bool prePlus;
        rep(i, N) {
            int k;
            cin >> k;
            if (k < 0 && prePlus) A[i] = -1 * k;
            else A[i] = k;
        }
        if (){
            ans.push_back(false);
            continue;
        }
        if (N == 2){
            ans.push_back(true);
            continue;
        }
        sort(A.begin(), A.end());
        for (int i = 1; i < N; i++){
            if(i+2 == N){
                ans.push_back(true);
                break;
            }
            if(A[i+2]*A[0] == A[i+1]*A[1]){
                continue;
            }else{
                ans.push_back(false);
                break;
            }
        }
        if(ans[j]){
            long double dA = static_cast<long double>(A[1])/static_cast<long double>(A[0]);
            if(dA != static_cast<long double>(A[2])/static_cast<long double>(A[1])) ans[j] = false;
        }
    }
    rep(i, ans.size()){
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}