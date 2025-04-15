#include<iostream>
#include<vector>
using namespace std;


int func(int m, int cur, vector<int> &vec, vector<vector<int>> &record){
    if(m == 0){
        return 1;
    }
    if(m < 0 || cur == vec.size()){
        return 0;
    }
    int &ans = record[m][cur];
    if(ans != -1){
        return ans;
    }
    return ans = func(m, cur+1, vec, record) + func(m - vec[cur], cur+1, vec, record);
}
int main(){
    //点菜算法 无放回的递归算法
    int n, m;
    cin >> n >> m;
    vector<int> vec;
    while(n--){
        int x;
        cin >> x;
        vec.push_back(x);
    }
    vector<vector<int>> record(m+1, vector<int>(vec.size(), -1));
    cout << func(m, 0, vec, record);
}