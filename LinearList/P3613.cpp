#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    vector<unordered_map<int, long long>> store(n+1);
    int op, i, j;
    long long k;
    while(q--){
        cin >> op;
        if(op==1){
            cin >> i >> j >> k;
            store[i][j] = k;
        }else{
            cin >> i >> j;
            cout << store[i][j] << endl;
        }
    }
}