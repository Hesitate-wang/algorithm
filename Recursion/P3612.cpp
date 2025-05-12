#include<iostream>


using namespace std;
long long func(long long &target, long long len, long long N){
    if(len >= N && len == target){
        //当前长度重回原始字符串 直接返回
        return N;
    }
    if(N <= len / 2){
        return func(target, len / 2, N);
    }
    //如果带查找的字符在旋转之后的右半边
    long long diff = N - len / 2 - 1;
    if(diff == 0){
        return func(target, len / 2, len / 2);
    }else{
        return func(target, len/2, diff);
    }
}
//P3612 [USACO17JAN] Secret Cow Code S
int main(){
    string s; 
    long long N;
    cin >> s >> N;
    long long len = s.size();
    while(len < N){
        len *= 2;
    }
    long long target = s.size();
    long long index = func(target, len, N);
    cout << s[index-1];
}