#include<iostream>
#include<vector>
#include<random>
using namespace std;

random_device rd;
mt19937 gen(rd());
struct Player{
    int score;
    int id;
    Player(int score, int id): score(score), id(id){}
    bool operator<(const Player& player) const{
        if(this -> score == player.score){
            return this -> id > player.id;
        }
        return this -> score < player.score;
    }

    bool operator>(const Player &player) const{
        if(this -> score == player.score){
            return this -> id < player.id;
        }
        return this->score > player.score;
    }
    void str(){
        cout << this -> id << ' '<< this -> score;
    }
};

int partition(vector<Player> &vec, int l, int r){
    int mid = (l + r) >> 1;
    Player pivot = vec[mid];
    std::swap(vec[mid], vec[l]);
    while(l < r){
        while(l < r && vec[r] < pivot){
            --r;
        }
        std::swap(vec[l], vec[r]);
        while(l < r && vec[l] > pivot){
            ++l;
        }
        std::swap(vec[l], vec[r]);
    }
    return l;
}
void quickSort(vector<Player> &vec, int l, int r){
    if(l >= r){
        return;
    }
    int index = partition(vec, l, r);
    quickSort(vec, l, index - 1);
    quickSort(vec, index+1, r);
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<Player> vec;
    for(int i = 0; i < n; ++i){
        int score, id;
        cin >> id >> score;
        vec.emplace_back(score, id);
    }
    quickSort(vec, 0, n-1);
    m = m * 1.5;
    int i = 0;
    vector<Player> ans;
    while(i < m){
        ans.push_back(vec[i++]);
    }
    while(i < n && vec[i].score == vec[i-1].score){
        ans.push_back(vec[i++]);
    }
    cout << ans.back().score << ' ' << ans.size() << endl;
    for(int i = 0; i < ans.size(); ++i){
        ans[i].str();
        if(i != ans.size()-1){
            cout << endl;
        }
    }
}