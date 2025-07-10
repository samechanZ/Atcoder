#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;

    vector<vector<string>> PC(N, vector<string>());
    string Server = "";
    
    for (int i = 0; i < Q; ++i) {
        int queryIndex;
        cin >> queryIndex;
        if (queryIndex ==1){
            int p;
            cin >> p;
            PC[p-1].clear();
            PC[p-1].push_back(Server);
        } else if (queryIndex == 2) {
            int p;
            cin >> p;
            string s;
            cin >> s;
            PC[p-1].push_back(s);
        } else if (queryIndex == 3) {
            int p;
            cin >> p;
            Server = "";
            for (const string& s : PC[p-1]) {
                Server += s;
            }
        }
    }
    cout << Server << endl;
}