#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
bool IsHuiWen(int i){
    string s= to_string(i);
    int len = s.size();
    int half = len/2;
    for(int i=0; i<half; i++){
        int peer = len - 1 - i;
        if(s[i] != s[peer]){
            return false;
        }
    }
    return true;
}
int main() {
    vector<int> inputs;
    inputs.push_back(121);
    inputs.push_back(-123);
    inputs.push_back(10);
    inputs.push_back(1001);


    for(auto i:inputs){
        bool is = IsHuiWen(i);
        cout << "i: " << i << "  回文: "<< is <<endl;
    }
    return 0;
}