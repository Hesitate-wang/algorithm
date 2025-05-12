#include<iostream>
#include<unordered_map>
using namespace std;

struct Node{
    int order;
    Node *prev;
    Node *next;
    Node() = default;
    Node(int order): order(order){}
};

struct LinkList{
    Node *head;
    Node *tail;
    unordered_map<int, Node*> map;
    LinkList() = default;
    LinkList(int init){
        head = new Node();
        tail = new Node();
        Node *tmp = new Node(init);
        head -> next = tmp;
        tmp -> prev = head;

        tmp -> next = tail;
        tail -> prev = tmp;
        map[init] = tmp;
    }
    void insert(int order, int k, int p){
        if(p){
            insertR(order, k);
        }else{
            insertL(order, k);
        }
    }
    void insertR(int order, int k){
        Node *target = map[k];
        Node *tmp = new Node(order);
        tmp->next = target->next;
        target->next -> prev = tmp;
        target -> next = tmp;
        tmp -> prev = target;
        map[order] = tmp;
    }
    void insertL(int order, int k){
        Node *target = map[k];
        Node *tmp = new Node(order);
        target -> prev -> next = tmp;
        tmp -> prev = target -> prev;
        tmp -> next = target;
        target -> prev = tmp;
        tmp -> next = target;
        map[order] = tmp;
    }
    void remove(int x){
        if(map.find(x) == map.end()){
            return;
        }
        Node *target = map[x];
        target -> prev -> next = target -> next;
        target -> next -> prev = target -> prev;
        map.erase(x);
        delete target;
    }
    void str(){
        Node *it = head -> next;
        while(it != tail){
            cout << it -> order << ' ';
            it = it -> next;
        }
    }
};

int main(){
    int N;
    cin >> N;
    int cur = 2;
    LinkList list(1);
    while(--N){
        int k, p;
        cin >> k >> p;
        list.insert(cur++, k, p);
    }
    int m;
    cin >> m;
    while(m--){
        int x;
        cin >> x;
        list.remove(x);
    }
    list.str();
}