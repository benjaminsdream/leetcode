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
bool IsHuiWen2(int i){
    if(i<0 || (i%10 == 0 && i!=0) )  return false;
    int revertedI = 0;
    while(i>revertedI){
        revertedI = revertedI*10 + i%10;
        i = i /10;
    }
    return i== revertedI || i == revertedI/10 ? true : false;
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