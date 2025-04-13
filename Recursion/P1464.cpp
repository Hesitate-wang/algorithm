#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
using ansType = vector<vector<vector<long long>>>;
long long func(long long a, long long b, long long c, ansType &vec){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    if(a > 20 || b > 20 || c > 20){
        return func(20, 20, 20, vec);
    }
    long long &ans = vec[a][b][c];
    if(ans != -1){
        return ans;
    }
    if(a < b && b < c){
        return ans = func(a, b, c - 1, vec) + func(a, b - 1, c - 1, vec) - func(a, b - 1, c, vec);
    }
    return ans = func(a-1, b, c, vec) + func(a-1, b-1, c, vec) + func(a-1, b, c-1, vec) - func(a-1, b-1, c-1, vec);
}
int main(){
    long long a, b, c;
    vector<vector<vector<long long>>> vec(21, vector<vector<long long>>(21, vector<long long>(21, -1)));
    while(1){
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1){
            break;
        }
        long long ans = func(a, b, c, vec);
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, ans);
    }
}