#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;

struct Dot{
    int x, y, z;
    Dot(int x, int y, int z): x(x), y(y), z(z){}
    bool operator<(const Dot& dot) const{
        //需要升序排列 重载小于号
        //最小堆 则是重载大于号
        return this -> z < dot.z; 
    }
};

struct People{
    int year, month, day, id;
    string name;
    People(string name, int year, int month, int day, int id): name(name), year(year), day(day), id(id){}
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

double distance(const Dot &d1, const Dot &d2){
    return sqrt(pow(d1.x - d2.x, 2) + pow(d1.y - d2.y, 2) + pow(d1.z - d2.z, 2));
}
int main(){
    int n;
    cin >> n;
    vector<Dot> trace;
    while(n--){
        double x, y, z;
        cin >> x >> y >> z;
        trace.emplace_back(x, y, z);
    }
    double ans = 0;
    sort(trace.begin(), trace.end());
    for(int i = 1; i < trace.size(); ++i){
        ans += distance(trace[i], trace[i-1]);
    }
    printf("%.3f", ans);
}