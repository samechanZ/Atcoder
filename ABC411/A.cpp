#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;
    int L;
    cin >> L;
    if (S.size() >= L) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }
}