#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
动态规划：
状态： dp[i][j]
方程： dp[i][j] = s[i] == s[j]  && (dp[i+1][j-1]  or j-i<3)
边界： 
初始化：对角线
*/
string longestPalindrome(string s) {
    if(s.size() < 2) {
        return s;
    }
    int begin = 0;
    int maxLen = 1;
    const int len = s.size();
    vector< vector<bool> > dp(len, vector<bool>(len));
    for(size_t i = 0; i<s.size(); i++){
        dp[i][i] = true;
    }
    for(int j=1; j<len; j++){
        for(int i = 0; i<j; i++){
            if(s[i] != s[j]){
                dp[i][j] = false;
            } else {
                if((j-i)<3){
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i+1][j-1];
                }
            }
            if(dp[i][j] && (j-i+1) > maxLen){
                maxLen = j-i+1;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxLen);
}
int main(){
    vector<string> ss;
    ss.push_back("bab");
    ss.push_back("aaaaa");
    ss.push_back("a");
    ss.push_back("ac");

    for(auto s: ss){
        string longS = longestPalindrome(s);
        cout<< longS << endl;
    }
}