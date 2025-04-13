#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

// 上楼梯 
//数据量太大 必须高精度加法
string add(const string &s1, const string &s2){
    int more = 0;
    int i = s1.size()-1, j = s2.size()-1;
    string ans;
    while(i >= 0 && j >= 0){
        int sum = s1[i--] + s2[j--] - '0' * 2 + more;
        more = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    while(i >= 0){
        int sum = s1[i--] - '0' + more;
        more = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    while(j >= 0){
        int sum = s2[j--] - '0' + more;
        more = sum / 10;
        ans.push_back(sum % 10 + '0');
    }
    if(more){
        ans.push_back(more + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<string> vec(N+1);
    vec[0] = "1";
    vec[1] = "1";
    for(int i = 2; i <= N; ++i){
        vec[i] = add(vec[i-1], vec[i-2]);
    }
    cout << vec[N];
}