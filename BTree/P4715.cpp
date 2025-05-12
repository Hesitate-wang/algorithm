#include<deque>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    deque<pair<int, int>> ue;
    int score;
    int i = 0;
    while(n--){
        cin >> score;
        ue.emplace_back(i++, score);
    }
    while(ue.size() > 2){
        auto p1 = ue.front(); ue.pop_front();
        auto p2 = ue.front(); ue.pop_front();
        if(p1.second > p2.second){
            ue.push_back(p1);
        }else{
            ue.push_back(p2);
        }
    }
    if(ue.front().second < ue.back().second){
        cout << ue.front().first;
    }else{
        cout << ue.back().first;
    }
    return 0;
}