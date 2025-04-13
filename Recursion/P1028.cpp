#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long>  vec(n+1);
    vector<long long> prefix(n+1);
    vec[0] = 1;
    prefix[0] = 1;
    for(int i = 1; i <= n; ++i){
        vec[i] = prefix[i / 2];
        prefix[i] = prefix[i-1] + vec[i];
    }
    cout << vec[n];
}