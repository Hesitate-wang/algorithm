#include<iostream>
#include<deque>
struct Node{
    int order;
    Node(int x): order(x) {}
};
using namespace std;


int main(){
    int n, m;
    cin >> n >> m;
    deque<Node> ue;
    for(int i = 1; i <= n; ++i){
        ue.emplace_back(i);
    }
    int count = 1;
    auto it = ue.begin();
    while(!ue.empty()){
        if(count == m){
            cout << (it -> order) << ' ';
            it = ue.erase(it);
            count = 1;
        }else{
            ++count;
        }
        ++it;
        if(it == ue.end() && !ue.empty()){
            it = ue.begin();
        }
    }
}