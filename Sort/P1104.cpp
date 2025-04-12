#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct People{
    int year, month, day, id;
    string name;
    People(string name, int year, int month, int day, int id): name(name), year(year),month(month), day(day), id(id){}
    bool operator>(const People& people)const{
        if(this -> year == people.year){
            if(this -> month == people.month){
                if(this -> day == people.day){
                    return this -> id > people.id;
                }
                return this -> day < people.day;
            }
            return this -> month < people.month;
        }
        return this->year < people.year;
    }
};


int main(){
    int n;
    cin >> n;
    vector<People> vec;
    int order = 1;
    while(n--){
        string name;
        int year, month, day;
        cin >> name >> year >> month >> day;
        vec.emplace_back(name, year, month, day, order++);
    }
    sort(vec.begin(), vec.end(), greater<People>());
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i].name;
        if(i != vec.size()-1){
            cout << endl;
        }
    }
}