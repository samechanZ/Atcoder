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
    int count = 0;
    rep(i, N){
        int A, B;
        cin >> A >> B;
        if (A < B) count++;
    } 
    cout << count << endl;
}