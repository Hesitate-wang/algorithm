#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;
struct Student{
    int id;
    int chinese;
    int sum;
    Student(int id, int chinese, int sum):id(id), chinese(chinese), sum(sum){}
    bool operator>(const Student&ope) const{
        //最小堆 自定义比较大于号
        if(this->sum == ope.sum){
            if(this->chinese==ope.chinese){
                return this->id < ope.id;
            }
            return this->chinese > ope.chinese;
        }
        return this->sum > ope.sum;
    }
};

int main(){
    int n;
    cin >> n;
    vector<Student> students;
    int order = 1;
    while(n--){
        int cn, math, en;
        cin >> cn >> math >> en;
        students.emplace_back(order++, cn, cn + math + en);
    }
    //创建一个大小为5的最小堆
    priority_queue<Student, vector<Student>, greater<Student>> ue;
    for(Student student: students){
        if(ue.size() < 5){
            ue.push(student);
        }else{
            if(student > ue.top()){
                ue.pop();
                ue.push(student);
            }
        }
    }
    vector<pair<int, int>> ans(5);
    for(int i = 0; i < 5; ++i){
        ans[i].first = ue.top().id;
        ans[i].second = ue.top().sum;
        ue.pop();
    }
    for(int i = 4; i >= 0; --i){
        cout << ans[i].first << ' ' << ans[i].second;
        if(i != 0){
            cout << endl;
        }
    }

}