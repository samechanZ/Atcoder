#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <bitset>
using namespace std;

int main() {
    string S;
    cin >> S;
    long long N;
    cin >> N;

    bitset<60> bitN(N);
    string bitNString = bitN.to_string();
    int maxBitIdx;
    for (int i = 0; i < 60; i++) {
        if(bitN.test(59-i)){
            maxBitIdx = i;
            break;
        }
    }
    if (60 - maxBitIdx >= S.size()) bitNString = bitNString.substr(maxBitIdx, bitNString.size() - maxBitIdx);
    else bitNString = bitNString.substr(60 - S.size(), S.size());

    string tmp = S;
    for (int i = 0; i < S.size(); i++){
        if (tmp[i] == '?') tmp[i] = '0';
    }
    long long sum = 0, k_tmp = 1;
    for (int i = 0; i < S.size(); i++){
        if (tmp[S.size() - i - 1] == '1') sum += k_tmp;
        k_tmp *= 2;
    }
    if (sum > N) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < S.size(); i++){
        if (S.size() < bitNString.size()){
            for (int i = 0; i < S.size(); i++){
                if (S[i] == '?') S[i] = '1';
            }
            break;
        }
        if (S[i] == '?'){
            S[i] = '1';
            string subS = S;
            bool SisSmaller = true;
            for (int j = i+1; j < S.size(); j++){
                if (S[j] == '?') subS[j] = '0';
                else subS[j] = S[j];
            }
            for (int j = 0; j < S.size(); j++){
                if (int(subS[j]) < int(bitNString[j])){
                    break;
                } 
                if (int(subS[j]) > int(bitNString[j])){
                    SisSmaller = false;
                    break;
                }
            }
            if (!SisSmaller) S[i] = '0';
        }
    }
    
    long long max = 0, k = 1;
    for (int i = 0; i < S.size(); i++){
        if (S[S.size() - i - 1] == '1') max += k;
        k*=2;
    }
    cout << max << endl;
    return 0;
}