#include<iostream>
#include<algorithm>

using namespace std;


//P1259 黑白棋子的移动
int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < n; ++i){
        s.push_back('o');
    }
    for(int i = 0; i < n; ++i){
        s.push_back('*');
    }
    s.append("--");
    while(n){
        cout << s << endl;
        swap(s[n-1], s[2 * n]);
        swap(s[n], s[2*n+1]);
        cout << s << endl;
        if(n == 4){
            //n=4是特殊情况单独处理
            swap(s[n-1], s[2*n-1]);
            swap(s[n], s[2*n]);
            cout << s << endl;
            swap(s[1], s[2*n-1]);
            swap(s[2], s[2*n]);
            cout << s << endl;
            swap(s[1], s[2*n-2]);
            swap(s[2], s[2*n-1]);
            cout << s << endl;
            swap(s[0], s[2*n-2]);
            swap(s[1], s[2*n-1]);
            cout << s << endl;
            return 0;
        }
        swap(s[n-1], s[2*n-2]);
        swap(s[n], s[2*n-1]);
        --n;
    }
}