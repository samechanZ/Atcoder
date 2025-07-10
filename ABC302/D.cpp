#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    while(A.size() != 0 && B.size() != 0){
        ll Aend = A.size()-1, Bend = B.size()-1;
        if(A[Aend] >= B[Bend]){
            if(A[Aend] - B[Bend] <= D){
                cout << A[Aend] + B[Bend] << endl;
                return 0;
            } else {
                A.pop_back();
            }
        }else{
            if(A[Aend] - B[Bend] >= -D){
                cout << A[Aend] + B[Bend] << endl;
                return 0;
            } else {
                B.pop_back();
            }
        }
    }
    cout << -1 << endl;

    return 0;
}