#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), oriA(N);
    rep(i, N){
        cin >> A[i];
        oriA[i] = A[i];
    }
    sort(A.begin(), A.end());
    int dif = -1;
    vector<int> idx;
    rep(i, N){
        if (A[i] != oriA[i]){
            idx.push_back(i);
            dif++;
        }
    }
    vector<bool> swaped(idx.size(), false);
    for(int i = 0; i < idx.size(); i++){
        if (swaped[i] || i == idx.size()-1) continue; 
        for (int j = i+1; j < idx.size(); j++){
            if(A[idx[i]] == oriA[idx[j]] && A[idx[j]] == oriA[idx[i]] && A[idx[i]] != A[idx[j]] && !swaped[j]){
                swaped[j] = true;
                dif--;
                break;
            }
        }
    }
    cout << dif << endl;

    return 0;
}