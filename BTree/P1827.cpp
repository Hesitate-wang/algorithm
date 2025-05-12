#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int search_s(const string &s, const char &c){
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == c){
            return i;
        }
    }
    return -1;
}
void func(string mid, string pre){
    //从前序获取根节点
    if(pre.empty()){
        return;
    }
    char root = pre[0];
    //找到根节点位置 用于切割左右树
    int index = search_s(mid, root);
    func(mid.substr(0, index), pre.substr(1, index));
    func(mid.substr(index+1), pre.substr(1+index));
    cout << root;
}
int main(){
    string midOrder, preOrder;
    cin >> midOrder >> preOrder;
    func(midOrder, preOrder);
}