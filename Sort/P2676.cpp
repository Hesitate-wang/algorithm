#include<iostream>
#include<queue>
using namespace std;


int main(){
    int N;
    long long B;
    cin >> N >> B;
    priority_queue<long long> ue;
    while(N--){
        int x;
        cin >> x;
        ue.push(x);
    }
    int ans = 0;
    while(B > 0 && !ue.empty()){
        B -= ue.top();
        ue.pop();
        ++ans;
    }
    cout << ans;
}