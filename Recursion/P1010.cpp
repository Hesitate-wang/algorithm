#include<iostream>
#include<string>
#include<vector>

using namespace std;
string func(int n, vector<string> &vec){
    if(!vec[n].empty()){
        return vec[n];
    }
    vector<string> tmp;
    string &ans = vec[n];
    if(n == 2){
        return ans = "2";
    }
    int count = 0;
    while(n > 0){
        if(n & 1){
            if(count == 1){
                //如果2^1, 进行特殊标记
                tmp.push_back("1");
            }else{
                tmp.push_back(func(count, vec));  
            }
            
        }
        n = n >> 1;
        ++count;
    }
    for(int i = tmp.size() - 1; i >= 0; --i){
        if(i != tmp.size() - 1){
            ans.push_back('+');
        }
        ans.push_back('2');
        if(tmp[i] != "1"){
            ans.push_back('(');
            ans.append(tmp[i]);
            ans.push_back(')');
        }
    }
    return ans;
}
//P1010 [NOIP 1998 普及组] 幂次方
int main(){
    int n;
    cin >> n;
    vector<string> vec(n+1);
    vec[0] = "0";
    string ans = func(n, vec);
    cout << ans;
}