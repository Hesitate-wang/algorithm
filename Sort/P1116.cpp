#include<iostream>
#include<vector>
using namespace std;


int merge(vector<int> &vec, int l, int mid, int r){
    vector<int> tmp;
    int ans = 0;
    int i = l;
    int m = mid + 1;
    while(i <= mid && m <= r){
        if(vec[i] <= vec[m]){
            tmp.push_back(vec[i++]);
        }else{
            tmp.push_back(vec[m++]);
            ans += mid - i + 1;
        }
    }
    while(i <= mid){
        tmp.push_back(vec[i++]);
    }
    while(m <= r){
        tmp.push_back(vec[m++]);
    }
    for(i = l; i <= r; ++i){
        vec[i] = tmp[i - l];
    }
    return ans;
}
int mergeSort(vector<int> &vec, int l , int r){
    // 归并排序 可以用于求解逆序对数量 即两两交换返回最终的有序序列
    if(l >= r){
        return 0;
    }
    int mid = (l + r) >> 1;
    int ans1 = mergeSort(vec, l, mid);
    int ans2 = mergeSort(vec, mid+1, r);
    int ans = ans1 + ans2 + merge(vec, l ,mid, r);
    return ans;
}
int main(){
    int N;
    cin >> N;
    vector<int> carriages;
    while(N--){
        int carriage;
        cin >> carriage;
        carriages.push_back(carriage);
    }
    int ans = mergeSort(carriages, 0, carriages.size()-1);
    cout << ans;
}