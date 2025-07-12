#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

ll maxketa(int keta){
    ll result = 1;
    rep(i, keta){
        result *= 10;
    }
    return result;
}

bool convertToAisSym(int A,ll N) {
    string result = "";
    while (N >= A){
        result += to_string(N % A);
        N /= A;
    }
    result += to_string(N);
    string temp = result;
    reverse(result.begin(), result.end());
    return result == temp;
}

int main() {
    int A;
    ll N;
    cin >> A >> N;
    vector<ll> kaibun;
    rep (i, 9){
        kaibun.push_back(i+1);
    }
    int keta = 1;
    while(keta < size(to_string(N))+1){
        if (keta == 13) break;
        if (keta % 2 == 0){
            string front = "";
            for (int i = maxketa((keta/2) - 1); i < maxketa(keta/2); i++){
                front = to_string(i);
                kaibun.push_back(stoll(front + string(front.rbegin(), front.rend())));
            }
        } else {
            string front = "";
            for (int i = maxketa((keta/2) - 1); i < maxketa((keta/2)); i++){
                front = to_string(i);
                rep(j, 10){
                    kaibun.push_back(stoll(front + to_string(j) + string(front.rbegin(), front.rend())));
                }
            }
        }
        keta += 1;
    }

    ll result = 0;
    for (ll i : kaibun) {
        if (i > N) break;
        if (convertToAisSym(A, i)) {
            result += i;
        }
    }

    cout << result << endl;

    return 0;
}
