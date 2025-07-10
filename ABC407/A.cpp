#include <iostream>
#include <climits>
using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int Ans = 0;
    int min = INT_MAX;
    while (true) {
        if (abs(A-(B*Ans)) < min) {
            min = abs(A-(B*Ans));
            Ans++;
            continue;
        } else {
            break;
        }
    }
    cout << Ans-1 << endl;
}