#include<iostream>


using namespace std;

struct Node{
    //数节点
    int val;
    Node *parent;
    Node *left;
    Node *right;
    Node() = default;
    Node(int val): val(val), parent(nullptr), left(nullptr), right(nullptr){};
};

struct Tree{
    int height;
    Node *root;
    Tree(): height(0), root(nullptr){};
    
};
//普通二叉树（简化版）
int main(){

}