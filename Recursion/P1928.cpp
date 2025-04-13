#include<iostream>
#include<vector>

//密码压缩递归考点
using namespace std;
int main(){
    vector<char> secret;
    vector<int> number;
    int c;
    int D = 0;
    while((c = getchar()) != '\n'){
        if(c == ']'){
            int num = number.back();
            number.pop_back();
            string tmp;
            while(secret.back() != '['){
                char top = secret.back();
                secret.pop_back();
                tmp.push_back(top);
            }
            secret.pop_back();
            //重新压入D个字符串
            for(int i = 0; i < num; ++i){
                for(int j = tmp.size() - 1; j >= 0; --j){
                    secret.push_back(tmp[j]);
                }
            }
        }else if(c >= '0' && c <= '9'){
            D = D * 10 + c - '0';
        }else{
            secret.push_back(c);
            //压入当前字符后 判断前缀是否是非零的D 如果非零 则需要保存
            if(D != 0){
                number.push_back(D);
                D = 0;  
            }
            
        }
    }
    string target = "";
    for(char x : secret){
        cout << x;
    }
}