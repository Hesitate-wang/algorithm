#include<iostream>



//P1228 地毯填补问题
using namespace std;
void func(int x_0, int y_0, int k, int x, int y){
    if(k == 1){
        //大小特判
        if(x == x_0 && y == y_0){
            cout << x+1 << y + 1 << 1;
        }else if(x == x_0 && y == y_0 + 1){
            cout << x_0 + 1 << y_0 << 2;
        }else if(x == x_0 + 1 && y == y_0){
            cout << x_0 << y_0 + 1 << 3;
        }else{
            cout << x_0 << y_0 << 4;
        }
        return;
    }
    //todo
}
int main(){
    int k;
    int x, y;
    cin >> k >> x >> y;
    func(0, 0, k, x, y);
}