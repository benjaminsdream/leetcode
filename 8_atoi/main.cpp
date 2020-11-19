#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;
bool IsNumber(char ch){
    if( ch >= '0' && ch <='9')
        return true;
    return false;
}
bool OverFlow(int result, int remain){
    if(result > INT_MAX/10)
        return true;
    if(result == INT_MAX/10 && remain >7)
        return true;
    return false;
}
int myAtoi(string s) {
    if(s=="") return 0;
    int result = 0;
    int i = 0;
    bool positive = true;
    int len = s.size();
    while(s[i] == ' '){i++;}
    if(s[i] == '-') {positive = false;}
    if(s[i] == '+' || s[i] == '-') { i++;}
    while(i<len && isdigit(s[i])){
        int remain = s[i] - '0';
        if(OverFlow(result, remain)){
            return positive ? INT_MAX : INT_MIN;
        }
        result = result*10 + remain;
        // printf("i:%d: remain:%d  result:%d\n", i, remain, result);
        i++;
    }
    // cout << endl;
    return positive ?  result : -result;
}
int main() {
    vector<string> inputs;
    inputs.push_back("123");
    inputs.push_back("-123");
    inputs.push_back("-12340");
    inputs.push_back("-01234");
    inputs.push_back("-123455555555555");
    inputs.push_back("123455555555555");



    for(auto i:inputs){
        int output = myAtoi(i);
        cout << "i: " << i << "  output: "<< output<<endl;
    }
    return 0;
}