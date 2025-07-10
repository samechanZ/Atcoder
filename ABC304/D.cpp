#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int binary_search(const vector<ll> arr, ll target){
    int begin = 0, end = arr.size()-1;
    while(end - begin != 1){
        int mid = (end - begin) / 2;
        if(target > arr[mid]){  
            begin = mid;
        }else{
            end = mid;
        }
    }
    return begin + 1;
}

int main() {
    ll W, H;
    cin >> W >> H;
    int N;
    cin >> N;
    vector<vector<ll>> ichigo(N, vector<ll>(2));
    rep(i, N) cin >> ichigo[i][0] >> ichigo[i][1];
    int A, B;
    cin >> A;
    vector<ll> a(A);
    rep(i, A) cin >> a[i];
    cin >> B;
    vector<ll> b(B);
    rep(i, A) cin >> b[i];

    a = {1, 4, 5, 10, 13, 21, 51, 62, 91};
    int k = 26;
    cout << binary_search(a, k) << endl;

    return 0;
}