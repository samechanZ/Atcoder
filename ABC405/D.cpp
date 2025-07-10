#include <iostream>
#include <vector>
#include <string>

using namespace std;


void findExit(int H, int W, vector<string>& S, int i, int j){
    if (i < 0 || i >= H || j < 0 || j >= W) return;
    if (S[i][j] == 'E' || S[i][j] == '<' || S[i][j] == '>' || S[i][j] == '^' || S[i][j] == 'v'){
        if (i-1 >= 0 && S[i-1][j] == '.') {
            S[i-1][j] = 'v';
            findExit(H, W, S, i-1, j);
        }
        else if (i+1 < H && S[i+1][j] == '.') {
            S[i+1][j] = '^';
            findExit(H, W, S, i+1, j);
        }
        else if (j-1 >= 0 && S[i][j-1] == '.') {
            S[i][j-1] = '>';
            findExit(H, W, S, i, j-1);
        } 
        else if (j+1 < W && S[i][j+1] == '.') {
            S[i][j+1] = '<';
            findExit(H, W, S, i, j+1);
        }
    } else return;
    return;
}

int main(){
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    vector<vector<int>> Exit;
    for (int i = 0; i < H; ++i){
        cin >> S[i];
        for (int j = 0; j < W; ++j){
            if (S[i][j] == 'E'){
                Exit.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < Exit.size(); ++i){
        int x = Exit[i][0];
        int y = Exit[i][1];
        cout << x << " " << y << endl;
        findExit(H, W, S, x, y);
    }

    for (int i = 0; i < H; ++i){
        cout << S[i] << endl;
    }
}