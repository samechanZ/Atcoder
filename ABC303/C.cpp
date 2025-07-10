#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

void death(int H){
    if (H < 0){
        cout << "No" << endl;
        exit(0);
    }
}

int main() {
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    vector<set<int>> heal(4e5+1);

    rep(i, M){
        int x, y;
        cin >> x >> y;
        heal[x+2e5].insert(y);
    }

    int x = 0, y = 0;
    rep(i, N){
        if(S[i] == 'R'){
            x++;
            H--;
            death(H);
            if(heal[x+2e5].find(y) != heal[x+2e5].end() && H < K){
                heal[x+2e5].erase(y);
                H = K;
            }
        }else if (S[i] == 'L'){
            x--;
            H--;
            death(H);
            if(heal[x+2e5].find(y) != heal[x+2e5].end() && H < K){
                heal[x+2e5].erase(y);
                H = K;
            }
        }else if (S[i] == 'U'){
            y++;
            H--;
            death(H);
            if(heal[x+2e5].find(y) != heal[x+2e5].end() && H < K){
                heal[x+2e5].erase(y);
                H = K;
            }
        }else if (S[i] == 'D'){
            y--;
            H--;
            death(H);
            if(heal[x+2e5].find(y) != heal[x+2e5].end() && H < K){
                heal[x+2e5].erase(y);
                H = K;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}