#include <iostream>
#include <string>
#include <vector>
using namespace std;

int Aup[12] = {3,8,10,13,17,20,24,26,28,31,37,39};
int Adown[12] = {39,36,31,29,26,22,19,15,13,11,8,2};
int Bup[5] = {4,7,10,12,15};
int Bdown[5] = {15,11,8,5,3};

vector<vector<int>> timeTable(24);

void timeCalculate(int hour, int minute, int takenTime, int interval, string flag){
  while (hour < 23){
    int arrivalMinute = minute + takenTime;
    int arrivalHour = hour;
    if (arrivalMinute < 60){
      timeTable[arrivalHour-1].push_back(arrivalMinute);
    } else {
      arrivalHour += 1;
      timeTable[arrivalHour-1].push_back((arrivalMinute)%60);
    }
    if (minute + interval < 60){
      minute += interval;
    } else {
      minute = (minute + interval) % 60;
      hour += 1;
    }
    if (interval == 0) break;
    if (flag == "Adown" && hour == 22 && (minute + takenTime*2) >= 60){
      break;
    }
  }
}

int main(){
  string R, S, DIR, HH;
  cin >> R >> S >> DIR >> HH;
  string flag = "";

  int stationNum = stoi(S.substr(1, S.size() - 1));
  if (R == "A"){
    if (DIR == "U"){
      int takenTime = Aup[stationNum - 1];
      if (stationNum <= 7){
        timeCalculate(5, 55, takenTime, 5, flag);
      } else {
        timeCalculate(6, 10, takenTime - Aup[5], 0, flag);
        timeCalculate(6, 0, takenTime, 10, flag);
      }
    } else {
      int takenTime = Adown[stationNum - 1];
      if (stationNum >= 7){
        timeCalculate(5, 52, takenTime, 10, flag);
      } else {
        timeCalculate(6, 06, takenTime - Adown[6], 10, flag);
        timeCalculate(5, 52, takenTime, 10, flag = "Adown");
      }
    }
  }else{
    if (DIR == "U"){
      int takenTime = Bup[stationNum - 1];
      timeCalculate(6, 00, takenTime, 6, flag);
    } else {
      int takenTime = Bdown[stationNum - 1];
      timeCalculate(6, 11, takenTime, 6, flag);
    }
  }
  int hour = stoi(HH.substr(0));
  if (timeTable[hour-1].empty()){
    cout << "No train" << endl;
  }
  for (int i = 0; i < timeTable[hour-1].size(); i++){
    if (i == 0) cout << hour << ": ";
    if (timeTable[hour-1][i] < 10) cout << 0;
    cout << timeTable[hour-1][i] << " ";
  }
  for (int i = 0; i < timeTable[hour-2].size(); i++){
    if (i == 0) cout << hour-1 << ": ";
    if (timeTable[hour-2][i] < 10) cout << 0;
    cout << timeTable[hour-2][i] << " ";
  }
}