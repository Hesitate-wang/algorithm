#include<iostream>
#include<string>
using namespace std;

bool compare(const string &s1, const string &s2){
    if(s1.size() == s2.size()){
        return s1 > s2;
    }
    return s1.size() > s2.size();
}
int main(){
    int n;
    cin >> n;
    string cur = "0";
    int ans = 0;
    int order = 1;
    while(n--){
        string num;
        cin >> num;
        if(compare(num, cur)){
            cur = num;
            ans = order;    
        }
        ++order;
    }
    cout << ans << endl << cur; 
}