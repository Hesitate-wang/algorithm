#include<iostream>
#include<vector>
using namespace std;

int func(long long st, long long n, vector<vector<long long>> &vec){
    if(n == 0){
        //如果栈为空且队列中无剩余元素 结束递归
        return 1;
    }
    long long &ans = vec[st][n];
    if(ans != -1){
        return ans;
    }
    ans = 0;
    if(st > 0){
        //栈非空
        ans += func(st-1, n, vec);
    }
    if(n > 0){
        //队列非空 压入栈
        ans += func(st+1, n-1, vec);
    }
    
    return ans;
}
int main(){
    long long n;
    cin >> n;
    vector<vector<long long>> vec(n+1, vector<long long>(n+1, -1));
    long long ans = 0;
    ans = func(0, n, vec);
    cout << ans;
}