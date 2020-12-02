#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector< vector<bool> > dp(m+1, vector<bool>(n+1));
    dp[0][0] = true;

    auto match = [&](int i, int j){
        if(i==0) return false;
        if(p[j-1] == '.') return true;
        return s[i-1] == p[j-1];
    };

    for(int i=0; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(p[j-1] != '*'){
                if(match(i, j)){
                    dp[i][j] = dp[i][j] | dp[i - 1][j - 1];
                }
            } else {
                dp[i][j] =  dp[i][j] | dp[i][j-2];
                if(match(i, j-1)){
                    dp[i][j] =  dp[i][j] | dp[i-1][j];
                }
            }
        }
    }
    return dp[m][n];
}
class Input{
    public:
        string s;
        string p;
        Input(string _s, string _p): s(_s), p(_p){}
};
int main() {
    vector<Input> inputs;
    inputs.push_back( Input("aa", "a"));
    inputs.push_back( Input("aa", "a*"));
    inputs.push_back( Input("ab", ".*"));
    inputs.push_back( Input("aab", "c*a*b"));
    for(auto item: inputs){
        bool result =isMatch(item.s, item.p);
        cout<<"s:" << item.s << " p:"<< item.p <<"  isMatch: "<< result <<endl;
    }
    return 0;
}