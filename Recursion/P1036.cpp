#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool isPrime(int x){
    if(x == 1){
        return false;
    }
    for(int i = 2; i <= sqrt(x); ++i){
        if(x % i == 0){
            return false;
        }
    }
    return true;
}
int func(vector<int> &vec, int k, int cur, int sum){
    if(k == 0 && isPrime(sum)){
        return 1;
    }
    if(cur == vec.size()){
        return 0;
    }
    return func(vec, k, cur + 1, sum) + func(vec, k-1, cur + 1, sum + vec[cur]);
}
//[NOIP 2002 普及组] 选数
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    while(n--){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    int ans = func(vec, k, 0, 0);
    cout << ans;
}