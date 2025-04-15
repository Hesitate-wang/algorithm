#include<iostream>
#include<vector>




using namespace std;


//覆盖墙壁
int main(){
    int n;
    cin >> n;
    vector<int> F(n+1); //F(n) 表示从1列到n列都是空的 多少种覆盖方法
    vector<int> G(n+1); //G(n) 表示1到n-1列全是空的 但是n列其中一个已经被覆盖
    //G(n) = F(n-2) + G(n-1)
    //F(n) = F(n-1) + F(n-2) + 2*G(n-1) = F(n-1) + F(n-2) + 2*F(n-3) + 2*G(n-2)
    F[0] = 1;
    F[1] = 1;
    if(n == 1){
        cout << F[1];
        return 0;
    }
    F[2] = 2;
    G[0] = 0;
    G[1] = 0;
    G[2] = F[0] + G[1];
    int mod = 10000;
    for(int i = 3; i <= n; ++i){
        F[i] = (F[i-1] + F[i-2] + 2 * F[i-3] + 2 * G[i-2]) % mod;
        G[i] = (F[i-2] + G[i-1]) % mod; 
    }
    cout << F[n];

}