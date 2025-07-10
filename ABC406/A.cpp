#include <iostream>
using namespace std;

int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A > C || (A == C && B > D)){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}