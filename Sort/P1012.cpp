#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool compare(const string &s1, const string &s2){
    //返回true 即排序在前
    //字符串拼接选择
    return s1 + s2 > s2 + s1;
}

int main(){
    int n;
    cin >> n;
    vector<string> vec;
    while(n--){
        string s;
        cin >> s;
        vec.push_back(s);
    }
    //比较时 如果a + b > b + a, 说明a > b；
    sort(vec.begin(), vec.end(), compare);
    for(string &s : vec){
        cout << s;
    }

}