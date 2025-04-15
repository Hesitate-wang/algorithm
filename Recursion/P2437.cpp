#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
string add(const string &s1, const string &s2){
    int carry = 0;
    int i = s1.size() - 1, j = s2.size()-1;
    string ans = "";
    while(i >= 0 || j >= 0){
        int tmp = carry;
        if(i >= 0){
            tmp += s1[i--] - '0';
        }
        if(j >= 0){
            tmp += s2[j--] - '0';
        }
        ans.push_back(tmp % 10 + '0');
        carry = tmp / 10;
    }
    if(carry){
        ans.push_back(carry + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;

}
//P2437 蜜蜂路线
int main(){
    int m, n;
    cin >> m >> n;
    vector<string> vec(n+1);
    if(m == n - 1){
        cout << "1";
        return 0;
    }
    vec[n] = "1";
    vec[n-1] = "1";
    for(int i = n - 2; i >= 1; --i){
        vec[i] = add(vec[i+1], vec[i+2]);
        if(i == m){
            cout << vec[i];
            return 0;
        }
    }
}